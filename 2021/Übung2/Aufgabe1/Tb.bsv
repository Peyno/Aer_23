package Tb; 

interface CalcUnit; 
    method Action put(Int#(32) x); 
    method ActionValue#(Int#(32)) result(); 
endinterface

interface CalcUnitChangeable; 
    interface CalcUnit calc; 
    method Action setParameter(Int#(32) param); 
endinterface

module mkAddA(CalcUnitChangeable); 
    Reg#(Int#(32)) a <- mkRegU; 
    Wire#(Int#(32)) in <- mkWire; 

    method Action setParameter(Int#(32) param); 
        a <= param; 
    endmethod

    interface CalcUnit calc; 
        method Action put(Int#(32) x); 
            in <= x; 
        endmethod

        method ActionValue#(Int#(32)) result(); 
            noAction; 
            return in + a; 
        endmethod
    endinterface 
endmodule

module mkMul(CalcUnitChangeable); 
    Reg#(Int#(32)) b <- mkRegU; 
    Wire#(Int#(32)) in <- mkWire; 

    method Action setParameter(Int#(32) param); 
        b <= param; 
    endmethod

    interface CalcUnit calc; 
        method Action put(Int#(32) x); 
            in <= x; 
        endmethod

        method ActionValue#(Int#(32)) result(); 
            noAction; 
            return in * b; 
        endmethod
    endinterface 
endmodule

module mkDiv4(CalcUnit); 
    Wire#(Int#(32)) <- mkWire; 

    method Action put(Int#(32) x ); 
        in <= x; 
    endmethod

    method ActionValue#(Int#(32)) result(); 
        noAction; 
        return in / 4; 
    endmethod 
endmodule

module mkAdd128(CalcUnit); 
    Wire#(Int#(32)) in <- mkWire; 
    
    method Action put(Int#(32) x ); 
        in <= x; 
    endmethod

    method ActionValue#(Int#(32)) result(); 
        noAction; 
        return in + 128; 
    endmethod
endmodule




















interface Pipeline; 
    interface CalcUnit calc; 
    method Action setParam(UInt#(2) addr, Int#(32) val); 
endinterface   

module mkPipeline(Pipeline); 
    CalcUnitChangeable stage1 <- mkAddA; 
    CalcUnitChangeable stage2 <- mkMul; 
    CalcUnitChangeable stage3 <- mkMul; 
    CalcUnit stage4 <- mkDiv4; 
    CalcUnit stage5 <- mkAdd128; 

    Vector#(3, CalcUnitChangeable) changeables; 
    changeables[0] = stage1; 
    changeables[1] = stage2; 
    changeables[2] = stage3;

    Vector#(5, CalcUnit) stages; 
    stages[0] = stage1.calc; 
    stages[1] = stage2.calc; 
    stages[2] = stage3.calc; 
    stages[3] = stage4; 
    stages[4] = stage5; 

    Vector#(6, FIFO#(Int#Int#(32))) fifos <- replicateM(mkSizedFIFO(1)); 

    for(Integer i = 0; i < 5; i = i + 1)begin
        rule push; 
            stages[i].put(fifos[i].first); 
            fifos[i].deq; 
        endrule
    end

    for(Integer i = 1; i < 6; i = i + 1)begin 
        rule pull; 
            let t <- stages[i-1].result(); 
            fifos[i].enq(t); 
        endrule
    end

    method Action  setParam(UInt#(2) addr, Int#(32) val); 
        changeables[addr].setParameter(val); 
    endmethod

    interface CalcUnit clac; 
        method Action put(Int#(32) x); 
            fifos[0].enq(x); 
        endmethod

        method ActionValue#(Int#(32)) result(); 
            let res = fifos[5].first(); 
            fifos[5].deq; 
            return res; 
        endmethod
    endinterface
endmodule
























module mkTB(Empty); 
    Pipeline dut <- mkPipeline(); 
    Reg#(Int#(32)) idx_put <- mkRegU; 
    Reg#(Int#(32)) idx_get <- mkRegU; 

    Stmt s = seq
        dut.setParam(0, 42); 
        dut.setParam(1,2); 
        dut.setParam(2,13); 
        $display("Initialized parameters, starting test..."); 
        par
            seq
                for(idx_put <= 0; idx_put < 10; idx_put <= idx_put + 1)action 
                    dut.calc.put(unpack(pack(idx_put))); 
                endaction 
                dut.setParam(0,7); 
                dut.setParam(1,3); 
                dut.setParam(2,17); 
                for(idx_put <= 10; idx_put < 20; idx_put <= idx_put + 1)action 
                    dut.calc.put(unpack(pack(idx_put))); 
                endaction 
            endseq

            seq
                for(idx_get <= 0; idx_get < 20; idx_get <= idx_get + 1)action 
                    $display("Checking result for %d", idx_get); 
                    let t <- dut.calc.result(); 
                    if(t == testvec[idx_get])
                        correct_tests <= correct_tests + 1; 
                    else $display("Expected %d, got %d.", testvec[idx_get], t); 
                endaction 
            endseq
        endpar
        $display("%d of 20 tests passed.", correct_tests); 
        if(correct_tests == 20) $display("SUCCESS!"); 
        else $display("FAILURE!"); 
        $finish(); 
    endseq; 

    mkAutoFSM(s); 


endmodule




endpackage
