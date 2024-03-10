package Tb; 
import FIFOF::*; 
import StmtFSM::*; 
import GetPut::*; 
import FIFO::*; 
import Vector::*; 

interface TX_ifc; 
    interface Put#(Bit#(8)) data; 
    method Bit#(1) pin(); 
endinterface

typedef enum {IDLE, START, TRANSFER} States deriving(Bits, Eq, FShow); 

module mkTX(TX_ifc);
    Integer ticks = 16; 
    FIFOF#(Bit#(8)) fifo <- mkFIFOF; 
    Reg#(Bit#(1)) pinbit <- mkReg(1); 
    Reg#(States) state <- mkReg(IDLE); 
    Reg#(Int#(32)) count <- mkReg(fromInteger(ticks)); 
    Reg#(Bit#(8)) fifowert <- mkRegU; 
    Reg#(Int#(32)) cc <- mkRegU; 

    rule counter (count > 0 ); 
        count <= count - 1; 
    endrule

    rule idlerule (state == IDLE && count == 0); 
        cc <= 0; 
        count <= 16; 
        pinbit <= 1; 
        if(fifo.notEmpty)begin 
            state <= START; 
        end
    endrule

    rule startrule(state == START && count == 0); 
        count <= 16; 
        pinbit <= 0; 
        state <= TRANSFER; 
    endrule

    rule transferrule(state == TRANSFER && count == 0); 
        count <= 16; 
        cc <= cc + 1; 
        //cc <= 0; 
        let x = fifo.first; 
        fifowert <= x; 
        if(cc < 8)begin 
            pinbit <= fifowert[cc]; 
            
        end
        else begin 
            fifo.deq; 
           // pinbit <= 1; 
            state <= IDLE; 
        end
    endrule




    method Bit#(1) pin(); 
        return pinbit; 
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

    module mkTestbench(Empty);

    Integer tickCounterTop = 16;

    Integer ascii_0 = 48;
    Integer ascii_9 = 57;

    // let dut <- mkTX;
    let dut <- mkTX;

    Reg#(UInt#(32)) rIndex <- mkRegU;
    Reg#(UInt#(32)) rCounter <- mkRegU;
    Reg#(Bit#(8)) rPkt <- mkRegU;
    FIFO#(Bit#(8)) fOut <- mkFIFO;

    Reg#(UInt#(32)) rTestIndexOut <- mkRegU;
    Reg#(UInt#(32)) rTestIndexRX <- mkRegU;

    function Bit#(8) offset_data(Integer x) = fromInteger(x + ascii_0);
    Vector#(10, Bit#(8)) testData = map(offset_data, genVector);

    Stmt s = seq
        rTestIndexOut <= 0;
        rTestIndexRX <= 0;
        par
        while(rTestIndexOut < 10) seq
            action
                let out = testData[rTestIndexOut];
                $display("Sending %0b", out);
                dut.data.put(out);
                fOut.enq(out);
                rTestIndexOut <= rTestIndexOut + 1;
            endaction
        endseq
        while(rTestIndexRX < 10) seq
            action
                await(dut.pin() == 1'b0); //wait for start bit
                rCounter <= fromInteger(tickCounterTop + tickCounterTop/2 - 2); //first sample is in middle of first bit
                rIndex <= 0;
                rPkt <= 0;
            endaction
            while(rIndex < 8) seq
                while(rCounter > 0) //move to next bit
                    rCounter <= rCounter - 1;
                //sample the output pin
                action
                    let c = rPkt;
                    c[rIndex] = dut.pin();
                    rCounter <= fromInteger(tickCounterTop - 1) ;
                    rIndex <= rIndex + 1;
                    rPkt <= c;
                endaction
            endseq
            par
            seq            
                while(rCounter > 0) //wait for stop bit
                    rCounter <= rCounter - 1;
                action
                    if(dut.pin != 1'b1) begin
                        $display("Expected stop bit");
                        $finish;
                    end
                endaction
            endseq
            action //check received data
                if(rPkt != fOut.first) begin
                    $display("Sent out: %0b but got back: %0b", fOut.first, rPkt);
                    $finish;
                end else begin
                    $display("Received: %0b", rPkt);
                    fOut.deq;
                end
            endaction
            endpar
            rTestIndexRX <= rTestIndexRX + 1;
        endseq
        endpar
        $display("Finished successfully");
    endseq;

    mkAutoFSM(s);

endmodule
endpackage