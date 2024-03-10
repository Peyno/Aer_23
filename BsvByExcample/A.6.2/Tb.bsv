package Tb;     

    import FIFO::*; 

    (* synthesize *)
    module mkTb(Empty); 

        FIFO#(int) f <- mkFIFO; 

        Reg#(int) state <- mkReg(0); 

        rule step_state; 
            if(state > 9) $finish(0); 
            state <= state + 1; 
        endrule


        (* descending_urgency = "enq1, enq2" *)
        rule enq1 (state < 7); 
            f.enq(state); 
            $display("fifo enq1: %d2", state); 
        endrule

        rule enq2 (state > 4); 
            f.enq(state +1); 
            $display("fifo enq2: %d", state+1); 
        endrule

        rule deq; 
            f.deq(); 
            $display("fifo deq: %d", f.first()); 
        endrule

    endmodule: mkTb

endpackage : Tb