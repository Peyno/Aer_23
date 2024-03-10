package Tb; 
import Vector::*; 
import FIFO::*; 

(* synthesize *)
module mkTb(Empty); 
    Int#(16) arr1[4]; 
    for(Integer i=0; i<4; i=i+1)
        arr1[i] = 0; 

    Vector#(4, Int#(16)) vec1 = newVector; 
    Vector#(4, Int#(16)) vec2 = replicate(0); 

    Int#(16) arr2a[4]; 
    for(Integer i=0; i<4; i=i+1)
        arr2a[i] = 0; 

    Vector#(4, Int#(16)) vec3 = map (fromInteger, genVector); 

    Int#(16) arr3a[4]; 
    for(Integer i=0; i<4; i=i+1)
        arr3a[i] = fromInteger(i); 

    function Int#(16) vec3init(Integer i); 
        return fromInteger(i*13); 
    endfunction 

    Vector#(4, Int#(16)) vec4 = map(vec3init, genVector); 
    
    Int#(16) arr4a[4]; 

    for(Integer i=0; i<4; i=i+1)
        arr4a[i] = fromInteger(i*13); 

    rule displayArray; 
        for(Integer i=0; i<4; i=i+1)
            $display("arr1[i] = %x", arr1[i]); 
    endrule

    rule displayVec2; 
        for(Integer i=0; i<4; i=i+1)
            $display("vec2[i] = %x", vec2[i]); 
    endrule

    rule displayVec3; 
        for(Integer i=0; i<4; i=i+1)
            $display("vec3[i] = %d", vec3[i]); 
    endrule

    rule displayVec4; 
        for(Integer i=0; i<4; i=i+1)
            $display("vec[i] = %d", vec4[i]); 
    endrule

endmodule: mkTb

endpackage: Tb