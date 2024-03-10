package hello_world; 

(* synthesize *)
module mkTb (Empty); 
    
    Reg#(int) step <- mkReg(0); 


    rule greet (step == 0); 
        $display("Hello world"); 
      step <= step + 1; 
    endrule


    rule greet2 (step == 1); 
        $display("klsadkfjö"); 
        $finish(0); 
    endrule
endmodule: mkTb

endpackage: hello_world

