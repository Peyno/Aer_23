package Tb;
import FIFO::*; 
import FIFOF::*; 
import Vector::*;  
import ClientServer::*; 
import GetPut::*; 


typedef Bit#(8) GrayScale; 

module mkComparator(Server#(Tuple2#(GrayScale, Vector#(12, GrayScale)), Bool)); 

    FIFO#(Tuple2#(GrayScale, Vector#(12, GrayScale))) inputFIFO <- mkBypassFIFO;
        FIFO#(Bool) outputFIFO <- mkBypassFIFO; 

    rule calc; 
        let t  = inputFIFO.first; inputFIFO.deq; 
        let value = tpl_1(t); 
        let values = tpl_2(t); 

        Bool res = True; 
        for(Integer i = 0; i < 12; i = i + 1)begin 
            res = res && value < values[i]; 
        end
        
        outputFIFO.enq(res); 
    endrule

    interface Put request = toPut(inputFIFO); 
    interface Get response = toGet(outputFIFO); 

endmodule

module mkFastComparatorTB(); 
    Server#(Tuple2#(GrayScale, Vector#(12, GrayScale)), Bool) uut <- mkComparator; 
    Reg#(Bit#(32)) counter <- mkReg(1); 

    rule inc; 
        counter <= counter + 1; 
    endrule

    rule fill (counter > 100  && counter < 150); 
        Vector#(12, GrayScale) vec; 

        for(Integer i = 0; i < 12; i = i + 1)
            vec[i] = truncate(counter) + fromInteger(i); 

        let tmp  = tuple2(fromInteger(137), vec); 
        uut.request.put(tmp); 

    endrule

    rule drain; 
        let tmp = uut.response.get; 
        $display("Takt %d: War es alles größer als %d? %d", counter, 137, tmp); 
    endrule

    rule fin (counter > 200); 
        $finish(); 
    endrule

endmodule
endpackage: Tb