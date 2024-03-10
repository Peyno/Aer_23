package Tb; 
import FIFO::*; 
import GetPut::*; 
import ClientServer::*; 
import StmtFSM::*; 


typedef Server#(Tuple2#(Int#(32), Int#(32)), Int#(32)) AddUnit; 
typedef Server#(Tuple2#(Int#(32), Int#(32)), Int#(32)) MulUnit; 
typedef Server#(Int#(32), Int#(32)) SqrtUnit; 

typedef Server#(Tuple4#(Int#(32), Int#(32), Int#(32), Int#(32)), Int#(32)) FSMCalc; 

module mkCalcUnitRules(FSMCalc); 
    AddUnit adder <- mkAdder(); 
    MulUnit mul <- mkMul(); 
    SqrtUnit sqrt <- mkSqrt(); 

    FIFO#(Tuple4#(Int#(32), Int#(32), Int#(32), Int#(32))) incoming <- mkFIFO(); 

    Reg#(Int#(32)) state <- mkReg(0); 
    Reg#(Int#(32)) rega <- mkRegU; 
    Reg#(Int#(32)) regb <- mkRegU; 
    Reg#(Int#(32)) regc <- mkRegU; 
    Reg#(Int#(32)) regd <- mkRegU; 
    Reg#(Int#(32)) resultadd1 <- mkRegU; 
    Reg#(Int#(32)) resultadd2 <- mkRegU; 
    Reg#(Int#(32)) resultmul <- mkRegU; 

    rule pull (state == 0); 
        let x = incoming.first; incoming.deq; 
        match{.a, .b, .c, .d} = x; 
        rega <= a;  
        regb <= b; 
        regc <= c; 
        regd <= d; 

        state <= state + 1; 
    endrule

    rule requestadd1 (state == 1); 
        let t = tuple2(rega,regb); 
        adder.request.put(t); 
        state <= state + 1; 
    endrule

    rule responseadd1(state == 2); 
            let x <- adder.response.get(); 
        resultadd1 <= x; 
         
        state <= state + 1; 
    endrule

    rule requestadd2(state == 3); 
        let t = tuple2(regc, -regd); 
        adder.request.put(t); 
        state <= state + 1; 
    endrule

    rule responseadd2(state == 4); 
        let x <- adder.response.get(); 
        resultadd2 <= x; 
        state <= state + 1; 
    endrule

    rule requestmul(state ==5); 
        let t = tuple2(resultadd1, resultadd2); 
        mul.request.put(t);
        state <= state + 1; 
    endrule

    rule responsemul(state == 6); 
        let x <-  mul.response.get();
        resultmul <= x;  
        state <= state + 1; 
    endrule

    rule sqrtrequest(state == 7); 
        sqrt.request.put(resultmul +16); 
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
    FSMCalc dut <- mkCalcUnitRules(); 
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