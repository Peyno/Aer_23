package Tb; 
import FIFO::*; 
import StmtFSM::*; 


interface CalcUnit; 
    method Action put(Int#(32) x); 
    method ActionValue#(Int#(32)) result(); 
endinterface

interface Pipeline; 
    interface CalcUnit calc; 
    method Action setParam(Int#(32) value); 
endinterface

// x -> FIFO1 -> x+5 -> FIFO2 -> x*x -> FIFO3
module mkPipeline(Pipeline); 
    CalcUnit stage0 <- mkAdd; 
    CalcUnit stage1 <- mkMult; 
    Reg#(Int#(32)) x <- mkReg(0); 

    FIFO#(Int#(32)) fifo1 <- mkFIFO; 
    FIFO#(Int#(32)) fifo2 <- mkFIFO; 
    FIFO#(Int#(32)) fifo3 <- mkFIFO; 

    Reg#(Bool) stage0put <- mkReg(False); 
    Reg#(Bool) stage1put <- mkReg(True); 

    Reg#(Bit#(8)) stage <- mkReg(0); 

    rule r1(stage == 0); 
        $display("Rule r1"); 
       let t =  fifo1.first; fifo1.deq; 
        stage0.put(t); 
        stage <= stage + 1; 
    endrule

    rule r2(stage == 1); 
            $display("Rule r2"); 

        let t <- stage0.result(); 
       fifo2.enq( t ); 
       stage <= stage +1 ; 

    endrule

    rule r3(stage == 2);
            $display("Rule r3"); 

        let t = fifo2.first; fifo2.deq(); 
        stage1.put(t); 
        stage <= stage + 1; 
    endrule

    rule r4 (stage == 3); 
            $display("Rule r4"); 

        let t <- stage1.result();
        fifo3.enq( t); 
        stage <= 0; 
    endrule

    method Action  setParam(Int#(32) value); 
        x <= value; 
    endmethod

    interface CalcUnit calc; 
        method Action put(Int#(32) x); 
        $display("Wert wurde in fifo1 enq"); 
            fifo1.enq(x); 
        endmethod

        method ActionValue#(Int#(32)) result(); 
            $display("Wert wurde aus fifo3 deq"); 
            fifo3.deq(); 
            return fifo3.first; 
        endmethod
    endinterface






endmodule


module mkAdd(CalcUnit); 
    Reg#(Int#(32)) wert <- mkReg(0); 

    

    method Action put(Int#(32) x); 
        wert <= x; 
    endmethod

    method ActionValue#(Int#(32)) result(); 
        return  wert + 5; 
    endmethod

endmodule

module mkMult(CalcUnit); 
    Reg#(Int#(32)) wert <- mkReg(0); 

    method Action put(Int#(32) x); 
        wert <= x; 
    endmethod

    method ActionValue#(Int#(32)) result(); 
        return wert * wert; 
    endmethod
endmodule






module mkTB1(Empty); 
    CalcUnit dut <- mkMult(); 

    Stmt s = seq
        dut.put(2); 

        $display("Ergebnis der Pipeline: %d", dut.result); 
    endseq; 

    mkAutoFSM(s); 


endmodule


module mkTB(Empty); 
    Pipeline dut <- mkPipeline(); 

    Stmt s = seq
        dut.setParam(2); 
        dut.calc.put(2); 

        $display("Ergebnis der Pipeline: %d", dut.calc.result); 
    endseq; 

    mkAutoFSM(s); 


endmodule

endpackage