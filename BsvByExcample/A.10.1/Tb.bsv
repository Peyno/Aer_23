package Tb; 

import FIFO::*; 
import GetPut::*; 
import ClientServer::*; 

(* synthesize *)
module mkTb(Empty); 
    Reg#(int) klimit <- mkReg (24);
   rule r;
      int a = 10;
      for (int k = 20; k < klimit; k = k + 1)
         a = a + k;
      $display ("rule r, a = %0d", a);
   endrule

endmodule: mkTb
endpackage: Tb