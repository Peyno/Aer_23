package Buffer;

import GetPut::*;
import ClientServer::*;
import FIFO::*;
import SpecialFIFOs::*;
import BRAMFIFO::*;
import Settings::*;

import MyTypes::*;

interface BufferServer;
    interface Server#(GrayScale, GrayScale) server;
endinterface: BufferServer

// This buffer operates with BRAM fifos.
module mkBRAMBuffer(BufferServer);
    // TODO: implement this module (Task 3.1d)
    
    FIFO#(GrayScale) bufferedValue <- mkSizedBRAMFIFO(width-3+1); 

    Reg#(Bit#(12)) counterInput <- mkReg(0); 

    Reg#(Bool) flag[2] <- mkCReg(2, False); 

    interface Server server = interface Server; 
        interface Put request = interface Put
            method Action put(GrayScale p) if(!flag[1]); 
                bufferedValue.enq(p); 
                if(counterInput == fromInteger(width-3 -1))
                    flag[1] <= True; 
                else
                    counterInput <= counterInput + 1; 
            endmethod
        endinterface; 

        interface Get response = interface Get; 
            method ActionValue#(GrayScale) get() if(flag[0]); 
                bufferedValue.deq(); 
                flag[0] <= False; 
                return bufferedValue.first(); 
            endmethod
        endinterface; 
        endinterface; 

endmodule


endpackage



