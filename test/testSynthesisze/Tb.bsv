package Tb; 

//(* synthesize *)
module mkTB1 (Empty); 
Reg#(int) cntr <- mkReg(0); 

rule r1  ; 
    $display("Hallo Welt!"); 
    $finish(0); 
endrule


endmodule

 typedef struct {
    Bool bol; 
 } Stru deriving (Bits, Eq); 

//(* synthesize *)
module mkTB2#(Int#(32)  x) (Empty);

Reg#(int) cntr <- mkReg(x); 

rule r1  ; 
    $display("Hallo Welt!"); 
    $finish(0); 
endrule

endmodule

endpackage