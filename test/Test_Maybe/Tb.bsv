package Tb; 

module mkTest(); 

    Reg#(Maybe#(int)) b <- mkRegU; 
    Reg#(Bool) bool <- mkReg(True); 


    (* execution_order = "r1, foo" *)
    rule r1; 
        if(bool)
             b <= tagged Valid (1); 
        else
            b <= tagged Invalid; 
    endrule


   

    rule foo(b matches tagged Invalid ); 
        $display("42!");  
    endrule

endmodule

endpackage : Tb