package Tb; 
    import GetPut::*; 

    (* synthesize *)
    module mkTb (Empty); 
        Reg#(int) cycle <- mkReg(0); 
        Reg#(int) x <- mkReg(0); 

        Put#(int) dut <- mkDut(); 

        rule count_cycles; 
            cycle <= cycle + 1; 
            if(cycle > 15) $finish(0); 
        endrule

        // (* descending_urgency = "r2, r1" *)
        (* descending_urgency = "r1, r2" *)

        (* fire_when_enabled, no_implicit_conditions *)
        rule r1 (pack (cycle)[2:0] != 7); 
            dut.put(x); 
            x <= x + 1; 
        endrule

        rule r2; 
            x <= x + 2; 
        endrule

    endmodule: mkTb

    (* synthesize *)
    module mkDut(Put#(int)); 
        Reg#(int) y <- mkReg(0); 

        method Action put(int z); // if(y > 0); 
            y <= z; 
        endmethod
    endmodule

    
endpackage : Tb
    