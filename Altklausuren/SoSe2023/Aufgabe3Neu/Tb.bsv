package Tb; 
import FIFO::*; 
import StmtFSM::*; 
import Vector::*; 
import ClientServer::*; 
import GetPut::*; 



module mkPipeline(Server#(Int#(32), Int#(32))); 
    Server#(Int#(32), Int#(32)) stage0 <- mkAdd; 
   Server#(Int#(32), Int#(32)) stage1 <- mkMult; 
    Reg#(Int#(32)) x <- mkRegU; 

    Vector#(3, FIFO#(Int#(32))) fifos <- replicateM(mkFIFO); 


    rule r1; 
        $display("1"); 
        let t = fifos[0].first; fifos[0].deq; 
        stage0.request.put(t); 
    endrule

    rule r2; 
     $display("2"); 
        let t <- stage0.response.get(); 
        fifos[1].enq(t); 
    endrule

    rule r3; 
     $display("3"); 
        let t = fifos[1].first; fifos[1].deq; 
        stage1.request.put(t); 
    endrule

    rule r4; 
     $display("4"); 
        let t <-  stage1.response.get(); 
        fifos[2].enq(t); 
    endrule



interface request = toPut(fifos[0]); 
interface response = toGet(fifos[2]); 

endmodule



















module mkAdd(Server#(Int#(32), Int#(32))); 
    FIFO#(Int#(32)) in <- mkFIFO; 
    FIFO#(Int#(32)) out <- mkFIFO; 

    rule r; 
        let t = in.first; 
        out.enq(t + 5); 
    endrule

   interface request = toPut(in); 
   interface response = toGet(out); 
endmodule

module mkMult(Server#(Int#(32), Int#(32))); 
     FIFO#(Int#(32)) in <- mkFIFO; 
    FIFO#(Int#(32)) out <- mkFIFO; 

    rule r; 
        let t = in.first; 
        out.enq(t * t); 
    endrule

   interface request = toPut(in); 
   interface response = toGet(out); 

endmodule








module mkTB(Empty); 
    Server#(Int#(32), Int#(32)) dut <- mkPipeline(); 

    Stmt s = seq
        dut.request.put(2); 
        $display("Ergebnis der Pipeline: %d", dut.response.get()); 

    endseq; 

    mkAutoFSM(s); 


endmodule
endpackage