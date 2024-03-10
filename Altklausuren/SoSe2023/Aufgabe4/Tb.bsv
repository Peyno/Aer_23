package Tb; 
import FIFO::*; 
import StmtFSM::*; 
import GetPut::*; 
import Vector::*; 

typedef Tuple2#(Bit#(11), Bit#(4)) InTpl; 

interface Serializer; 
    method Bool getValue(); 
    interface Put#(InTpl) indata; 
endinterface

module mkSerializer(Serializer); 
    FIFO#(InTpl) in <- mkFIFO; 
    Reg#(Bit#(11)) data <- mkRegU; 
    Reg#(Bit#(4)) len <- mkRegU; 
    Wire#(Bool) outwire <- mkWire(); 
    Reg#(Bit#(4)) ctr <- mkRegU; 

    Stmt s = seq
        while(True) seq
            //TODO: implement logic

            action
                let t = in.first; in.deq; 
                match {.d, .l} = t; 
                data <= d; 
                len <= l; 
            endaction 

            for(ctr <= 0; ctr < len + 1; ctr <= ctr + 1)action 
                outwire <= unpack(data[ctr]); 
            endaction 


        endseq
    endseq; 

    //TODO: instantiate and start FSM
    mkAutoFSM(s); 
    method Bool getValue(); 
        return outwire; 
    endmethod

    //TODO: implement Put Subinterface
    interface Put   indata = toPut(in); 
endmodule

module mkTB1(Empty); 
    Serializer dut <- mkSerializer();
    Reg#(Bool) start <- mkReg(True); 
    
    rule r(start); 
        InTpl in = {00000101100, 6}; 
        dut.request(in); 
        start <= False; 
    endrule



    rule r1; 
        $display("getValue : %d", dut.getValue()); 
    endrule


endmodule



module mkTB(Empty); 
    Serializer dut <- mkSerializer(); 
    Vector#(10, Bit#(11)) samples = getWith(fromInteger); 
    Reg#(UInt#(4)) inctr <- mkRegU; 
    Reg#(UInt#(4)) bitctr <- mkRegU; 
    Reg#(Bit#(11)) reconstructed <- mkRegU; 

    Stmt s = seq

    endseq; 
    mkAutoFSM(s); 
endmodule



endpackage