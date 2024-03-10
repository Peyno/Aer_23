package AXILiteLite_W;

import GetPut :: *;

typedef Bit#(32) Data;

(* always_ready, always_enabled *)
interface AXILiteLiteSlaveW_Fab;
	method Bool wready;
	method Action wvalid(Bool valid);
	method Action wdata(Data data);
endinterface

interface AXILiteLiteSlaveW;
	interface AXILiteLiteSlaveW_Fab fab;
	interface Get#(Data) data;
endinterface

module mkAXILiteLiteSlaveW(AXILiteLiteSlaveW);
	Wire#(Bool) validIn;
	Wire#(Data) dataIn;


endmodule

endpackage