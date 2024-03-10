package Tb; 

import FIFO::*; 
import GetPut::*; 
import ClientServer::*; 

Bool configVar = True; 
int x0 = 23; 

(* synthesize *)
module mkTb(Empty); 
    Reg#(int) cycle <- mkReg(0); 
    int initval = (configVar ? (x0 + 10) : (x0 + 20)); 
    Reg#(int) r0 <- (configVar ? mkReg(initval) : mkRegU); 

    Reg#(int) r1 ; 
    if(configVar)
        r1 <- mkReg(initval);
    else
        r1 <- mkRegU; 


    rule r; 
        $display("%0d: rule r, r0 = %0d, r1 = %0d", cycle, r0, r1); 

        r0 <= ((pack (cycle)[0]==1) ? (r0 + 1) : (r0 + 5)); 

        if(pack(cycle)[0]==1)
            r1 <= r1 + 1; 
        else    
            r1 <= r1 +5; 

        if(cycle > 7) $finish(0); 
        cycle <= cycle + 1; 
    endrule

endmodule: mkTb
endpackage: Tb