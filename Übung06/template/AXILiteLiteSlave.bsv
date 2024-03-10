package AXILiteLiteSlave;

import GetPut :: *;
import ClientServer :: *;

import AXILiteLite_AW :: *;
import AXILiteLite_W :: *;
import AXILiteLite_B :: *;
import AXILiteLite_AR :: *;
import AXILiteLite_R :: *;


(* always_ready, always_enabled *)
interface AXILiteLiteSlave_Fab;
	interface AXILiteLiteSlaveAR_Fab ar;
	interface AXILiteLiteSlaveR_Fab r;
	interface AXILiteLiteSlaveAW_Fab aw;
	interface AXILiteLiteSlaveW_Fab w;
	interface AXILiteLiteSlaveB_Fab b;
endinterface

interface AXILiteLiteSlave;
	interface AXILiteLiteSlave_Fab fab;

	interface Client#(Address, Data) rd;
	interface Client#(Tuple2#(Address, Data), AXILiteLiteResponse) wr;
endinterface

module mkAXILiteLiteSlave(AXILiteLiteSlave);
	
endmodule


endpackage