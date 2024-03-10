package Tb; 

(* synthesize *)
module mkTb (Empty); 

    Reg#(int) x <- mkReg(0); 
    Reg#(int) y <- mkReg(0); 

    function Action incr_both (int dx, int dy); 
        return 
            action 
                    x <= x + dx; 
                    y <= y + dy; 
            endaction;
    endfunction

    rule r1 (x <= y); 
        incr_both(5, 1); 
        $display("(x, y) = (%0d, %0d); r1 fires", x,y); 
        if(x > 30) $finish(0); 
    endrule

    rule r2 (x > y); 
        incr_both (1,4); 
        $display("(x, y) = (%0d, %0d): r2 fires", x, y); 
    endrule

endmodule

endpackage: Tb
