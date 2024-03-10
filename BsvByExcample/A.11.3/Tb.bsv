package Tb; 

(* synthesize *)
module mkTb (Empty); 

    function int square(int a); 
        return a * a; 
    endfunction

    function int increment (int a); 
        int maxInt = unpack({1'b1, 0}); 
        if(a != maxInt)
            return a + 1; 
        else 
            return a; 
    endfunction

    Reg#(int) step <- mkReg(0); 

    rule intit (step == 0); 
        $display("=== step 0 ==="); 
        $display("square    10 = ", square(10)); 
        $display("increment 20 = ", increment(20)); 

        $display("2*10+1       =", increment(square(10))); 

        step <= step +1; 
    endrule

    rule step1(step == 1); 
        $display("=== step 1 ==="); 
        $display("All done"); 
        $finish(0); 
    endrule

endmodule: mkTb
endpackage: Tb