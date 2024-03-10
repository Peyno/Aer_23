package Tb; 
import FIFO::*; 
import StmtFSM::*; 
import ClientServer::*; 
import GetPut::*; 

module mkModule(Server#(Reg#(Int#(16)), Reg#(Int#(16)))); 
    Reg#(Int#(16)) a <- mkRegU; 
    Reg#(Int#(16)) b <- mkReg(0); 

    rule r1;  
        
        $display("Wert aus der a : %d", a); 
       
    endrule

    
    interface request = toPut(a); 
    interface response = toGet(b); 

endmodule

module mkTB(Empty); 
    Server#(Reg#(Int#(16)), Reg#(Int#(16))) dut <- mkModule(); 
    Reg#(Int#(16)) x <- mkReg(5); 
    Stmt s = seq
        dut.request.put(x); 

        action 
         let w =   dut.response.get(); 
         $display("Wert in FSM : %d", w);
        endaction 
    endseq; 
    mkAutoFSM(s); 

endmodule

endpackage
