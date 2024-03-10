package Tb; 
import FIFOF::*; 
import GetPut::*; 
import StmtFSM::*; 

interface TX_ifc; 
    interface Put#(Bit#(8)) data; 
    method Bit#(1) pin(); 
endinterface

typedef enum {IDLE, START, TRANSMIT, ENDE } States deriving (Bits, Eq, FShow); 

module mkTX(TX_ifc); 
    Integer ticks = 16; 

    FIFOF#(Bit#(8)) fifo <- mkFIFOF; 
    Reg#(Bit#(1)) bbit <- mkReg(1); 
    Reg#(States) state <- mkReg(IDLE); 
    Reg#(Int#(32)) count <- mkReg(fromInteger(ticks)); 
    Reg#(Bit#(8)) datafifo <- mkRegU; 

    Reg#(Int#(32)) c <- mkReg(0); 

    rule cc (count > 0 ); 
        count <= count - 1; 
    endrule

    rule r1 (state == IDLE && count == 0); 
     c <= 0; 
        count <= 16; 
        bbit <= 1; 
        if(fifo.notEmpty)begin 
            
            state <= START; 
        end
    endrule

    rule r2(state == START && count == 0); 
        count <= 16; 
        bbit <= 0; 
       
        state <= TRANSMIT; 
    endrule

    rule r3(state == TRANSMIT && count == 0); 
        count <= 16; 
         c <= c + 1 ; 

        let x = fifo.first; 
            datafifo <= x ; 

        if( c  < 8)begin 
            bbit <= datafifo[c]; 
           
        end
        else begin 
        fifo.deq; 

        state <= IDLE; 
        end
    endrule 

    rule r4 (state == ENDE && count == 0); 
    fifo.deq; 
        c <= 0; 
        count <= 16; 
        bbit <= 1; 
        state <= IDLE; 
    endrule



    method Bit#(1) pin(); 
        return bbit; 
    endmethod

    interface Put data = toPut(fifo); 
endmodule

module mkTB2(Empty); 
 TX_ifc dut <- mkTX();
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