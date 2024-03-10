package Tb; 

(* synthesize *)
module mkTb(Empty); 
    Reg#(int) step <- mkReg(0); 

    rule init(step == 0); 
        $display("== step 0 =="); 
        
        Tuple2#(Bool, int) foo = tuple2(True, 25); 

        Bool field1 = tpl_1(foo); 
        int field2 = tpl_2(foo); 

        foo = tuple2(!field1, field2); 

        $display("tpl_1(foo) = ", tpl_1(foo)); 
        $display("tpl_2(foo) = ", tpl_2(foo));

        step <= step +1; 
    endrule

    rule step1(step == 1); 
        $display("=== 1 ==="); 

        Tuple4#(Bool, UInt#(4), Int#(8), Bit#(12)) bar = tuple4(True, 0, -2, 5); 

        $display("tpl_1(bar) = ", tpl_1(bar)); 
        $display("tpl_2(bar) = ", tpl_2(bar)); 
        $display("tpl_3(bar) = ", tpl_3(bar)); 
        $display("tpl_4(bar) = ", tpl_4(bar)); 

        step <= step +1; 
    endrule

    rule step2 (step == 2); 
        $display("=== step 2 ==="); 
        $display("All done"); 
        $finish(0); 
    endrule
endmodule

endpackage