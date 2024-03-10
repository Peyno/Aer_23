package Tb; 

(* synthesize *)
module mkTb(Empty); 

    Reg#(Bit#(3)) x <- mkReg(1); 

    Reg#(int) cycle <- mkReg(0); 

    Reg#(int) y <- mkReg(0); 

    rule rx; 
        cycle <= cycle + 1; 
        x <= {x[1:0], x[2]}; 
        $display("%0d: Rule rx", cycle); 
    endrule

     (* conflict_free = "ry0, ry1, ry2" *) // XXX

    rule ry0; 
        if(x[0] == 1) y <= y + 2; 
        $display("%0d: Rule ry0", cycle); 
    endrule

    rule ry1; 
        if (x[1] == 1) y <= y + 2; 
        $display("%0d: Rule ry2", cycle); 
    endrule

    rule ry2;
        if(x[2] == 1) y <= y + 3; 
        $display("%0d: Rule ry2", cycle); 
    endrule

    rule done; 
        if(cycle >= 10) $finish(0); 
    endrule

endmodule: mkTb

endpackage: Tb