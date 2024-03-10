package Tb; 
import StmtFSM::*; 
module mkThirdFSM(Empty); 

    Reg#(UInt#(12)) counter <- mkReg(0); 
    PulseWire pw <- mkPulseWire(); 
    Reg#(UInt#(12)) i <- mkReg(0); 

    rule count (counter < 99); 
        counter <= counter + 1; 
    endrule

    rule restCount (counter == 99); 
        counter <= 0; 
        pw.send(); 
    endrule

    Stmt thirtStmt = {
        seq
            for(i <= 0; i < 20; i <= i + 1)seq
                $display("(%0d) Iteration %d.", $time, i); 
            endseq
            $finish(); 
        endseq
    }; 
    FSM myFSM <- mkFSMWithPred(thirtStmt, pw); 
    
    rule startFSM(myFSM.done()); 
        myFSM.start(); 
    endrule


endmodule



endpackage 