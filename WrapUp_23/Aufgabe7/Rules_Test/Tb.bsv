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
        AddUnit adder <- mkAdder;
        MulUnit mul <- mkMul;
        SqrtUnit sqrt <- mkSqrt;

        Reg#(Int #(32)) reg_a <- mkReg(0);
        Reg#(Int #(32)) reg_b <- mkReg(0);o
        Reg#(Int #(32)) reg_c <- mkReg(0);
        Reg#(Int #(32)) reg_d <- mkReg(0);
        Reg#(Int #(32)) reg_e <- mkReg(0);

        Reg#(Bool) flag_a <- mkReg(False);
        Reg#(Bool) flag_b <- mkReg(False);
        Reg#(Bool) flag_c <- mkReg(False);
        Reg#(Bool) flag_last <- mkReg(False);

        Reg#(Int#(32)) resultadder <- mkRegU; 
        Reg#(Bool) flag_adder <- mkReg(False); 
        
        Reg#(Int#(32)) mulresult <- mkRegU; 
        Reg#(Bool) flag_mul <- mkReg(False); 
        //Reg#(Bit #(1)) starter <- mkReg(False);
        //Reg#(Int #(32)) reg_res <- mkReg(0);

        Reg#(Int#(32)) resultsub <- mkRegU; 
        Reg#(Bool) flag_start <- mkReg(False); 

        FIFO#(Tuple4 #(Int #(32), Int #(32), Int #(32), Int #(32))) incoming <- mkFIFO;


    //Brechnung in Takte aufteilen

        rule start; //(!starter)
            let t = incoming.first; incoming.deq;

//mehrere Werte direkt extrahieren
            match{.a, .b, .c, .d} = t;
            reg_a <= a;
            reg_b <= b;
            reg_c <= c;
            reg_d <= d;
            //starter <= !starter;

            flag_start <= True; 
        endrule

        rule add_rule(flag_start);
                  //  $display("%d,%d,%d,%d", reg_a, reg_b, reg_c, reg_d); 

            adder.request.put(tuple2(reg_a, reg_b));
            flag_a <= True;
            //adder.request.put(tuple2(reg_a, reg_b));
        endrule

        rule sub_rule ;
            resultsub <= reg_c - reg_d;
            flag_b <= True;
            //reg_res <= reg_c - reg_d;
        endrule

        rule r(flag_a && flag_b); 
            let t <- adder.response.get(); 
            resultadder <= t; 
            flag_adder <= True; 
        endrule

        rule mul_rule (flag_adder);
           mul.request.put(tuple2(resultadder, resultsub));
           flag_c <= True;
           //mul.request.put(tuple2(t, reg_res));
        endrule

        rule last_step (flag_c);
            let t <- mul.response.get;
            mulresult <= t; 
            flag_last <= True;
        endrule

     

        rule l (flag_last); 
            sqrt.request.put(mulresult+16); 
        endrule
        
        interface request = toPut(incoming);
        interface response = sqrt.response;
    endmodule













////////////////////////////////






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