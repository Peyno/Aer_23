package Tb; 
import StmtFSM::*; 
import ClientServer::*; 
import FIFO::*; 
import GetPut::*; 

module mkTB(Empty); 
    Reg#(UInt#(32)) cntr1 <- mkRegU; 
    Reg#(UInt#(32)) cntr2 <- mkRegU; 
    Server#(UInt#(32), UInt#(32)) sqrt <- mkSqrt(); 

    Stmt s = seq
        $display("Hello"); 
        par
            seq
                for(cntr1 <= 0; cntr1 < 21; cntr1 <= cntr1 + 1) action 
                    sqrt.request.put(cntr1); 
                endaction 
            endseq
            seq
                for(cntr2 <= 0; cntr2 < 21; cntr2 <= cntr2 + 1) action 
                    let r = sqrt.response.get(); 
                    $display("Ergebnis: %d", r); 
                endaction 
            endseq
        endpar

    endseq; 
mkAutoFSM(s); 
endmodule

module mkTB2(Empty); 
    Reg#(UInt#(32)) cntr1 <- mkRegU; 
    Reg#(UInt#(32)) cntr2 <- mkRegU; 
    Server#(UInt#(32), UInt#(32)) sqrt <- mkSqrt(); 

    Stmt s = seq
        $display("Hello"); 
        par
            
                for(cntr1 <= 0; cntr1 < 21; cntr1 <= cntr1 + 1) seq 
                    sqrt.request.put(cntr1); 
                endseq
            
            
                for(cntr2 <= 0; cntr2 < 21; cntr2 <= cntr2 + 1) seq
                    action 
                    let r = sqrt.response.get(); 
                    $display("Ergebnis: %d", r); 
                    endaction
                endseq
            
        endpar

    endseq; 
mkAutoFSM(s); 

endmodule

module mkSqrt(Server#(UInt#(32), UInt#(32))); 
    FIFO#(UInt#(32)) in <- mkFIFO; 
    FIFO#(UInt#(32)) out <- mkFIFO; 

    rule get; 
       let t = in.first; in.deq; 
       out.enq(t); 
    endrule


interface request = toPut(in); 
interface response = toGet(out); 

endmodule


endpackage