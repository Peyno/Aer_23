package Tb; 

interface CompServer#(numeric type size); 
    interface Put#(Tuple2#(GrayScale, Vector#(size, GrayScale))) request; 
    interface Get#(Bool) response; 
endinterface: CompServer

module mkComparator#(Integer thresh) (CompServer#(size)); 

    FIFO#(Tuple2#(GrayScale, Vector#(size, GrayScale))) inputFIFO <- mkBypassFIFO; 
    FIFO#(Bool) outputFIFO <- mkBypassFIFO; 
    Reg#(GrayScale) threshold <- mkReg(unpack(fromInterger(thresh)));

    rule calc; 
        let t = inputFIFO.first; inputFIFO.deq; 
        
        let value = tpl_1(t); 
        let values = tpl_2(t); 

        Bool res = True; 
        for(Integer i = 0; i < valueOf(size); i = i + 1) begin 
            Bit#(9) tmp = extend(value) + extend(threshold); 
            res = res && tmp < extend(values[i]); 
        end

        ouputFIFO.enq(res); 
    endrule

    interface Put request = toPut(inputFIFO); 
    interface Get response = toGet(outputFIFO); 
endmodule

endpackage: Tb