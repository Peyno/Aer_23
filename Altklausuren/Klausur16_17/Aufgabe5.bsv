package Aufgabe5;

import StmtFSM::*; 
import FIFO::*; 
import GetPut::*; 
    interface Mac;
        method Action putA(Int#(16) b);
        method Action putB(Int#(16) c);

        method Int#(32) getAcc();
    endinterface

    module mkAcc(Mac);
        FIFO#(Int#(16)) inA <- mkFIFO;
        FIFO#(Int#(16)) inB <- mkFIFO;
        Reg#(Int#(32)) a <- mkReg(0);

        rule calc;
            a <= a + (extend(inA.first()) * extend(inB.first()));
            inA.deq; inB.deq;
        endrule

        method Action putA(Int#(16) b);
            inA.enq(b);
        endmethod

        method Action putB(Int#(16) c);
            inB.enq(c);
        endmethod

        method Int#(32) getAcc();
            return a;
        endmethod
    endmodule


    module mkAcc2(Mac); 
        FIFO#(Int#(16)) inA <- mkFIFO;
        FIFO#(Int#(16)) inB <- mkFIFO;
        Reg#(Int#(32)) a <- mkReg(0);

        rule calc;
            a <= a + (extend(inA.first()) * extend(inB.first()));
            inA.deq; inB.deq;
        endrule

        interface putA = toPut(inA); 
        interface putB = toPut(inB); 
        interface getAcc = a; 
    endmodule


    module mkMacTb(Empty);
        Mac dut1 <- mkAcc; 
       Mac dut2 <- mkAcc2; 
Reg#(Int#(32)) resultdut1 <- mkReg(0); 
Reg#(Int#(32)) resultdut2 <- mkReg(0); 
        Stmt test = seq
           par
            seq
                dut1.putA(2); 
                dut1.putB(3); 
                resultdut1 <= dut1.getAcc; 
                $display("Ergebnis dut1 : %d", resultdut1); 
            endseq
            seq
                dut2.putA(2); 
                dut2.putB(3); 
                resultdut2 <= dut2.getAcc; 
                $display("Ergebnis dut2 : %d", resultdut2); 
            endseq
            endpar
        endseq; 
        mkAutoFSM(test); 


    endmodule

endpackage 
