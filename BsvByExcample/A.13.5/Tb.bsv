package Tb; 
import StmtFSM::*; 
import FIFOF::*; 

(* synthesize *)
module mkTb(Empty); 

    FIFOF#(int) fifo <- mkFIFOF; 
    Reg#(Bool) cond <- mkReg(True); 
    Reg#(int) ii <- mkRegU; 
    Reg#(int) jj <- mkRegU; 
    Reg#(int) kk <- mkRegU; 

    function Action functionOfAction(int x); 
        return action 
                $display("this is an action inside of a function, writing %d", x); 
                ii <= x; 
        endaction; 
    endfunction

    function Stmt functionOfSeq(int x); 
        return seq
                action 
                    $display("sequence in side function %d", x); 
                    ii <= x; 
                endaction 
                action 
                    $display("sequence in side function %d", x+1); 
                    ii <= x+1; 
                endaction 
        endseq; 
    endfunction 

    Stmt test = 
    seq
        $display("This is action 1"); 
        $display("This is action 2"); 
        $display("This is action 3");  

        action 
            $display("This is action 4, part a"); 
            $display("This is action 4, part b"); 
        endaction  

        functionOfAction(10); 
        functionOfAction(20); 
        functionOfAction(30); 

        functionOfSeq(50); 

        action 
            $display("This is action 5"); 
            if(cond)
                $display("And it may hav several actions inside of it"); 
        endaction 

        noAction; 

        repeat (4) noAction; 

        repeat (4) action 
                        $display("Repeating action!"); 
                        $display("Check it out"); 
        endaction 

        seq
            noAction; 
            noAction; 
        endseq

        if(cond) seq
            $display("If seq 1"); 
            $display("If seq 2"); 
            $display("If seq 3"); 
        endseq
        else seq
            action 
                $display("Else seq 1"); 
            endaction 
            action 
                $display("Else seq 2"); 
            endaction
        endseq

        action 
            if(cond)
                $display("if action 1"); 
            else
                $display("else action 1"); 
        endaction

        action 
            $display("Enq 10 at time ", $time); 
            fifo.enq(10); 
        endaction 
        action 
            $display("Enq 20 at time ", $time); 
            fifo.enq(20); 
        endaction 
        action 
            $display("Enq 30 at time ", $time); 
            fifo.enq(30); 
        endaction 
        action 
            $display("Enq 40 at time ", $time); 
            fifo.enq(40); 
        endaction 


        action 
            $display("Fifo is now empty, continue..."); 
            await(fifo.notEmpty() == False); 
        endaction 

        if(cond)
            noAction; 
        else
            noAction; 

        for(ii <= 0; ii < 10; ii <= ii + 1)seq
            $display("For loop ste %d at time ", ii, $time); 
        endseq

        ii <= 0; 

        while (ii < 10)seq
            action 
                $display("While loop step %d at time ", ii, $time); 
                ii <= ii + 1; 
            endaction 
        endseq

        for(ii <= 0; ii<=4; ii<=ii+1)
            for(jj<=0; jj<=5; jj<=jj+1)
                for(kk <=0; kk<=3; kk<=kk+1)seq
                    action 
                        if(kk == 0)
                            $display("kk = 000, and ii=%1d, jj=%1d", ii, jj); 
                        else
                            $display("kk = --%1d, and ii=%1d, jj=%1d", kk, ii, jj); 
                    endaction 
                endseq
        
        par
            $display("Par block statement 1 at ", $time); 
            $display("Par block statement 2 at ", $time); 

            seq
                $display("Par block statement 3a at ", $time); 
                $display("Par block statement 3b at ", $time); 
            endseq

        endpar
        $display("Par block done!"); 
        par
            seq
                ii <= 2; 
                ii <= 3; 
            endseq

            seq
                ii <= 1; 
                ii <= 0; 
            endseq

            ii <= 10; 

        endpar

        $display("par block conflict test, ii = ", ii); 
    endseq;
    FSM testFSM <- mkFSM(test); 

    Stmt rcvr = 
    seq
        while(True) seq

            action 
                $display("fifo popped data", fifo.first()); 
                fifo.deq(); 
            endaction 

            repeat (5) noAction; 
        endseq
    endseq; 

    FSM rcvrFSM <- mkFSM(rcvr); 

    rule startit; 
        testFSM.start(); 
        rcvrFSM.start(); 
    endrule

    rule finish(testFSM.done() && !rcvrFSM.done());
        $finish; 
    endrule

endmodule

endpackage