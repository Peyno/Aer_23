package Tb; 

(* synthesize *)
module mkTb (Empty); 
    Dut_ifc dut <- mkDut; 

    rule r1; 
        let x1 = dut.f1; 
        $display("x1 = %0d", x1); 
        if(x1 > 10) $finish(0); 
    endrule

    rule r2; 
        let x2 = dut.f2; 
        $display(" x2 = %0d", x2); 
        if(x2 > 10) $finish(0); 
    endrule

endmodule

interface Dut_ifc; 
    method int f1(); 
    method int f2(); 
endinterface

(* synthesize *)
module mkDut (Dut_ifc); 

    Reg#(int) x <- mkReg(0); 

    rule count; 
        x <= x + 1; 
    endrule

    method int f1(); 
        return x; 
    endmethod

    method int f2() if(is_even(x)); 
        return x; 
    endmethod

endmodule

function Bool is_even(int v); 
    return ((pack(v)) [0] == 0); 
endfunction

endpackage: Tb