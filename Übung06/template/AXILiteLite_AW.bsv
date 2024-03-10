package AXILiteLite_AW;

import GetPut :: *;

typedef Bit#(32) Address;

(* always_ready, always_enabled *)
interface AXILiteLiteSlaveAW_Fab;
	method Bool awready;
	method Action awvalid(Bool valid);
	method Action awaddr(Address addr);
endinterface

interface AXILiteLiteSlaveAW;
	interface AXILiteLiteSlaveAW_Fab fab;
	interface Get#(Address) addr;
endinterface

module mkAXILiteLiteSlaveAW(AXILiteLiteSlaveAW);
	Wire#(Bool) validIn;
	Wire#(Address) addrIn;


endmodule

endpackage