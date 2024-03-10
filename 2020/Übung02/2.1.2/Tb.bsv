package Tb; 
import StmtFSM::*; 

module mkFSM(Empty); 

    Reg#(Bool) bol <-  mkReg(False); 

    Stmt test = {
        seq
        par
            seq
                
                $display("(%0d) Part one starts ",  $time); 
                delay(100); 
                bol <= True; 
                $display("(%0d) Part one done", $time); 
            endseq
            seq
            
                repeat(10) 
                    $display("Nachricht 2: ", $time);
              
                await(bol);  
                $display("(%0d) Part two done", $time); 
       
            endseq
        endpar
        $display("(%0d) Ende", $time); 
        endseq
    };

    mkAutoFSM(test); 
endmodule


endpackage