package Tb; 

typedef Bit#(14) TD; 

import FIFO::*; 
import Vector::*; 
import StmtFSM::*; 

(* synthesize *)
module mkTb(Empty); 

    Vector#(2, FIFO#(TD)) ififo <- replicateM(mkFIFO); 

    Vector#(4, FIFO#(TD)) ofifo <- replicateM(mkFIFO); 

    (* preempts = "move0, move1" *)

    rule move0; 
        let data  = ififo[0].first(); 
        ififo[0].deq(); 

        case ( data[13:12])
            0: ofifo[0].enq(data); 
            1: ofifo[1].enq(data); 
            2: ofifo[2].enq(data); 
            3: ofifo[3].enq(data); 
        endcase
    endrule

    rule move1; 
        let data = ififo[1].first(); 
        ififo[1].deq(); 

        case (data[13:12])
            0: ofifo[0].enq(data); 
            1: ofifo[1].enq(data); 
            2: ofifo[2].enq(data); 
            3: ofifo[3].enq(data); 
        endcase
    endrule

    Stmt test = 
    seq 
        ififo[0].enq( 'h0000 ); 
        ififo[0].enq( 'h1001 );
        ififo[0].enq( 'h2002 );
        ififo[0].enq( 'h3003 );
        ififo[1].enq( 'h0000 );
        ififo[1].enq( 'h1010 );
        ififo[1].enq( 'h2020 );
        ififo[1].enq( 'h3030 );
        noAction; 
    endseq; 
    mkAutoFSM(test); 

    for(Integer i=0; i<4; i=i+1)
        rule watch; 
            let data = ofifo[i].first(); 
            ofifo[i].deq(); 
            $display("ofifo[%d] => %x at ", i, data, $time); 
        endrule
endmodule: mkTb

endpackage: Tb