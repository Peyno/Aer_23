package Aufgabe2; 

interface StreamMaster; 
    interface Put#(Bit#(32)) data_in; 
endinterface

interface StreamMasterHelper; 
    method Bool isTReady; 
    method Action setTValid(Bool valid); 
    method Action setTData(Bit#(32) data); 
endinterface

typedef enum {
    IDLE, 
    TRANSFER, 
    WAIT
} States deriving (Bits, Eq, FSowh); 

module mkStreamMaster (StreamMaster); 
    StreamMasterHelper helper <- mkStreamMasterHelper; 
    Reg#(States) states <- mkReg(IDLE); 

    FIFOF#(Bit#(32)) data <- mkFIFOF; 
    helper.setTValid(False); 
    rule idleRule(states == IDLE)
        if(data.notEmpty) begin 
            states <= TRANSFER; 
        end else begin  //optional
            states <= IDLE; 
        end
    endrule

    rule transferRule(states == TRANSFER); 
        helper.setTValid(True); 
        let dataloc = data.first; 
        data.deq; 
        helper.setTData(dataloc); 
        if(helper.isTReady)begin 
            states <= IDLE; 
        end else begin
            states <= WAIT; 
        end
    endrule

    rule waitRule(states == WAIT); 
        if(helper.isTReady) begin 
            states <= IDLE; 
        end else begin 
            states <= WAIT; 
        end
    endrule

    interface data = toPut(data); 


endmodule

endpackage