package Tb; 

typedef enum {IDLE, STEP1, STEP2, STOP} State deriving(Bits, Eq); 

(* synthesize *)
module mkTb (Empty); 

    Reg#(State) state <- mkReg(IDLE); 
    Reg#(int) counter <- mkReg(0); 
    Reg#(Bool) restart <- mkReg(False); 

    rule runCounter; 
        if(counter == 200) begin
            $display("Done"); 
            $finish; 
        end
        counter <= counter + 1; 
    endrule

    rule stateIdle (state == IDLE); 
        $display("Counter = %03d, State: IDLE", counter); 

        if(counter % 4 == 0)
            state <= STEP1; 
    endrule

    rule stateStep1 (state == STEP1); 
        $display("Counter = %03d, State: STEP1", counter); 
        if(restart)
            state <= IDLE; 
        else if (counter % 8 == 0)
            state <= STEP2; 
    endrule

    rule stateStep2(state == STEP2); 
        $display("Counter = %03d, State: STEP2", counter); 
        state <= STOP; 
    endrule

    rule stateSTOP (state == STOP); 
        $display("Counter = %03d, State: STOP", counter); 
        state <= IDLE; 
    endrule

endmodule

endpackage 