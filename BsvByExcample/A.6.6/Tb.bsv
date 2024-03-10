package Tb; 

import FIFO::*; 
import GetPut::*; 
import ClientServer::*; 

(* synthesize *)
module mkTb (Empty); 
    Reg#(int) cycle <- mkReg(0); 

    Server#(int, int) g <- mkGadget; 

    rule source; 
        cycle <= cycle + 1; 
        if(pack (cycle)[2:0] < 5) g.request.put (cycle); 
    endrule

    rule drain; 
        let x <- g.response.get(); 
        $display("%0d: draining %d", cycle, x); 
        if(cycle > 20) $finish(0); 
    endrule
endmodule

(* synthesize *)
module mkGadget(Server#(int, int));     
    FIFO#(int) infifo <- mkFIFO; 
    FIFO#(int) outfifo <- mkFIFO; 

    Reg#(int) idle_cycles <- mkReg(0); 

    (* preempts="enqueue_item, count_idle_cycles" *)
    rule enqueue_item; 
        outfifo.enq(infifo.first); 
        infifo.deq; 
    endrule

    rule count_idle_cycles; 
        idle_cycles <= idle_cycles + 1; 
        $display("Idle cycle %0d", idle_cycles +1); 
    endrule

    interface request = fifoToPut(infifo); 
    interface response = fifoToGet(outfifo); 

endmodule: mkGadget
endpackage: Tb