package Tb; 
import StmtFSM::*; 

module mkTest(Empty); 

    Reg#(Bit#(32)) a <- mkReg(-5); 
    Reg#(Int#(42)) b <- mkReg(5); 

    Stmt fsm1 = {
        seq
            $display("Test unpack(expect())"); 
            $display("Wert a : %b", a); 
            $display("Wert b : %b", b); 

          //  b <= extend(unpack(a)); 
            b <= unpack(extend(a)); 
            $display("Wert b : %b",b ); 

            $finish(); 


        endseq
    };
    

    Stmt fsm2 = {
        seq
            $display("Test expect(unpack())"); 
            $display("Wert a : %b", a); 
            $display("Wert b : %b", b); 

          //  b <= extend(unpack(a)); 
            b <= extend(unpack(a)); 
            $display("Wert b : %b",b ); 

            $finish(); 


        endseq
    };

    mkAutoFSM(fsm1); 
    mkAutoFSM(fsm2); 
 
endmodule


endpackage