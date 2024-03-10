package Tb; 
import StmtFSM::*;  

(* synthesize *)
module mkTb(Empty); 

    Reg#(Bool) complete <- mkReg(False); 

    Stmt test = 
    seq
        $display("I am now running at ", $time); 
        $display("I am now running one more step at ", $time); 
        $display("And now I will finish at ", $time); 
        $finish; 
    endseq; 

    FSM testFSM <- mkFSM (test); 

    rule startit; 
        testFSM.start(); 
    endrule

    rule alwaysrun; 
        $display("  and a rule fires at", $time); 
    endrule
endmodule

endpackage