package Tb; 

(* synthesize *)
module mkTb (Empty); 
    Dut_ifc dut <- mkDut; 

    rule r1; 
        int w = dut