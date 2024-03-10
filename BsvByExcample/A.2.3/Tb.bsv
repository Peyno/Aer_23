package Tb; 

(* synthesize *)
module mkTb(Empty); 

    function Action passString(String s); 
        return action 
            $display("passString => ", s); 
        endaction; 
    endfunction 

    Reg#(int) step <- mkReg(0); 

    ///////////////////////////////////////////
    rule init( step == 0); 
        $display("=== step 0 ==="); 

        String s1 = "This is a test"; 
        $display("first string = ", s1); 

        //we can use + to concatenate
        String s2 = s1 + " of concatenation"; 
        $display("Second string = ", s2); 

        passString("String passed t0 a function"); 

        // the valid escape chars are listed in the reference manual
        step <= step + 1; 
    endrule

    ///////////////////////////////////////////////
    rule step1 (step == 1); 
        $display("All done");
        $finish(0); 
    endrule

endmodule: mkTb

endpackage: Tb