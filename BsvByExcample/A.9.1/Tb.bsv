package Tb; 

typedef enum {IDLE, DOX, DOY, FINISH} Tenum1 deriving (Bits, Eq); 

typedef enum {S0=43, S1, S2=20, S3=254} Tenum2 deriving(Bits, Eq); 

(*synthesize *)
module mkTb(Empty); 
    Reg#(int) step <- mkReg(0); 

    Reg#(Tenum1) r1 <- mkReg(IDLE); 
    Reg#(Tenum2) r2 <- mkReg(S3); 

    rule inint(step == 0); 
        $display("=== step 0 ==="); 
        $display("enum1 IDLE =>", IDLE); 
        $display("enum1 DOX =>", DOX); 
        $display("enum1 DOY =>", DOY); 
        $display("enum1 FINISH =>", FINISH); 

        $display("enum2 S0 =>", S0); 
        $display("enum2 S1 =>", S1); 
        $display("enum3 S2 =>", S2); 
        $display("enum4 S3 =>", S3); 

        step <= step + 1; 
    endrule

    rule step1 (step == 1); 
        $display("=== step 1 ==="); 
        Tenum1 foo = IDLE; 

        step <= step + 1; 
    endrule

    rule step2(step == 2);
        $display("All done"); 
        $finish(0); 
    endrule

    rule watcher(step != 0); 
    endrule

endmodule: mkTb

endpackage: Tb