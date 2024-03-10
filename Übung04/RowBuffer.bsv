package RowBuffer;

import Vector::*;
import GetPut::*;
import ClientServer::*;
import FIFO::*;
import SpecialFIFOs::*;
import BRAMFIFO::*;

import MyTypes::*;
import Buffer::*;


interface RowBufferServer;
    interface Vector#(2, Server#(GrayScale, GrayScale)) buffer_server;
endinterface: RowBufferServer


(* synthesize *)
module mkRowBuffer(RowBufferServer);
    BufferServer buffer[2];
    for(Integer i = 0; i < 2; i = i + 1)
        buffer[i] <- mkBRAMBuffer;

    Vector#(2, Server#(GrayScale, GrayScale)) servers;
    servers[0] = buffer[0].server;
    servers[1] = buffer[1].server;

    interface buffer_server = servers;
endmodule

endpackage