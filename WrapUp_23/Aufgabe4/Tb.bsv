package Tb; 
import Vector::*; 
import StmtFSM::*; 

interface Stack; 
    method Action push(Int#(32) value); 
    method ActionValue#(Int#(32)) pop();
    method Int#(32) peek(); 
endinterface

module mkStack(Stack); 
    Reg#(Vector#(5, Int#(32))) stack <- mkRegU; //replicateM
    Reg#(Int#(32)) index <- mkReg(0); 

    method Action push(Int#(32) value) if(index < 5); 
        stack[index] <= value; 
        index <= index + 1; 
    endmethod

    method ActionValue#(Int#(32)) pop() if (index > 0); 
        index <= index - 1; 
        return stack[index - 1]; 
    endmethod

    method Int#(32) peek() if(index > 0); 
        return stack[index - 1]; 
    endmethod

endmodule

module mkTb(Empty); 

    Stack s <- mkStack(); 
    Reg#(Int#(32)) wert <- mkReg(0); 

    rule push;
        wert <= wert + 1; 
        s.push(wert);  

    endrule

    rule peek; 
        let x = s.peek(); 
        $display("Oberster Wert im Stack = %d", x); 
    endrule

    rule finish (wert > 4); 
        $finish(0); 
    endrule

endmodule

module mkTb2(Empty); 
Reg#(int) i <- mkReg(0); 
    Stack s <- mkStack(); 

    Stmt f = seq

        for(i <= 0; i < 6; i <= i + 1)seq
           
            s.push(i); 
            $display("Wert oben = %d", s.peek()); 
           
        

        endseq
         $finish(0);
    endseq;

    mkAutoFSM(f); 

endmodule


endpackage