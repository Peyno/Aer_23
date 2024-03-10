package Tb; 
import Vector::*; 
import StmtFSM::*; 


interface Stack; 
    method Action push(Int#(32) value); 
    method ActionValue#(Int#(32)) pop(); 
    method Int#(32) peek(); 
endinterface

module mkStack(Stack); 

    Reg#(Vector#(5, Int#(32))) stack <- mkRegU(); 
    Reg#(Int#(32)) index <- mkReg(0); 

    method Action push(Int#(32) value) if(index < 5); 
        stack[index] <= value; 
        index <= index + 1; 
    endmethod

    method ActionValue#(Int#(32)) pop() if(index > 0 ); 
        index <= index - 1; 
        return stack[index - 1];

    endmethod

    method Int#(32) peek() if(index > 0 ); 
        return stack[index - 1]; 
    endmethod


endmodule


module mkTB(Empty); 

    Stack dut <- mkStack(); 
    Reg#(Int#(32)) i <- mkReg(0); 

    Stmt s = seq
        for( i <= 0; i < 6; i <= i + 1 )seq
            dut.push(i); 
            $display("Wert oben : %d", dut.peek); 
        endseq

    endseq;
    mkAutoFSM(s); 



endmodule


endpackage