package CalcUnits; 

typedef union tagged{
    UInt#(32) Unsigned; 
    Int#(32) Signed; 
} SignedOrUnsigned deriving (Eq, Bits); 

interface CalcUnit; 
    method Action put(SignedOrUnsigned x); 
    method ActionValue#(SignedOrUnsigned) result(); 
endinterface

interface CalcUnitChangeable; 
    interface CalcUnit calc; 
    method Action setParameter(SignedOrUnsigned param); 
endinterface

module mkAdd(CalcUnitChangeable); 
    Reg#(SignedOrUnsigned) a <- mkRegU; 
    Wire#(SignedOrUnsigned) in <- mkWire; 
    Wire#(SignedOrUnsigned) out <- mkWire; 
    
    //Rules
    rule computeSigned(a matches tagged Signed .sa &&&
                         in matches tagged Signed .sin); 
        out <= tagged Signed(sa + sin); 
    endrule
    
    rule computeUnsigned(a matches tagged Unsigned .usa &&& 
                            in matches tagged Unsigned .usin); 
        out <= tagged Unsigned (usa + usin); 
    endrule

    rule crash(pack(in)[32] != pack(a)[32]); // if we put an unfitting value we crash
        $display("ERROR: mkAddA got wrong input!"); 
        $display("Tag a: %b, Tag in : %b", pack(a)[32], pack(in)[32]); 
        $finish(); 
    endrule

    // Interface Definintion 
    method Action setParameter(SignedOrUnsigned param); 
        a <= param; 
    endmethod

    interface CalcUnit calc; 
        method Action put(SignedOrUnsigned x); 
            in <= x; 
        endmethod

        method ActionValue#(SignedOrUnsigned) result(); 
            noAction; 
            return out; 
        endmethod
    endinterface
endmodule

module mkMul(CalcUnitChangeable); 
    Reg#(SignedOrUnsigned) b <- mkRegU; //or c
    Wire#(SignedOrUnsigned) in <- mkWire; 
    Wire#(SignedOrUnsigned) out <- mkWire; 

    //Rules
    rule computeSigned(b matches tagged Signed .sb &&&
                         in matches tagged Signed .sin); 
        out <= tagged Signed(sb * sin); 
    endrule
    
    rule computeUnsigned(b matches tagged Unsigned .usb &&& 
                            in matches tagged Unsigned .usin); 
        out <= tagged Unsigned (usb * usin); 
    endrule

    rule crash(pack(in)[32] != pack(a)[32]); // if we put an unfitting value we crash
        $display("ERROR: mkAddA got wrong input!"); 
        $display("Tag a: %b, Tag in : %b", pack(a)[32], pack(in)[32]); 
        $finish(); 
    endrule

    //Interface Definition 
    method Action setParameter(SignedOrUnsigned param); 
        b <= param; 
    endmethod

    interface CalcUnit calc; 
        method Action put(SignedOrUnsigned x); 
            in <= x; 
        endmethod

        method ActionValue#(SignedOrUnsigned)result(); 
            noAction; 
            return out; 
        endmethod
    endinterface
endmodule

module mkDiv4(CalcUnit); 
    Wire#(SignedOrUnsigned) in <- mkWire; 

    method Action put(SignedOrUnsigned); 
        in <= x; 
    endmethod

    method ActionValue#(SignedOrUnsigned) result(); 
        noAction; 
        case(in) matches
            tagged Unsigned .usin: return tagged Unsigned (usin / 4); 
            tagged Signed .sin : return tagged Signed (sin / 4); 
        endcase
    endmethod
endmodule

module mkAdd128(CalcUnit); 
    Wire#(SignedOrUnsigned) in <- mkWire; 

    method Action put(SignedOrUnsigned x); 
        in <= x; 
    endmethod

    method ActionValue#(SignedOrUnsigned) result(); 
        noAction; 
        case(in) matches 
            tagged Unsigned .usin : return tagged Unsigned (usin + 128); 
            tagged Signed .sin : return tagged Signed (sin + 128); 
        endcase
    endmethod
endmodule

endpackage