package Test_1; 

module mkTest(Empty); 

    Reg#(UInt#(32)) b <- mkReg(42); 
    Reg#(Bool) bool <- mkReg(False); 

    rule r1; 
        if(bool)$display("%h at time : %d", b, $time); 
        bool <= !bool; 
    endrule

   


endmodule

endpackage