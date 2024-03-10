package Tb; 
import SimpleProcessor::*; 

InstructionAddress label_loop = 3; 
InstructionAddress label_subtract = 10; 
InstructionAdress label_done = 12; 
InstructionAdress label_last = 13; 

Instruction code [14] = 
    {
        tagged MovI {rd: R0, v: 0}, 
        tagged MovI {rd: R1, v: 15}, 
        tagged MovI {rd: R2, v: 27}, 

        tagged Brz {rs: R2, dest:label_done}, 
        tagged Gt {rd: R3, rs1: R1, rs2: R2}, 
        tagged Brz {rs: R3, dest: label_subtract}, 

        tagged Minus {rd: R3, rs1: R1, rs2: R0}, 
        tagged Minus {rd: R1, rs1: R2, rs2: R0}, 
        tagged Minus {rd: R2, rs1: R3, rs2: R0}, 
        tagged Br label_loop, 

        tagged Minus {rd: R2, rs1: R2, rs2: R1}, 
        tagged Br label_loop, 

        tagged Output R1, 

        tagged Halt
    }; 

(* synthesize *)
module mkTb (Empty); 
    Reg#(InstrucionAddress) ia <- mkReg(0); 
    SimpleProcessor sp <- mkSimpleProcessor(); 

    rule loadInstrs(ia <= label_last); 
        sp.loadInstruction (ia, code [ia]); 
        ia <= ia +1; 
    endrule

    rule go (ia == label_last + 1); 
        sp.start(); 
        ia <= ia + 1; 
    endrule

    rule windup ((ia > label_last +1) && (sp.halted)); 
        $display("Fyi: size of an Instruction is %0d bits", valueof (SizeOf#(Instruction))); 
        $finish(0); 
    endrule

endmodule: mkTb

endpackage: Tb







