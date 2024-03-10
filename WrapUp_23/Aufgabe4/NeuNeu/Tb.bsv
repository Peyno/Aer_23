package Tb; 
import StmtFSM::*; 
import Vector::*; 

interface Stack; 
    method Action push(Int#(32) value); 
    method ActionValue#(Int#(32)) pop(); 
    method Int#(32) peek(); 
endinterface

module mkStack(Stack); 
    Reg#(Int#(32)) index <- mkReg(0); 
    Reg#(Vector#(5, Int#(32))) stack <- mkRegU; 

    method Action push(Int#(32) value) if(index < 5); 
        stack[index] <= value; 
        index <= index + 1; 
    endmethod

    method ActionValue#(Int#(32)) pop() if(index > 0); 
        index <= index - 1; 
        return stack[index - 1]; 
    endmethod

    method Int#(32) peek() if (index > 0); 
        return stack[index - 1]; 
    endmethod

endmodule


module mkTB(Empty); 
    Stack s <- mkStack(); 
    Reg#(int) count <- mkReg(0); 

    Stmt st = seq

            for(count <= 0; count < 5; count <= count + 1)seq
                s.push(count); 
                $display("%d", s.peek()); 
            endseq

        endseq; 
        mkAutoFSM(st); 
endmodule

endpackage