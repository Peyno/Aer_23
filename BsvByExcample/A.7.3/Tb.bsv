package Tb; 

(* synthesize *)
module mkTb (Empty); 
    Counter c1 <- mkCounter_v1; 
    Counter c2 <- mkCounter_v2; 

    Reg#(int) state <- mkReg(0); 

    rule step_state; 
        if(state > 9) $finish(0); 
        state <= state + 1; 
    endrule

    rule show; 
        $display("In state %0d, counter values are %0d, %0d", state, c1.read(), c2.read()); 
    endrule

    rule incr1 (state < 7); 
        c1.increment(5); 
    endrule

    rule decr1 (state > 3); 
        c1.decrement(2); 
    endrule

    rule incr2 (state < 7); 
        c2.increment(5); 
    endrule

    rule decr2 (state > 3); 
        c2.decrement(2); 
    endrule

endmodule: mkTb

interface Counter; 
    method int read(); 
    method Action increment(int di); 
    method Action decrement(int dd); 
endinterface


(* synthesize *)
module  mkCounter_v1(Counter); 
    Reg#(int) value1 <- mkReg(0); 

    method int read(); 
        return value1; 
    endmethod

    method Action increment (int di); 
        value1 <= value1 + di; 
    endmethod

    method Action decrement (int dd); 
        value1 <= value1 - dd; 
    endmethod

endmodule: mkCounter_v1


(* synthesize *)
module mkCounter_v2 (Counter); 
    Reg#(int) value2 <- mkReg(0); 

    Wire#(int) w_incr <- mkWire(); 
    Wire#(int) w_decr <- mkWire(); 

    (* descending_urgency = "r_incr_and_decr, r_incr_only, r_decr_only"  *)

    rule r_incr_and_decr; 
        value2 <= value2 + w_incr - w_decr; 
    endrule

    rule r_incr_only; 
        value2 <= value2 + w_incr; 
    endrule

    rule r_decr_only; 
        value2 <= value2 - w_decr; 
    endrule

    method int read(); 
        return value2; 
    endmethod

    method Action increment (int di); 
        w_incr <= di; 
    endmethod

    method Action decrement (int dd); 
        w_decr <= dd; 
    endmethod

endmodule: mkCounter_v2
endpackage: Tb