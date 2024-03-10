package Tb; 
import StmtFSM::*; 

module mkTb(Empty); 
    Stmt test = {
        seq
             
                delay(1000); 
                action 
                $display("Hello World", $time); 
                endaction 
        endseq
    };
    mkAutoFSM(test); 
endmodule

endpackage 