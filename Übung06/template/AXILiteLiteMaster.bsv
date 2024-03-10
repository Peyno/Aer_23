package AXILiteLiteMaster;

import GetPut :: *;
import ClientServer :: *;
import FIFO :: *;
import FIFOF :: *;
import Clocks :: *;
import SpecialFIFOs :: *;
import Connectable :: *;

import AXILiteLiteSlave :: *;
import AXILiteLite_AR :: *;
import AXILiteLite_AW :: *;
import AXILiteLite_B :: *;
import AXILiteLite_R :: *;
import AXILiteLite_W :: *;

/*
========================
	Helper Functions
========================
*/

function Action axilitelite_write(AXILiteLiteMaster m, Bit#(32) addr, Bit#(32) data);
    action
        m.wr.request.put(tuple2(addr, data));
    endaction
endfunction

function Action axilitelite_read(AXILiteLiteMaster m, Bit#(32) addr);
    action
        m.rd.request.put(addr);
    endaction
endfunction

/*
========================
	Module
========================
*/

interface AXILiteLiteMaster;
	interface AXILiteLiteMaster_Fab fab;

	interface Server#(Bit#(32), Bit#(32)) rd;
	interface Server#(Tuple2#(Bit#(32), Bit#(32)), AXILiteLiteResponse) wr;
endinterface

(*synthesize*)
module mkAXILiteLiteMaster(AXILiteLiteMaster);
	let isRst <- isResetAsserted;

	FIFOF#(Bit#(32)) rd_in <- mkFIFOF;
	FIFOF#(Bit#(32)) rd_out <- mkFIFOF;
	FIFOF#(Tuple2#(Bit#(32), Bit#(32))) wr_in <- mkFIFOF;
	FIFOF#(AXILiteLiteResponse) wr_out <- mkFIFOF;

	Wire#(Bool) arreadyIn <- mkBypassWire();
	Wire#(Bit#(32)) araddrOut <- mkDWire(unpack(0));

	rule deqIn if(!isRst && arreadyIn && rd_in.notEmpty());
		rd_in.deq();
	endrule

	rule forwardIn;
		araddrOut <= rd_in.first();
	endrule

	Wire#(Bool) rvalidIn <- mkBypassWire();
	Wire#(Bit#(32)) rdataIn <- mkBypassWire();

	rule enqOut if(!isRst && rvalidIn && rd_out.notFull());
		rd_out.enq(rdataIn);
	endrule

	FIFOF#(Bit#(32)) addrOut <- mkBypassFIFOF();
	FIFOF#(Bit#(32)) dataOut <- mkBypassFIFOF();

	rule splitAddrData;
		match {.addr, .data} = wr_in.first(); wr_in.deq();
		addrOut.enq(addr);
		dataOut.enq(data);
	endrule

	Wire#(Bool) awreadyIn <- mkBypassWire();
	Wire#(Bit#(32)) awaddrOut <- mkDWire(0);

	rule deqAddr if(!isRst && awreadyIn && addrOut.notEmpty());
		addrOut.deq();
	endrule

	rule forwardAddr;
		awaddrOut <= addrOut.first();
	endrule

	Wire#(Bool) wreadyIn <- mkBypassWire();
	Wire#(Bit#(32)) wdataOut <- mkDWire(0);

	rule deqData if(!isRst && wreadyIn && dataOut.notEmpty());
		dataOut.deq();
	endrule

	rule forwardData;
		wdataOut <= dataOut.first();
	endrule

	Wire#(Bool) bvalidIn <- mkBypassWire();
	Wire#(AXILiteLiteResponse) brespIn <- mkBypassWire;

	rule forwardResp if(!isRst && bvalidIn && wr_out.notFull);
		wr_out.enq(brespIn);
	endrule

	interface rd = toGPServer(rd_in, rd_out);
	interface wr = toGPServer(wr_in, wr_out);

	interface AXILiteLiteMaster_Fab fab;
		interface AXILiteLiteMasterAR_Fab ar;
		  	method arready = arreadyIn._write;
			method arvalid = !isRst && rd_in.notEmpty();
	  		method araddr = araddrOut;
		endinterface

		interface AXILiteLiteMasterR_Fab r;
	  		method rready = !isRst && rd_out.notFull();
	  		method rvalid = rvalidIn._write;
	  		method rdata = rdataIn._write;
		endinterface

		interface AXILiteLiteMasterAW_Fab aw;
			method awready = awreadyIn._write();
			method awvalid = !isRst && addrOut.notEmpty();
			method awaddr = awaddrOut;
		endinterface

		interface AXILiteLiteMasterW_Fab w;
			method wready = wreadyIn._write;
			method wvalid = !isRst && dataOut.notEmpty();
			method wdata = wdataOut;
		endinterface

		interface AXILiteLiteMasterB_Fab b;
			method bvalid = bvalidIn._write;
			method bready = !isRst && wr_out.notFull;
			method bresp = brespIn._write;
		endinterface
	endinterface
endmodule


/*
========================
		Interfaces
========================
*/

interface AXILiteLiteMasterAR_Fab;
	method Bool arvalid;
	method Action arready(Bool ready);
	method Bit#(32) araddr;
endinterface

interface AXILiteLiteMasterR_Fab;
	method Bool rready;
	method Action rvalid(Bool valid);
	method Action rdata(Bit#(32) d);
endinterface

interface AXILiteLiteMasterAW_Fab;
	method Action awready(Bool ready);
	method Bool awvalid;
	method Bit#(32) awaddr;
endinterface

interface AXILiteLiteMasterW_Fab;
	method Action wready(Bool ready);
	method Bool wvalid;
	method Bit#(32) wdata;
endinterface

interface AXILiteLiteMasterB_Fab;
	method Action bvalid(Bool b);
	method Bool bready;
	method Action bresp(AXILiteLiteResponse r);
endinterface


(* always_ready, always_enabled *)
interface AXILiteLiteMaster_Fab;
	interface AXILiteLiteMasterAR_Fab ar;
	interface AXILiteLiteMasterR_Fab r;
	interface AXILiteLiteMasterAW_Fab aw;
	interface AXILiteLiteMasterW_Fab w;
	interface AXILiteLiteMasterB_Fab b;
endinterface


/*
========================
		Connectables
========================
*/

instance Connectable#(AXILiteLiteMaster_Fab, AXILiteLiteSlave_Fab);
	module mkConnection#(AXILiteLiteMaster_Fab master, AXILiteLiteSlave_Fab slave)(Empty);
		// AW
		rule forward1; master.aw.awready(slave.aw.awready); endrule
		rule forward2; slave.aw.awvalid(master.aw.awvalid); endrule
		rule forward3; slave.aw.awaddr(master.aw.awaddr); endrule
		// W
		rule forward5; master.w.wready(slave.w.wready); endrule
		rule forward6; slave.w.wvalid(master.w.wvalid); endrule
		rule forward7; slave.w.wdata(master.w.wdata); endrule
		// B
		rule forward9; master.b.bvalid(slave.b.bvalid); endrule
		rule forward10; slave.b.bready(master.b.bready); endrule
		rule forward11; master.b.bresp(slave.b.bresp); endrule
		// AR
		rule forward12; slave.ar.arvalid(master.ar.arvalid); endrule
		rule forward13; master.ar.arready(slave.ar.arready); endrule
		rule forward14; slave.ar.araddr(master.ar.araddr); endrule
		// R
		rule forward15; slave.r.rready(master.r.rready); endrule
		rule forward16; master.r.rvalid(slave.r.rvalid); endrule
		rule forward17; master.r.rdata(slave.r.rdata); endrule
	endmodule
endinstance

instance Connectable#(AXILiteLiteSlave_Fab, AXILiteLiteMaster_Fab);
	module mkConnection#(AXILiteLiteSlave_Fab slave, AXILiteLiteMaster_Fab master)(Empty);
		mkConnection(master, slave);
	endmodule
endinstance

endpackage