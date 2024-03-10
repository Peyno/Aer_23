
package Tb; 
import StmtFSM::*; 
/*

module mkTb(Empty); 
    
Reg#(Int#(32)) result <- mkReg(0); 

    rule r1;
            $display("Result %%d" , result); 
    endrule
        
    rule r2; 
            result <= result + 1; 
    endrule

    rule r3(result == 10); 
        $finish(0); 
    endrule

endmodule
*/

module mkTb2(Empty); 
    Reg#(Int#(32)) c <- mkReg(0); 
    for(Integer i = 0; i < 11; i = i + 1)begin 
        rule  r1; 
            $display("%d", fromInteger(i)); 
        endrule 
        
    end
    
    Stmt test = seq
        for(c <= 0; c < 11; c <= c + 1)action 

                $display("%d" , c); 
        endaction 
    endseq;
    mkAutoFSM(test); 
endmodule


module mkTb3(Empty); 
    Reg#(Int#(32)) c <- mkReg(0); 

    Stmt test = seq
        while(c < 11)action 
            
            $display("%d", c); 
            c <= c + 1; 
            
        endaction
    endseq; 
    mkAutoFSM(test); 
endmodule

endpackage