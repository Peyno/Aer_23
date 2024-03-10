package Aufgabe5; 

typedef Server#(UInt#(32), UInt#(32)) MyFIFO; 


module mkBypassFIFO(MyFIFO); 
    Reg#(Maybe#(UInt#(32))) store[2] <- mkCreg#(2, tagged Invalid); 
    Reg#(Int#(32)) in <- mkFIFO; 
    Reg#(Int#(32)) out <- mkFIFO; 




    interface request = toPut(in); 
    interface response = toGet(out); 




    







endmodule


endpackage