package CacheWrapper;

import BRAM :: *;

import AXILiteLiteSlave :: *;
import AXILiteLite_B :: *;
import CacheCtrl :: *;
import Cache :: *;

interface CacheWrapper;
	interface AXILiteLiteSlave_Fab axi_toCPU;
	interface BRAMClient#(Address, Data) toMem;
endinterface

(*synthesize*)
module mkCacheWrapper(CacheWrapper);
	
endmodule

endpackage