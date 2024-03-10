package Tb; 

(* synthesize *)
module mkTb (Empty); 

function td nop( td i );
   return i;
endfunction
function Bool equal( td i, td j ) provisos( Eq#(td) );
   return ( i == j );
endfunction
function td add2x( td i, td j ) provisos( Arith#(td) );
   return ( i + 2*j );
endfunction
function Bool i2xj( td i, td j ) provisos( Arith#(td), Eq#(td) );
   return ( (i - 2*j) == 0 );
endfunction
function Bool isBlock( td i ) provisos(Bits#(td,szTD));
   return (pack(i) & 3) == 0;
endfunction
function Bool isBlock2( td i ) provisos(Bits#(td,szTD),
                                        Add#(2,unused,szTD));  // 2 + unused == szTD
   return (pack(i) & 3) == 0;
endfunction
function Bool isMod3( td i ) provisos(Arith#(td),
                                      Eq#(td),
                                      Add#(4,unused,SizeOf#(td)));
   return (i % 3) == 0;
endfunction
////////////////////////////////////////
rule show;
   $display(" nop is ", nop(10));
   Bit#(10) v1 = 2;
   $display(" equal %x %x ", equal(v1,v1), equal(v1,~v1));
   Bit#(8) v2 = 2;
   Bit#(8) v3 = 8;
   $display(" add2x = %x", add2x(v2,v3));
   $display(" i2xj  = %x", i2xj(v2,v3));
   $display(" isBlock = %x", isBlock(v2));
   $display(" isBlock2 = %x", isBlock2(v2));

      // if you try to compile these two lines
      //   Bit#(2) v4 = 1;
      //   $display(" isMod3   = %x", isMod3(v4));
      // you get a compiler error, as the size of v4 is too small
      // to match the required provisos..
      $finish;
   endrule

endmodule

endpackage 