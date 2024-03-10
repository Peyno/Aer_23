package Tb;


module mkFilter(Server#(Tuple2#(GrayScale, Vector#(16, GrayScale)), Bool));

    FIFO#(Tuple2#(GrayScale, Vector#(16, GrayScale))) inputFIFO <- mkBypassFIFO; 
    FIFO#(Bool) outputFIFO <- mkBypassFIFO; 

    Server#(Tuple2#(GrayScale, Vector#(12, GrayScale)), Bool) comparators[16]; 
    for(Integer i = 0; i < 16; i = i + 1)
        comparators[i] <- mkComparator(); 

    function Vector#(12, GrayScale) takeSomeValues(Vector#(16, GrayScale) v, Integer start); 
        Vector#(12, GrayScale) vec; 
        for(Integer i = 0; i < 12; i = i + 1)
            vec[i] = v[(i+ start) % 16]; 

            return vec; 
    endfunction 

    rule drain; 
        let tmp = inputFIFO.first; 
        inputFIFO.deq; 

        let val = tpl_1(tmp); 
        let val = tpl_2(tmp); 

        for(Integer i = 0; i < 16; i = i + 1)
            comparators[i].request.put(tuple2(val, takeSomeValues(vals, i))); 
    endrule

    rule fill; 
        Bool flag = False; 

        for(Integer i = 0; i < 16; i = i + 1)begin
            Bool tmp <- comparators[i].response.get; 
            flag = flag || tmp; 
        end

        outputFIFO.enq(flag); 
    endrule

    interface Put request = toPut(inputFIFO); 
    interface Get response = toGet(outputFIFO); 
endmodule

endpackage: Tb