package Tb; 
import FIFO::*; 
import ClientServer::*; 
import GetPut::*; 
import StmtFSM::*; 
import Vector::*; 

typedef Server#(Tuple2#(Int#(32), Int#(32)), Int#(32)) AddUnit; 
typedef Server#(Tuple2#(Int#(32), Int#(32)), Int#(32)) MulUnit; 
typedef Server#(Int#(32), Int#(32)) SqrtUnit; 

typedef Server#(Tuple4#(Int#(32), Int#(32), Int#(32), Int#(32)), Int#(32)) FSMCalc; 

module mkCalcUnitRules (FSMCalc); 
    AddUnit adder <- mkAdder(); 
    MulUnit mul <- mkMul(); 
    SqrtUnit sqrt <- mkSqrt(); 

    FIFO#(Tuple4#(Int#(32), Int#(32), Int#(32), Int#(32))) incoming <- mkFIFO(); 

    Reg#(Int#(32)) state <- mkReg(0); 
    Reg#(Int#(32)) rega <- mkRegU; 
    Reg#(Int#(32)) regb <- mkRegU; 
    Reg#(Int#(32)) regc <- mkRegU; 
    Reg#(Int#(32)) regd <- mkRegU; 

    Reg#(Int#(32)) resultab <- mkRegU; 
    Reg#(Int#(32)) resultcd <- mkRegU; 
    Reg#(Int#(32)) resultmul <- mkRegU; 

    rule init (state == 0); 
        let t = incoming.first; incoming.deq; 
        match {.a, .b, .c, .d} = t; 
        rega <= a; 
        regb <= b; 
        regc <= c; 
        regd <= d; 

        state <= state + 1; 
    endrule

    rule r1 (state == 1); 
        let t = tuple2(rega, regb); 
        adder.request.put(t); 
        state <= state + 1; 
    endrule

    rule r2(state == 2); 
        let t <- adder.response.get(); 
        resultab <= t; 
        
        state <= state + 1; 
    endrule
    
    rule r3(state == 3); 
        let t = tuple2(regc, -regd); 
        adder.request.put(t); 
        state <= state + 1; 
    endrule

    rule r4(state == 4); 
        let t <- adder.response.get(); 
        resultcd <= t; 
        state <= state + 1; 
    endrule

    rule r5(state == 5); 
        let t = tuple2(resultab, resultcd); 
        mul.request.put(t); 
        state <= state + 1; 
    endrule

    rule r6(state == 6); 
        let t <- mul.response.get(); 
        resultmul <= t; 
        state <= state + 1; 
    endrule

    rule r7(state == 7); 
        sqrt.request.put(resultmul + 16); 
       // state <= 0; 
    endrule


    interface request = toPut(incoming); 
    interface response = sqrt.response; 
endmodule



module mkCalcUnitFSM(FSMCalc); 
    AddUnit adder <- mkAdder(); 
    MulUnit mul <- mkAdder(); 
    SqrtUnit sqrt <- mkSqrt(); 

    FIFO#(Tuple4#(Int#(32), Int#(32), Int#(32), Int#(32))) incoming <- mkFIFO(); 

    Reg#(Int#(32)) rega <- mkRegU; 
    Reg#(Int#(32)) regb <- mkRegU; 
    Reg#(Int#(32)) regc <- mkRegU; 
    Reg#(Int#(32)) regd <- mkRegU; 
    Reg#(Int#(32)) resultab <- mkRegU; 
    Reg#(Int#(32)) resultcd <- mkRegU; 
    Reg#(Int#(32)) resultmul <- mkRegU; 


    Stmt s = seq
        action 
        let t = incoming.first; incoming.deq; 
        match{.a, .b, .c, .d} = t; 
        rega <= a; 
        regb <= b; 
        regc <= c; 
        regd <= d; 
        endaction 

        action
            $display("1"); 
            let t = tuple2(rega, regb); 
            adder.request.put(t); 
        endaction 

        action 
            $display("2"); 

            let  t<- adder.response.get(); 
            resultab <= t; 
        endaction 

        action 
            $display("3"); 

            let t = tuple2(regc, -regd); 
            adder.request.put(t); 
        endaction 

        action 
            $display("4"); 

            let t <- adder.response.get(); 
            resultcd <= t;
        endaction 

        action 
            $display("5"); 

            let t = tuple2(resultab, resultcd); 
            mul.request.put(t); 
        endaction 

        action 
            $display("6"); 

            let t <- mul.response.get(); 
            resultmul <= t; 
        endaction 
            $display("7"); 

        sqrt.request.put(resultmul + 16); 
            $display("8"); 

    endseq; 

    let fsm <- mkFSM(s); 

    rule rstart(fsm.done()); 
        fsm.start(); 
    endrule

    interface request = toPut(incoming); 
    interface response = sqrt.response; 
endmodule






















module mkAdder(AddUnit); 
    FIFO#(Tuple2#(Int#(32), Int#(32))) in <- mkFIFO(); 
    FIFO#(Int#(32)) out <- mkFIFO; 

    rule r1; 
        let t = in.first; in.deq; 
       match{.a, .b} = t;
        out.enq(a + b); 
    endrule

    interface request = toPut(in); 
    interface response = toGet(out); 

    
endmodule


module mkMul(MulUnit); 
    FIFO#(Tuple2#(Int#(32), Int#(32))) in <- mkFIFO; 
    FIFO#(Int#(32)) out <- mkFIFO; 

    rule r1; 
        let t = in.first; in.deq; 
        match{.a, .b} = t; 
        out.enq(a * b); 
    endrule

    interface request = toPut(in); 
    interface response = toGet(out); 
endmodule

module mkSqrt(SqrtUnit); 
    FIFO#(Int#(32)) in <- mkFIFO; 
    FIFO#(Int#(32)) out <- mkFIFO; 

    rule r1; 
        let t = in.first; in.deq; 
        out.enq(t + 2); 

    endrule
    interface request = toPut(in); 
    interface response = toGet(out); 
endmodule



module mkTB(Empty); 
    FSMCalc dut <- mkCalcUnitFSM(); 
    Tuple4#(Int#(32), Int#(32), Int#(32), Int#(32)) tuple = tuple4(2, 4, 6, 2); //result = 42
    Stmt test = seq
       
        dut.request.put(tuple); 
$display("Hallo"); 
        action 
             $display(" Wetl"); 
            let x =  dut.response.get(); 
            $display("Ergebnis der Berechnung = %d", x); 
        endaction 
    endseq; 
    mkAutoFSM(test); 


endmodule
endpackage