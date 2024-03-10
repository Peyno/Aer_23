package Tb;

import FIFOF :: *;
import GetPut :: *;
import StmtFSM::*; 
import FIFO::*; 

interface TX_ifc;
    method Bit#(1) pin();
    interface Put#(Bit#(8)) data;
endinterface


(* synthesize *)
module mkTXSR(TX_ifc);

    Integer tickCounterTop = 16;

    FIFO#(Bit#(8)) fTX <- mkFIFO;
    Reg#(Bit#(1)) rOutputPin <- mkReg(1'b1);
    Reg#(UInt#(32)) rCounter <- mkReg(0);

    Reg#(Bit#(10)) rOut <- mkReg(0); //shift register for output
    Reg#(UInt#(4)) rBitIndex <- mkReg(10);
    PulseWire pwTick <- mkPulseWire;

    rule tick_gen;
        if(rCounter + 1 >= fromInteger(tickCounterTop)) begin
            pwTick.send();
            rCounter <= 0;
        end else 
            rCounter <= rCounter + 1;
    endrule

    rule send_bit (pwTick);
        if(rBitIndex == 10) begin
            let pkt = fTX.first; fTX.deq;
            rOut <= {1'b1, pkt, 1'b0}; //{stop-bit, data, start-bit}
            rBitIndex <= 0;
        end else if(rBitIndex != 10) begin
            rOut <= {1'b1, rOut[9:1]};
            rOutputPin <= rOut[0];
            rBitIndex <= rBitIndex + 1;
        end
    endrule

    method pin = rOutputPin;
    interface data = toPut(fTX);

endmodule


module mkTB2(Empty); 
 TX_ifc dut <- mkTXSR();
        Bit#(8) data = 8'b10101010;
        Reg#(int) counter <- mkReg(0);
        Reg#(int) mistakes <- mkReg(0);

        Stmt s = seq
            $display("StartTB ...");
            action
                let pin = dut.pin;
                if(pin != 1) action
                    $display("Wrong Idle Output!");
                    mistakes <= mistakes + 1;
                endaction
            endaction
            dut.data.put(data);
            action
                $display("Waiting for Data to be sent ...");
                await( dut.pin == 0 );
            endaction

            // Waiting for the start bit to be sent
            repeat (15) action
                let pin = dut.pin;
                if(pin != 0) action
                    $display("Wrong Data Notification!");
                    mistakes <= mistakes + 1;
                endaction
            endaction
            for(counter <= 0; counter < 8; counter <= counter + 1) seq
                repeat (16) action
                    $display("Data: %d ... Fetching Data from Tackt: %d",counter, $time);
                    let pin = dut.pin;
                    if(pin != data[counter]) action
                        $display("%d Wrong Data expected: %d got: %d  Time: %d", counter, data[counter],pin, $time);
                        mistakes <= mistakes + 1;
                    endaction    
                endaction
            endseq
                
            // Waiting for the last bit to be sent
            repeat (16) action
                let pin = dut.pin;
                if(pin != 1) action
                    $display("Wrong END Bit: 1 got: ", pin);
                    mistakes <= mistakes + 1;
                endaction    
            endaction

            $display("Code executed with %d Mistakes!", mistakes);
            
        endseq;
        mkAutoFSM(s);
    endmodule 

endpackage