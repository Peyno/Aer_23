package AXILiteLite_R;

import GetPut :: *;

typedef Bit#(32) Data;

typedef enum {
	IDLE,
	TRANSFER,
	WAIT
} States deriving(Bits, Eq, FShow);

(* always_ready, always_enabled *)
interface AXILiteLiteSlaveR_Fab;
	method Bool rvalid;
	method Action rready(Bool ready);
	method Data rdata();
endinterface

interface AXILiteLiteSlaveR;
	interface AXILiteLiteSlaveR_Fab fab;
	interface Put#(Data) read_data;
endinterface

module mkAXILiteLiteSlaveR(AXILiteLiteSlaveR);
	Reg#(Bool) validOut[2] <- mkCReg(2, False);
	Reg#(Data) dataOut[2] <- mkCReg(2, 0);
	Wire#(Bool) readyIn;


endmodule

endpackage