package Tb; 
import FIFO::*; 

typedef struct {
    int a; 
    Bool b;
} TEx1 deriving(Bits, Eq); 

typedef struct {
    Reg#(int) ra; 
    Reg#(Bool) rb; 
} TEx2; 

(* synthesize *)
module mkTb(Empty); 
    
   Reg#(int) step <- mkReg(0);

   Reg#(TEx1)    r1 <- mkReg( unpack(0) );
   FIFO#(TEx1) fifo <- mkFIFO;

   TEx2 r2;
   r2.ra <- mkReg(2);
   r2.rb <- mkReg(True);

   Reg#(int)  reg3A <- mkReg(3);
   Reg#(Bool) reg3B <- mkReg(False);

   TEx2 r3;
   r3.ra = reg3A;
   r3.rb = reg3B;
   
   rule init ( step == 0 );
      $display("=== step 0 ===");
      $display("r1.a = ", r1.a);
      $display("r1.b = ", r1.b);
      TEx1 t = r1;
      t.a = 20;
      t.b = False;
      r1 <= t;

        step <= step +1; 
    endrule

    rule step1(step == 1); 
        $display("=== step 1 ==="); 
        $display("r2.ra = ", r2.ra); 
        $display("r2.rb = ", r2.rb); 

        r2.ra <= 31; 
        r2.rb <= False; 
        
        step <= step + 1; 
    endrule

    rule step2 (step == 2); 
        $display("=== step 2 ==="); 
        $display("r3.ra = ", r3.ra); 
        $display("r3.rb = ", r3.rb); 
        $display("All done"); 
        $finish(0); 
    endrule

endmodule

endpackage