package Tb; 
import FIFO::*; 
import ClientServer::*; 
import GetPut::*; 
import StmtFSM::*; 
import Vector::*; 

typedef Server#(Tuple2#(Int#(32), Int#(32)), Int#(32)) AddUnit; 
typedef Server#(Tuple2#(Int#(32), Int#(32)), Int#(32)) MulUnit; 
typedef Server#(Int#(32), Int#(32)) SqrtUnit;

// Tuple4: (a, b, c, d)
typedef Server#(Tuple4#(Int#(32), Int#(32), Int#(32), Int#(32)), Int#(32)) FSMCalc; 

module mkCalcUnitRules(FSMCalc); 
    AddUnit adder <- mkAdder(); 
    MulUnit mul <- mkMul(); 
    SqrtUnit sqrt <- mkSqrt(); 

    FIFO#(Tuple4#(Int#(32), Int#(32), Int#(32), Int#(32))) incoming <- mkFIFO(); 

  
    //parameter (0=a, 1=b, 2=c, 3=d)
    Vector#(4, Reg#(Maybe#(Int#(32)))) params <- replicateM(mkReg(tagged Invalid)); 
    Vector#(3, Reg#(Maybe#(Int#(32)))) regs <- replicateM(mkReg(tagged Invalid)); 
    
    Reg#(Bool) ab_send <- mkReg(False);  
    Reg#(Maybe#(Int#(32))) ab_result <- mkReg(tagged Invalid); 

    Reg#(Bool) cd_send <- mkReg(False); 
    Reg#(Maybe#(Int#(32))) cd_result <- mkReg(tagged Invalid); 

    Reg#(Bool) mul_send <- mkReg(False); 
    Reg#(Maybe#(Int#(32))) mul_result <- mkReg(tagged Invalid); 

    Reg#(Bool) sqrt_send <- mkReg(False); 

    Reg#(Bool) initdone <- mkReg(False); 

    rule init; 
        let t = incoming.first; incoming.deq; 
        match{.a, .b, .c, .d} = t;
        params[0] <=  tagged Valid(a); 
        params[1] <=  tagged Valid(b); 
        params[2] <=  tagged Valid(c); 
        params[3] <=  tagged Valid(d); 
        initdone <= True; 
    endrule

    rule absend(params[0] matches tagged Valid .a &&& params[1] matches tagged Valid .b &&& !ab_send); 
        let tu = tuple2(a,b); 
        adder.request.put(tu); 
        ab_send <= True; 
    endrule

    rule abre(ab_send); 
        let r <-  adder.response.get(); 
        ab_result <= tagged Valid (r); 
        ab_send <= False; 
    endrule


    rule cdsend(ab_result matches tagged Valid .ab &&& !cd_send); 
        if(params[2] matches tagged Valid .c &&& params[3] matches tagged Valid .d)begin
                let tu = tuple2(c, -d); 
                adder.request.put(tu); 
                cd_send <= True; 
            end
    endrule

    rule cdre(cd_send); 
            let r <- adder.response.get(); 
            cd_result <= tagged Valid(r); 
            cd_send <= False;
    endrule

    rule mulsend(ab_result matches tagged Valid .ab &&& cd_result matches tagged Valid .cd &&& !mul_send); 
            let tu = tuple2(ab, cd); 
            mul.request.put(tu); 
            mul_send <= True; 
    endrule

    rule mulre(mul_send); 
            let r <- mul.response.get(); 
            mul_result <= tagged Valid (r); 
            mul_send <= False; 
    endrule

    rule sqrtse(mul_result matches tagged Valid .m &&& !sqrt_send); 
            sqrt.request.put(m + 16); 
            sqrt_send <= False;  
    endrule





    interface request = toPut(incoming); 
    interface response = sqrt.response; 
endmodule





module mkCalcUnitFSM(FSMCalc); 
    AddUnit adder <- mkAdder(); 
    MulUnit mul <- mkMul(); 
    SqrtUnit sqrt <- mkSqrt(); 

    Vector#(4, Reg#(Int#(32))) params <- replicateM(mkRegU); 
    Reg#(Int#(32)) abresult <- mkRegU; 
    Reg#(Int#(32)) cdresult <- mkRegU; 
    Reg#(Int#(32)) mulresult <- mkRegU; 

    FIFO#(Tuple4#(Int#(32), Int#(32), Int#(32), Int#(32))) incoming <- mkFIFO(); 

    Stmt s = seq
        action
            let in =  incoming.first; incoming.deq;
            match{.a, .b, .c, .d} = in; 
            params[0] <= a; 
            params[1] <= b; 
            params[2] <= c; 
            params[3] <= d;  
        endaction 

        action 
            let t = tuple2(params[0],params[1]); 
            adder.request.put(t); 
        endaction 
        action
            let r <- adder.response.get(); 
            abresult <= r; 
        endaction 
        action
            let t = tuple2(params[2], -params[3]); 
            adder.request.put(t); 
        endaction 
        action 
        let r <- adder.response.get(); 
         cdresult <= r; 
        endaction 
        action 
            let t = tuple2(abresult, cdresult); 
            mul.request.put(t); 
        endaction 
        action 
            let r <- mul.response.get(); 
            mulresult <= r; 
        endaction 
       
        sqrt.request.put(mulresult+16); 


    endseq; 

   // mkAutoFSM(s); 
    
    let fsm <- mkFSM(s); 

    rule rstart(fsm.done()); 
        fsm.start(); 
    endrule


    interface request = toPut(incoming); 
    interface response = sqrt.response; 
endmodule






























///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



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