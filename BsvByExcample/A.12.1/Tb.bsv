package Tb; 

(* synthesize *)
module mkTb(Empty); 
    UInt#(16) arr[16]; 

    for(Integer i=0; i<10; i=i+1)
        arr[i] = fromInteger(i*3); 

    UInt#(16) arr2[3][4]; 

    for(Integer i=0; i<3; i=i+1)
        for(Integer j=0; j<4; j=j+1)
            arr2[i][j] = fromInteger((i*4) + j); 
    
    Reg#(int) arr3[4]; 
    for(Integer i=0; i<4; i=i+1)
        arr3[i] <- mkRegU; 

    rule load_arr3; 
        arr3[0] <= 'h10; 
        arr3[1] <= 4; 
        arr3[2] <= 1; 
        arr3[3] <= 0;
    endrule

    rule display_arr3; 
        for(Integer i=0; i<4; i=i+1)
            $display("arr3[i] = %x", arr3[i]); 
        $finish;
    endrule
endmodule: mkTb

endpackage: Tb
