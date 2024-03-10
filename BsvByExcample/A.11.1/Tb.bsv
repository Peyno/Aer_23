package Tb; 

(* synthesize *)
module mkTb (Empty); 

    Reg#(int) step <- mkReg(0); 

    rule init (step == 0); 
         $display("=== step 0 ===");
      // for instance.. let’s do the exact example above...
      bit o = 0;
      for (Bit#(2) i=0; i<2; i=i+1)
         for (Bit#(2) j=0; j<2; j=j+1) begin
            bit a = i[0];
            bit b = j[0];
            if ((a==0) && (b==0))
               o = 1;
            else
                o = 0;
            $display("%b%b = %b", a,b,o);
         end
      // this generates the NAND gate we expect and may be more natural
      step <= step + 1;
    endrule

    rule step1 (step == 1); 
        $display("=== step 1 ==="); 

        bit o = 0; 
        for(Bit#(2) i=0; i<2; i=i+1)
            for(Bit#(2) j=0; j<2; j=j+1)begin
                bit a = i[0]; 
                bit b = j[0]; 

                if((a==0) && (b==0))
                    o = 1; 
                else if ((a==1) && (b==1))
                    o = 0; 
                else
                    o = ?; 

                $display("%b%b = %b", a,b,o); 
            end 
        step <= step + 1; 
    endrule

    rule step2 (step == 2); 
        $display("=== step 2 ==="); 

        bit o = 0; 
        for(Bit#(2) i=0; i<2; i=i+1)
            for(Bit#(2) j=0; j<2; j=j+1)begin
                bit a =i[0]; 
                bit b = j[0]; 

                case ({a, b})
                    2'b11: o = 1;  
                    2'b01: o = ?; 
                    2'b10: o = ?; 
                    2'b00: o = 0; 
                endcase

                $display("%b%b = %b", a,b,o); 
            end

        step <= step + 1; 
    endrule

    rule step3 (step == 3); 
        $display("=== step 3 ==="); 

        bit o = 0; 
        for(Bit#(2) i=0; i<2; i=i+1)
            for(Bit#(2) j=0; j<2; j=j+1)begin
                bit a = i[0]; 
                bit b = j[0]; 

                case({a,b})matches
                2'b?1: o = ?; 
                2'b10: o = 1; 
                2'b00: o = 0; 
                endcase

                $display("%b%b = %b", a,b,o); 
            end 
        step <= step + 1; 
    endrule

    rule step4 (step == 4); 
        $display("=== step 4 ==="); 

        $display("All done"); 
        $finish(0); 

    endrule

endmodule: mkTb

endpackage: Tb
