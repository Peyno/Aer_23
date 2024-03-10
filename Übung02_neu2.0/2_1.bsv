package 2_1; 

interface  CalcUnit; 
    method Action put(Int#(32) x); 
    method AcitonValue#(Int#(32)) result(); 
endinterface

interface Pipeline; 
    interface CalcUnit calc; 
    method Action setParam(UInt#(32) addr, Int#(32) val); 
endinterface    

module mkSimplePipeline(Pipeline); 
    FIFOF#(Int#(32)) in <- mkFIFOF; 
    FIFO#(Int#(32)) out <- mkFIFO; 
    Vector#(3, Reg#(Int#(32))) params <- replicate(mkRegU); 
    Vector#(4, Reg#(Maybe#(Int#(32)))) regs <- replicateM(mkReg(tagged Invalid)); 

    rule all_together; 
        if(fifo_in.notEmpty)begin 
            let x = fifo_in.first; fifo_in.deq; 
            regs[0] <= tagged Valid(x + params[0]); 
        end else begin 
            regs[0] <= tagged Invalid; 
        end

        if(regs[0] matches tagged Valid .x) begin 
            regs[1] <= tagged Valid (x * params[1]); 
        end else begin 
            regs[1] <= tagged Invalid; 
        end

        if(regs[1] matches tagged Valid .x)begin 
            regs[2] <= tagged Valid (x * params[2]); 
        end else begin 
            regs[2] <= tagged Invalid; 
        end

        if(regs[2] matches tagged Valid .x) begin 
            regs[3] <= tagged Valid (x / 4); 
        end else begin 
            regs[3] <= tagged Invalid; 
        end

        if(regs[3] matches tagged Valid .x)begin 
            fifo_out.enq(x + 128); 
        end 
    endrule


    method Action setParam(UInt#(32) addr, Int#(32) val); 
        params[addr] <= val; 
    endmethod

    interface CalcUnit calc; 
        method Action put(Int#(32) x); 
            fifo_in.enq(x); 
        endmethod

        method ActionValue#(Int#(32)) result(); 
            fifo_out.deq(); 
            return fifo_out.first; 
        endmethod
    endinterface
endmodule

endpackage