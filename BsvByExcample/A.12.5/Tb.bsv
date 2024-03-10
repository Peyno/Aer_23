package Tb; 
import Vector::*; 

typedef enum{OK, FAIL,  TEST, WAIT} Status deriving(Bits, Eq); 

(* synthesize *)
module mkTb (Empty); 
    Reg#(Vector#(10, Status)) regstatus <- mkReg(replicate(OK)); 
    Vector#(10, Reg#(Status)) vecstatus <- replicateM(mkReg(OK)); 

    Reg#(Maybe#(UInt#(4))) failCond <- mkReg(Invalid); 
    Reg#(UInt#(4)) cycle <- mkReg(0); 

    rule checkChannel; 
        cycle <= cycle + 1; 
        if(cycle == 5)
            failCond <= tagged Valid 5; 
        else
            failCond <= tagged Invalid; 
        $display("cycle = ", cycle); 
        if(cycle > 9)$finish(0); 
    endrule

    rule updateRegStatus(failCond matches tagged Valid .chan); 
        let tempstatus = regstatus; 
        tempstatus[chan] = FAIL; 
        tempstatus[chan + 1] = TEST; 
        regstatus <= tempstatus; 
    endrule

    rule displayReg; 
        for(Integer i=0; i<10; i=i+1)begin
                $display("RegStatus(i)", regstatus[i]); 
                $display("VecStatus(i)", vecstatus[i]); 
        end
    endrule

    rule updateVecStauts (failCond matches tagged Valid .chan); 
        vecstatus[chan] <= FAIL; 
        vecstatus[chan + 1] <= TEST; 
    endrule

endmodule
endpackage