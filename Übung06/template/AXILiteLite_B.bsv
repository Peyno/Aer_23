package AXILiteLite_B;

import GetPut :: *;

typedef enum {
	OKAY = 2'b00,
	EXOKAY = 2'b01,
	SLVERR = 2'b10,
	DECERR = 2'b11
} AXILiteLiteResponse deriving(Bits, Eq, FShow);

typedef enum {
	IDLE,
	TRANSFER,
	WAIT
} States deriving(Bits, Eq, FShow);

(* always_ready, always_enabled *)
interface AXILiteLiteSlaveB_Fab;
	method Bool bvalid;
	method Action bready(Bool ready);
	method AXILiteLiteResponse bresp();
endinterface

interface AXILiteLiteSlaveB;
	interface AXILiteLiteSlaveB_Fab fab;
	interface Put#(AXILiteLiteResponse) resp;
endinterface

module mkAXILiteLiteSlaveB(AXILiteLiteSlaveB);
	Reg#(Bool) validOut[2] <- mkCReg(2, False);
	Reg#(AXILiteLiteResponse) respOut[2] <- mkCReg(2, OKAY);
	Wire#(Bool) readyIn;


endmodule

endpackage