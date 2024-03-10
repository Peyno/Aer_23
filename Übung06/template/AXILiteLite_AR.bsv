package AXILiteLite_AR;

import GetPut :: *;

typedef Bit#(32) Address;

(* always_ready, always_enabled *)
interface AXILiteLiteSlaveAR_Fab;
	method Bool arready;
	method Action arvalid(Bool valid);
	method Action araddr(Address addr);
endinterface

interface AXILiteLiteSlaveAR;
	interface AXILiteLiteSlaveAR_Fab fab;
	interface Get#(Address) addr;
endinterface

module mkAXILiteLiteSlaveAR(AXILiteLiteSlaveAR);
	Wire#(Bool) validIn;
	Wire#(Address) addrIn;


endmodule

endpackage