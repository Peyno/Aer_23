package Tb; 

    (* synthesize *)
    module mkTb(Empty); 
        Integer inx = 0; 

        Bool arr1[4]; 
        arr1[inx] = True; 
        
        inx = inx + 1; 
        arr1[inx] = False; 

        inx = inx + 1; 
        arr1[inx] = True; 
        
        inx = inx + 1; 
        arr1[inx] = True; 

        int arr2[16]; 
        for(Integer i = 0; i<16; i=i+1)
            arr2[i] = fromInteger(i); 

        Integer foo = 10; 
        foo = foo +1; 
        foo = foo * 5; 
        Bit#(16) var1 = fromInteger(foo); 

        ////////////////////////////////////////////////////////////////////
        Reg#(int) step <- mkReg(0); 
        
        rule init(step == 0);   
            $display("=== step 0 ==="); 

            Integer x = 10 ** 10000; 
            Bool isLarge = (x > 0); 
            $display("isLarge = ", isLarge); 

            // uncomment this and see the big number created, causing a error :)
            //$display("Large number = ", x);

            step <= step + 1; 
        endrule

        rule step1 (step == 1); 
            $display("=== step 1 ==="); 

            for(Integer i=1; i <16; i=i*2)
                $display("i is ", i); 

            step <= step + 1; 
        endrule

        rule step2( step == 2);     
            $display("All done"); 
            $finish(0); 
        endrule

    endmodule: mkTb

endpackage: Tb