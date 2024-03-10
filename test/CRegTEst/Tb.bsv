package Tb; 
import StmtFSM::*; 
import FIFO::*; 
import ClientServer::*;  
import GetPut::*; 


interface MyCounter; 
    method Action up(Int#(32) v); 
    method Action down(Int#(32) v); 
    method Action reset(); 
    method Int#(32) getCounter(); 
   // interface Server#(Int#(32), Int#(32)) server; 
endinterface






module mkMyCounter(MyCounter); 
    Reg#(Int#(32)) value[4] <- mkCReg(4,0); 
    //FIFO#(Int#(32)) in <- mkFIFO(); 
   // FIFO#(Int#(32)) out <- mkFIFO(); 

  //  Reg#(Int#(32)) test <- mkReg(0); 

/*
    rule r1; 
        let x = in.first; in.deq(); 
       // value[0] <= x; 
       test <= x; 
    endrule

    rule r2; 
        out.enq(test);  
      //  out.enq(value[4]); 
    endrule
*/



    method Action reset(); 
        value[0] <= 0;                                      
    endmethod

    method Action up(Int#(32) v); 
        value[1] <= value[1] + v; 
    endmethod                                              
                                                           
    method Action down(Int#(32) v); 
        value[2] <= value[2] - v;  
    endmethod

    method Int#(32) getCounter(); 
        return value[3]; 
    endmethod

/*
    interface Server server; 
        interface Put request = toPut(in); 
        interface Get response = toGet(out); 
    endinterface*/

endmodule


module mkRandom(Server#(Int#(32), Int#(32))); 
    FIFO#(Int#(32)) in <- mkFIFO(); 
    FIFO#(Int#(32)) out <- mkFIFO();  
    MyCounter counter <- mkMyCounter(); 
    Reg#(Int#(32)) t <- mkReg(0); 


    rule r1; 
        let x = in.first; in.deq(); 
        x <- counter.up(5); 
       // t <= x; 
    endrule

    rule r2; 
       t <=  counter.getCounter(); 
        out.enq(t); 
    endrule

    interface Put request = toPut(in); 
    interface Get response = toGet(out); 
endmodule

/*
module mkTb1(Empty); 
 MyCounter uut <- mkMyCounter(); 
Reg#(Int#(32)) a <- mkReg(5); 
//Reg#(Int#(32)) o <- mkReg(0); 
Stmt test =                                                                 
        seq
           
            uut.server.request.put(a); 

action 
    
          let o <-    uut.server.response.get(); 
            $display("Ergebnis : %d",o);
endaction 

             //uut.up(5); 
             //uut.down(1); 
           
            



        endseq;

mkAutoFSM(test); 
endmodule
*/
module mkTb2(Empty); 
   // MyCounter uut <- mkMyCounter(); 
    Server#(Int#(32), Int#(32)) uut <- mkRandom(); 
    Reg#(Int#(32)) a <- mkReg(5); 

    rule r1; 
        uut.request.put(a); 
    endrule
    rule r2; 
        let o <- uut.response.get(); 
        $display("Ergebnis: %d", o); 
    endrule

endmodule


endpackage


