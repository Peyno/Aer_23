package Tb; 

(* synthesize *)
module mkTb(Empty); 
    Reg#(Bit#(8)) foo <- mkReg(0); 
    Reg#(Bit#(8)) foo2 <- mkReg(0); 

    (* preempts = "up1, up2" *)

    rule up1;
        $display("foo[1:0] = %b", foo[1:0]); 
        $display("foo[2] = %b", foo[2]); 

        foo[1] <=1; 

        let tmp = foo2; 
        tmp[1] = 1; 
        tmp[3] = 1; 
        tmp[7:6] = 3; 
        foo2 <= tmp; 
    endrule

    rule up2; 
        foo[2] <= 1; 
    endrule

    Reg#(bit) b1 <- mkReg(0); 
    Reg#(bit) b2 <- mkReg(0); 

    rule up3; 
        b1 <= 1; 
        b2 <= 1; 
    endrule

    rule done (b2 == 1); 
        $display("b12 = %b", {b1,b2}); 
        $finish; 
    endrule

endmodule
endpackage