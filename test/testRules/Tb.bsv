package Tb; 
import FIFO::*; 
interface Conflict; 
    method ActionValue#(Bool) getConflict(); 
endinterface

module mkTb(Conflict); 
    FIFO#(Bool) queue <- mkFIFO(); 
    Reg#(Bit#(1)) cntr <- mkReg(0); 

    rule switch; 
        if(cntr == 0) begin 
            queue.enq(True); 
        end else begin
            queue.enq(False); 
        end
    endrule
    rule r1; 
        cntr <= cntr + 1; 
    endrule

    method ActionValue#(Bool) getConflict(); 
        let t = queue.first(); queue.deq(); 
        return t; 
    endmethod

endmodule


module mkTB1(Empty); 
    Conflict dut <- mkTb; 
    Reg#(Int#(32)) cntr <- mkReg(0); 

    rule r; 
        $display("%d", dut.getConflict()); 
    endrule

    rule r1; 
        cntr <= cntr + 1; 
        if(cntr == 10)
            $finish(0); 
    endrule

  

endmodule

endpackage