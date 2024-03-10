package Tb; 

typedef union tagged {
    UInt#(32) Unsigned; 
    Int#(32) Signed; 
} SignedOrUnsigned deriving (Eq, Bits); 

interface TU_Pipeline; 
    interface CalcUnit calc; 
    method Action setParam(UInt#(2) addr, SignedOrUnsigned val); 
endinterface

interface CalcUnit; 
    method Action put(SignedOrUnsigned x); 
    method ActionValue#(SignedOrUnsigned) result(); 
endinterface

interface CalcUnitChangeable; 
    interface CalcUnit calc; 
    method Action setParameter(SignedOrUnsigned param); 
endinterface

module mkAddA(CalcUnitChangeable); 
    Reg#(SignedOrUnsigned) a <- mkRegU; 
    Wire#(SignedOrUnsigned) in <- mkWire; 
    Wire#(SignedOrUnsigned) out <- mkWire; 

    rule computerSigned (a matches tagged Signed .sa &&&
                            in matches tagged Signed .sin); 
        out <= tagged Signed(sa + sin); 
    endrule

    rule computeUnsigned(a matches tagged Unsigned .usa &&&
                            in matches tagged Unsigned .usin); 
        out <= tagged Unsigned (usa + usin); 
    endrule

    rule crash(pack(in)[32] != pack(a)[32]); 
        $display("ERROR: mkAddA got wrong input!"); 
        $display("Tag a: %b, Tag in : %b", pack(a)[32], pack(in[32])); 
        $finish(); 
    endrule

    method Action setParameter(SignedOrUnsigned param); 
        a <= param; 
    endmethod

    interface CalcUnit calc; 
        method Action put (SignedOrUnsigned x); 
            in <= x; 
        endmethod

        method ActionValue#(SignedOrUnsigned) result(); 
            noAction; 
            return out; 
        endmethod
    endinterface
endmodule



endpackage