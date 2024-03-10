package Tb; 

(* synthesize *)
module mkTb (Empty); 

Dut_ifc dut <- mkDut; 

rule r1; 
    int w <- dut.avmeth(10); 
    $display(" w = %0d", w); 
    if(w > 50) $finish(0); 
endrule

endmodule 

//------------------------------------------------------------


interface Dut_ifc; 
    method ActionValue#(int) avmeth (int v); 
endinterface

(* synthesize *)
module mkDut(Dut_ifc); 

    Reg#(int) x <- mkReg(0); 

    method ActionValue#(int) avmeth (int v); 
        x <= x + v; 
        return x; 
    endmethod

endmodule

endpackage: Tb