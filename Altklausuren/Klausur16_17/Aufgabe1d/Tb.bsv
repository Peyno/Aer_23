package Tb; 
import Vector::*; 
import StmtFSM::*; 


module mkTb(Empty); 
    Reg#(int) ctr <- mkReg(0); 

    Reg#(Vector#(10, UInt#(32))) b <- mkReg(replicate(0)); 
   // Vector#(10, Reg#(UInt#(32))) b <- replicateM(mkRegU); 
   
 
Stmt s = seq
  
     b <= genVector();
   
    for(ctr <= 0; ctr < 10; ctr <= ctr + 1)action 
        $display("Vector: %d", b[ctr]); 
    endaction 

endseq; 
mkAutoFSM(s); 


endmodule


endpackage