package TestTb;
import StmtFSM::*; 
import FIFO::*; 
import ClientServer::*; 
import GetPut::*; 

typedef Server#(Tuple2#(Int#(32), Int#(32)), Int#(32)) AdderUnit; 
typedef Server#(Tuple2#(Int#(32), Int#(32)), Int#(32)) MulUnit;
typedef Server#(Int#(32), Int#(32)) SqrtUnit;

module mkAdder(AdderUnit); 
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
        out.enq(t + 1); 

    endrule
    interface request = toPut(in); 
    interface response = toGet(out); 
endmodule




module mkTb(Empty); 
    SqrtUnit mul <- mkSqrt(); 
    
    Tuple2#(Int#(32), Int#(32)) tuple = tuple2(5,2); 
    Reg#(Int#(32)) a <- mkReg(5); 
    Stmt test = seq
        mul.request.put(a); 
        action 
        let x = mul.response.get(); 
        $display("Ergebnis : %d", x); 
        endaction 
    endseq; 
    mkAutoFSM(test); 


endmodule


endpackage