package Tb; 
import FIFO::*; 

interface Foo_ifc; 
    method ActionValue#(int) avx(); 
    method int vy(); 
    method Action ay(); 
    
    method int get_cycle_count(); 
endinterface

(* synthesize *)
module mkFoo (Foo_ifc); 
    Reg#(int) x <- mkReg(0); 
    Reg#(int) y <- mkReg(0);
    Reg#(int) cycle <- mkReg(0); 

    rule count_cycles; 
        cycle <= cycle + 1; 
        if(cycle > 3) $finish(0); 
    endrule

    rule incx; 
        x <= x + 1; 
        $display("%0d: rule incx; new x = %0d", cycle, x+1); 
    endrule

    rule incy; 
        y <= y + 1; 
        $display("%0d: rule incy; new y = %0d", cycle, y+1); 
    endrule

    method ActionValue#(int) avx(); 
        $display("%0d: method avx; setting x to 42; returning old x = %0d", cycle, x); 
        x <= 42; 
        return x; 
    endmethod

    method int vy(); 
        return y; 
    endmethod

    method Action ay(); 
        $display("0d: method ay; setting y to 42", cycle); 
        y <= 42; 
    endmethod

    method int get_cycle_count(); 
        return cycle; 
    endmethod
endmodule



(* synthesize *)
module mkTb(Empty); 

    Foo_ifc foo <- mkFoo; 

    let cycle = foo.get_cycle_count(); 

    rule rAVX; 
        let x <- foo.avx(); 
        $display("%0d: rule rAVX, x = %0d", cycle, x); 
    endrule

    rule rAY; 
        $display("%0d: rule rAY", cycle); 
        foo.ay(); 
    endrule

    rule rVY; 
        let y = foo.vy(); 
        $display("%0d: rule rVY, y = %0d", cycle, y); 
    endrule

endmodule: mkTb

endpackage: Tb