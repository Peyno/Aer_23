package Tb; 

import FIFO::*; 

(* synthesize *)
module mkTb (Empty); 

    Reg#(int) cycle <- mkReg(0); 

    FIFO#(int) f0 <- mkSizedFIFO (3); 
    FIFO#(int) f1 <- mkSizedFIFO (3); 

    rule count_cycles; 
        cycle <= cycle + 1; 
        if(cycle > 15) $finish(0); 
    endrule

    rule rA; 
        if(pack (cycle)[0] == 0)begin
            f0.enq (cycle); 
            $display("%0d: Enqeuing %d into fifo f0", cycle, cycle); 
        end
        else begin
            f1.enq(cycle); 
            $display("%0d: Enqueuing %d into fifo f1", cycle, cycle); 
        end
    endrule

    rule rB; 
        f0.deq(); 
    endrule

endmodule: mkTb
endpackage: Tb