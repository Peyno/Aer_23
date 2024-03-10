package Tb; 
import GetPut::*;

module mkSomeCalcr(Put#(UInt#(32)));

endmodule

module mksomeProducer(Get#(UInt#(32))); 

endmodule



module mkCombiner(Empty);
  
    Put#(UInt#(32)) calc <- mkScomeCalc(); 
    Get#(UInt#(32)) prod <- mkSomeProducer(); 


    mkConnection(prod, clac); 
endmodule




endpackage