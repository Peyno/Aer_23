package Tb; 

import StmtFSM::*; 

module mkTb(Empty); 

    Stmt test = 
    seq
        $display("I am now running at ", $time);
         $display("I am now running one more step at ", $time);
         $display("And now I will finish at", $time);
    endseq;

    mkAutoFSM(test); 

    rule alwaysrun; 
        $display(" and a rule fires at", $time); 
    endrule

endmodule

endpackage