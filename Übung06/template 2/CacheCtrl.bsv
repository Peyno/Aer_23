package CacheCtrl;
    import DefaultValue::*;
    import ClientServer::*;
    import GetPut::*;
    import FIFO::*;
    import BRAM::*;
    import Cache::*;
    import ReplacementStrategy::*;
    import StmtFSM::*;

    typedef struct {
        Address addr;
        Data data;
    } WriteReq deriving (Bits, FShow);

    typedef struct {
        Address addr;
    } ReadReq deriving (Bits, FShow);

    typedef union tagged {
        WriteReq Write;
        ReadReq Read;
    } CtrlReq deriving (Bits, FShow);

    typedef union tagged {
        Data Read;
        Bool Write; // return true on write success
    } CtrlRsp deriving (Bits, FShow);

    interface CacheCtrl;
        interface Server#(CtrlReq, CtrlRsp) toCPU;
        interface BRAMClient#(Address, Data) toMem;
    endinterface

    typedef enum {Idle, Access, WriteBack, Allocate} CtrlState deriving(Bits, Eq);

    module mkCacheCtrl(CacheCtrl);
        FIFO#(CtrlReq) cpu_req <- mkFIFO();
        FIFO#(CtrlRsp) cpu_rsp <- mkFIFO();

        Reg#(CtrlState) state <- mkReg(Idle);
        Reg#(CtrlReq) curr_req <- mkRegU;
        Reg#(DecodedAddress) curr_addr <- mkRegU;

        // Eviction
        Reg#(Way) evicted_way <- mkRegU;
        Reg#(CacheEntry) evicted_entry <- mkRegU;
        Reg#(DecodedAddress) evicted_addr <- mkRegU;
        FIFO#(BRAMRequest#(Address, Data)) toBRAM <- mkFIFO(); // send read/write requests
        FIFO#(Data) fromBRAM <- mkFIFO(); // fetch read/write responses
        Reg#(CacheEntry) line <- mkRegU;    // hold the currently constructed cache block
        Reg#(Address) curr_bram_addr <- mkRegU; // current address inside the cache block
        Reg#(Bit#(TAdd#(WORDS_PER_BLOCK, 1))) bram_rsp_count <- mkRegU; // how often did we get stuff back from BRAM?


        // Cache
        Cache cache <- mkCache();
        
        `ifndef PLRU
        `define PLRU 0
        `endif

        Bool use_plru = unpack(`PLRU);
        ReplacementStrategy replacer;
        if(use_plru) begin
            replacer <- mkPLRU();
        end
        else begin
            replacer <- mkRoundRobin();
        end

        function Action requestFromBRAM(Address a, Bool write, Data d);
            return action
                toBRAM.enq(BRAMRequest{
                    write: write,
                    responseOnWrite: False,
                    address: a,
                    datain: d
                });
            endaction;
        endfunction

        Stmt accessFsmStmt = seq 
            // TODO: task 6.1d
            action 
                DecodedAddress req_addr; 
                CacheReq to_cache; 
                if(curr_req matches tagged Read .rd) begin
                        req_addr = decode(rd.addr); 
                        to_cache = tagged Load req_addr; 
                end
                else begin
                    WriteReq wr = curr_req.Write; 
                    req_addr = decode(wr.addr); 
                    Data req_data = wr.data; 
                    to_cache = tagged Store StoreReq{addr: req_addr, data: req_data}; 
                end
                curr_addr <= req_addr; 
                cache.ls_server.request.put(to_cache); 
            endaction 
            action
                let rsp <- cache.ls_server.response.get(); 
                if(rsp matches tagged Valid .from_cache)begin
                    CtrlRsp ctrl_rsp; 
                    Way accessed_way; 
                    if(from_cache matches tagged LoadResponse .loadresp) begin
                        ctrl_rsp = tagged Read loadresp.data; 
                        accessed_way = loadresp.way; 
                    end
                    else begin 
                        let storeresp = from_cache.StoreResponse; 
                        ctrl_rsp = tagged Write True; 
                        accessed_way = storeresp; 
                    end
                    replacer.updateAccesses(curr_addr.index, accessed_way); 
                    cpu_rsp = tagged Write True; 
                    accessed_way = storeresp; 
                end
                else begin
                    let storeresp = from_cache.StoreResponse; 
                    ctrl_rsp = tagged Write True; 
                    accessed_way = storeresp; 
                end
                re


        endseq;

        FSM accessFSM <- mkFSMWithPred(accessFsmStmt, state == Access);

        function Address computeBlockAddr(DecodedAddress addr);
            // TODO: task 6.1e
            return 0;
        endfunction

        function Address computeEndAddr(DecodedAddress addr);
            let blockstart = computeBlockAddr(addr);
            Address res = blockstart + fromInteger(valueOf(BLOCK_SIZE));
            return res;
        endfunction

        Stmt allocateFsmStmt = seq 
            // TODO: task 6.1e
        endseq;

        FSM allocateFSM <- mkFSMWithPred(allocateFsmStmt, state == Allocate);

        Stmt writebackFsmStmt = seq
            // TODO: task 6.1f
        endseq;

        FSM writebackFSM <- mkFSMWithPred(writebackFsmStmt, state == WriteBack);

        rule idle (state == Idle);
            // TODO: task 6.1c
            curr_req <= cpu_req.first(); 
            cpu_req.deq(); 
            state <= Access; 
        endrule

        rule access;
            // TODO: task 6.1d
        endrule

        rule allocate;
            // TODO: task 6.1e
        endrule

        rule writeback;
            // TODO: task 6.1f
        endrule

        // TODO: implement subinterfaces here. See task 6.1b

        interface Server toCPU; 
            interface Put request = toPut(in); 
            interface Get response = toGet(out); 
        endinterface

        interface BRAMClient toMem; 
            interface Get request = toGet(toBRAM); 
            interface Put response = toPut(fromBRAM); 
        endinterface
    endmodule

endpackage : CacheCtrl