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
        if(pack(cycle)[2:0] < 5) g.request.put(cycle); 
    endrule

    rule drain;     
        let x <- g.response.get(); 
        $display ("%0d: draining %0d", cycle, x); 
        if(cycle > 20) $finish(0); 
    endrule
endmodule: mkTb


(* synthesize *)
module mkGadget (Server#(int, int));
    int bubble_value = 42; 

    FIFO#(int) infifo <- mkFIFO; 
    FIFO#(int) outfifo <- mkFIFO; 

    Reg#(int) bubble_cycles <- mkReg(0); 
    Reg#(int) max_bubble_cycles <- mkReg(0); 

    (* descending_urgency="enqueue_item, enqueue_bubble" *)
    rule enqueue_item; 
        outfifo.enq(infifo.first); 
        infifo.deq; 
        bubble_cycles <= 0; 
    endrule

    rule inc_bubble_cyclus; 
        bubble_cycles <= bubble_cycles +1; 
    endrule

    rule enqueue_bubble;
        outfifo.enq(bubble_value); 
        max_bubble_cycles <= max(max_bubble_cycles, bubble_cycles); 
    endrule

    interface request = fifoToPut (infifo); 
    interface response = fifoToGet (outfifo); 

endmodule: mkGadget

endpackage: Tb