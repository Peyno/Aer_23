package Tb; 
import ClientServer::*; 
import FIFO::*; 
import GetPut::*; 

interface Div; 
    interface Put#(Tuple2(Int#(32), Int#(32))) request; 
    interface Get#(Maybe#(32)) response; 

endinterface


module mkDiv(Div); 

    FIFO#(Tuple2(Int#(32), Int#(32))) in <- mkFIFO; 
    FIFO#(Maybe#(Int#(32))) out <- mkFIFO; 

    Reg#(Maybe#(Int#(32))) result <- mkReg(tagged Invalid); 

    



    interface request = toPut(in); 
    interface response = toGet(out); 
endmodule

endpackage