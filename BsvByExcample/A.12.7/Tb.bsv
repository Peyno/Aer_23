package Tb; 
import Vector::*; 

(* synthesize *)
module mkTb (Empty); 
    Vector#(8, Reg#(int)) arr1 <- replicateM(mkRegU); 
    Reg#(int) step <- mkReg(0); 

    rule init (step == 0); 
        for(Integer i=0; i<8; i=i+1)
            arr1[i] <= fromInteger(i); 
        step <= step + 1; 
    endrule

    rule step1 (step == 1); 
        for(int i=0; i<8; i=i+1)
            arr1[i] <= i; 
        step <= step + 1; 
    endrule

    rule step2 (step == 2); 
        for(int i=0; i<8; i=i+1)
            if(i!=7)
                arr1[i+1] <= arr1[i]; 
            else
                arr1[0] <= arr1[7]; 
        step <= step + 1; 
    endrule

    rule step3 (step ==3 ); 
        for(int i=0; i<8; i=i+1)
            case (i)
                0: arr1[0] <= arr1[3];
                1: arr1[1] <= arr1[1];
                2: arr1[2] <= arr1[2];
                3: arr1[3] <= arr1[0];
                4: arr1[4] <= arr1[5];
                5: arr1[5] <= arr1[7];
                6: arr1[6] <= arr1[4];
                7: arr1[7] <= arr1[6];
            endcase
        step <= step + 1; 
    endrule

    Reg#(UInt#(3)) inx <- mkReg(0); 

    rule step4(step == 4); 
        arr1[inx] <= 0; 
        step <= step + 1; 
    endrule

    rule step5(step == 5); 
        for(Integer i=0; i<8; i=i+1)begin
            int indexVal = unpack(zeroExtend(pack(inx))); 
        end
        step <= step + 1; 
    endrule

    rule step6(step == 6); 
        for(Integer i=1; i<8; i=i+1)
            arr1[i-1] <= arr1[i] + fromInteger(i*3); 
        step <= step + 1; 
    endrule

    rule step7 (step == 7); 
        int acc = 0; 
        for(Integer i=0; i<8; i=i+1)begin
            acc = arr1[i] + acc; 
            arr1[i] <= acc; 
        end

        step <= step + 1; 
    endrule

    rule step8 (step == 8); 
        $display("All done"); 
        $finish(0); 
    endrule

    rule watcher (step > 0); 
        $display("=== step %d ===", step); 
        for(Integer i=0; i<8; i=i+1)
            $display("arr1[%d] = ", i, arr1[i]); 
    endrule
    
endmodule: mkTb
endpackage: Tb