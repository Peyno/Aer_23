package Tb; 

(* synthesize *)
module mkTb(Empty); 

    Reg#(int) step <- mkReg(0); 

    Reg#(int) a <- mkReg(0); 

    rule init (step == 0); 
        $display("=== step 0 ==="); 

        int val = case(a)
            0: return 25;
            1: return 23; 
            2: return 17; 
            default: return 64; 
        endcase;

      $display("val = %0d", val);

        step <= step + 1; 
    endrule

    Bool initReg = True; 

    Reg#(int) rr <- case (initReg)
        False: mkRegU; 
        True: mkReg(0); 
    endcase; 

    rule step1(step == 1); 
        $display("=== step 1 ==="); 
        $display("reg rr is initalized to  %0d", rr); 
        step <= step + 1; 
    endrule

    rule step2 (step == 2); 
        $display("=== step 2 ==="); 
        $display("All done"); 
        $finish(0);  
    endrule

endmodule: mkTb

endpackage: Tb