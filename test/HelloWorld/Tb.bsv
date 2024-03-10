package Tb; 

module mkTb (Empty); 

    rule greet; 
        $display("Hello World Hello"); 
        $finish(0); 
    endrule

endmodule: mkTb

endpackage: Tb