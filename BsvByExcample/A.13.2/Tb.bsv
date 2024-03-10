package Tb; 

(* synthesize *) 
module mkTb(Empty); 
    Integer idle = 0; 
    Integer step1 = 1; 
    Integer step2 = 2; 
    Integer stop = 3; 

    function Bit#(4) toState (Integer st); 
        return 1 << st; 
    endfunction 

    Reg#(Bit#(4)) state <- mkReg( toState(idle)); 

    Reg#(int) counter <- mkReg(0); 
    Reg#(Bool) restart <- mkReg(False); 

    rule runCounter; 
        if(counter == 200) begin 
            $display("Done"); 
            $finish; 
        end
        counter <= counter +1; 
    endrule

    (* mutually_exclusive = "stateIdle, stateStep1, stateStep2, stateStop" *)
    rule stateIdle(state[idle] == 1); 
        $display("Counter = %03d, State: IDLE", counter); 

        if(counter % 4 == 0)
            state <= toState(step1); 
    endrule

    rule stateStep1(state[step1] == 1); 
        $display("Counter = %03d, State: STEP1", counter);

        if(restart)
            state <= toState(idle); 
        else if(counter % 4 == 0)
            state <= toState(step2); 
    endrule

    rule stateStep2 (state[step2] == 1); 
        $display("Counter = %03d, State: STEP2", counter); 
        state <= toState(stop); 
    endrule

    rule stateStop(state[stop] == 1); 
        $display("Counter = %03d, State: STEP2", counter); 
        state <= toState(stop); 
    endrule


endmodule

endpackage