
//2.1

module mkSomeCounter(Empty); 
    Reg#(UInt#(16)) cnt <- mkReg(0); //<- 

    rule increment; 
        cnt <= cnt + 1; // <=
        $display("%d\n", cnt); 
    endrule
endmodule



//2.2


package HelloBluespec; 
    module mkHelloBluespec(Empty); // darf nicht Empty sein, da Methode implementiert wurde
        Reg#(UInt#(32)) flag <- mkReg(24); 

        method ActionValue#(Int#(8)) foo(int x); 

        endmethod
    endmodule
endpackage


//2.3

module mkExample(Empty); 
    Reg#(int) x <- mkReg(5); 

    (* execution_order = "write, read"*)
    rule read; 
        $display("%d\n", x); 
    endrule
                            // laut der execution_order wird erst geschrieben und dann gelesen was der präzedenzrelatino wiederspricht
    rule write; 
        x <= x * -1; 
    endrule
endmodule