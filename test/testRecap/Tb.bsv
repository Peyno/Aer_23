package Tb; 
import FIFO::*;
import StmtFSM::*;



    typedef UInt#(8) GrayScale;

    interface ThresholdA;
        method Action setThreshold(GrayScale t);
        method Action put(GrayScale val);
        method ActionValue#(GrayScale) get;
    endinterface

    module mkThresholdA(ThresholdA);

        FIFO#(GrayScale) in <- mkFIFO;
        FIFO#(GrayScale) out <- mkFIFO;

        //gibt aktuellen Threshold an
        Reg#(GrayScale) thresh <- mkRegU;


        rule dosth;
            let t = in.first; in.deq;
            GrayScale res;

            // 2^8 = 256 Zahlen darstellbar --> Zahlen: 0-255
            if(t > thresh) res = 255;
            else res = 0;

            out.enq(res);
        endrule

        //Interface Implementation
        method Action setThreshold(GrayScale t);
            thresh <= t;
        endmethod

        method Action put(GrayScale val);
            in.enq(val);
        endmethod

        method ActionValue#(GrayScale) get;
            out.deq;
            return out.first; 
        endmethod
    endmodule





    module mkThresholdTb(Empty);

        ThresholdA dut <- mkThresholdA;

        Stmt s = seq
                dut.setThreshold(5); 

                dut.put(8); 

                action 
                    let t <- dut.get(); 
                    $display("Ergebnis ist : %d", t); 
                endaction 

        endseq; 
        mkAutoFSM(s); 


    endmodule

    module mkTBRules(Empty); 

        ThresholdA dut <- mkThresholdA; 
       
        rule set; 
            dut.setThreshold(5); 
        endrule


        rule put; 
            dut.put(3); 
        endrule

        rule ausgabe; 
            let t <- dut.get; 
            $display("Ergebnis ist : %d", t); 
            $finish(0); 
        endrule

    endmodule


endpackage
/*
        rule do_sth;
            dut.put(30);
        endrule
        //bei Clinet/Server
        //dut.interfaceName.request/responseMethode
        rule ausgabe;
            let t <- dut.get;
            $display("Ergebnis ist: %0d",t);
            $finish(0);
        endrule
        */