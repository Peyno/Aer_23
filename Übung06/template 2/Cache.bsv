package Cache;
    import Vector::*;
    import DefaultValue::*;
    import ClientServer::*;
    import GetPut::*;
    import FIFO::*;

    /*~~~~~CONFIGURATION~~~~~*/
    typedef 32    ADDR_WIDTH;
    typedef 32    WORD_WIDTH;

    typedef 128    CAPACITY; // in byte
    typedef 8     BLOCK_SIZE; // in byte
    typedef 4     ASSOCIATIVITY;

  
    /* Computing bit widths for data types according to set parameters */
    typedef TDiv#(CAPACITY, BLOCK_SIZE)         N_BLOCKS;
    typedef TDiv#(WORD_WIDTH, 8)                BYTES_PER_WORD;
    typedef TDiv#(BLOCK_SIZE, BYTES_PER_WORD)   WORDS_PER_BLOCK;
    typedef TDiv#(N_BLOCKS, ASSOCIATIVITY)      N_SETS;

    typedef TLog#(N_SETS)                                                                         INDEX_WIDTH;
    typedef TLog#(WORDS_PER_BLOCK)                                                                BLOCK_OFFSET_WIDTH;
    typedef TLog#(BYTES_PER_WORD)                                                                 BYTE_OFFSET_WIDTH;
    typedef TSub#(TSub#(TSub#(ADDR_WIDTH, BYTE_OFFSET_WIDTH), BLOCK_OFFSET_WIDTH), INDEX_WIDTH)   TAG_WIDTH;
    typedef TLog#(ASSOCIATIVITY)                                                                  WAY_WIDTH;


    /* Actually usable datatypes */
    typedef Bit#(ADDR_WIDTH)          Address;
    typedef Bit#(WORD_WIDTH)          Data;
    typedef Bit#(TAG_WIDTH)           Tag;
    typedef Bit#(BLOCK_OFFSET_WIDTH)  BlockOffset;
    typedef Bit#(BYTE_OFFSET_WIDTH)   ByteOffset;
    typedef Bit#(INDEX_WIDTH)         Index;
    typedef Bit#(WAY_WIDTH)           Way;

    typedef struct {
        Tag tag;
        Index index;
        BlockOffset block_offset;
        ByteOffset byte_offset;
    } DecodedAddress deriving (Bits, Eq, FShow);

    typedef struct {
        Bool dirty;
        Tag tag;
        Vector#(WORDS_PER_BLOCK, Data) data_block;
    } CacheEntry deriving (Bits, FShow);

    instance DefaultValue#(CacheEntry);
        defaultValue = CacheEntry {
          dirty: False,
          tag: 0,
          data_block: defaultValue
        };
    endinstance

    // Utility functions
    function DecodedAddress decode(Address addr);
        return DecodedAddress {
            tag: addr[valueOf(ADDR_WIDTH)-1:valueOf(ADDR_WIDTH)-valueOf(TAG_WIDTH)],
            index: addr[valueOf(ADDR_WIDTH)-1-valueOf(TAG_WIDTH):valueOf(ADDR_WIDTH)-valueOf(TAG_WIDTH)-valueOf(INDEX_WIDTH)],
            block_offset: fromInteger(valueOf(BLOCK_OFFSET_WIDTH)) > 0 ? addr[valueOf(BYTE_OFFSET_WIDTH)+valueOf(BLOCK_OFFSET_WIDTH)-1:valueOf(BYTE_OFFSET_WIDTH)] : 0,
            byte_offset: 0
        };
    endfunction

    function Address encode(DecodedAddress dec);
        return {dec.tag, dec.index, dec.block_offset, dec.byte_offset};
    endfunction

    // Interface datatypes
    typedef DecodedAddress LoadReq;
    typedef struct {
        Way way;
        Data data;
    } LoadRsp deriving(Bits, Eq);

    typedef struct {
        DecodedAddress addr;
        Data data;
    } StoreReq deriving(Bits, Eq);

    typedef Way StoreRsp;

    typedef union tagged {
        LoadReq Load;
        StoreReq Store;
    } CacheReq deriving(Bits, Eq);

    typedef union tagged {
        LoadRsp LoadResponse;
        StoreRsp StoreResponse;
    } CacheRsp deriving(Bits, Eq);

    interface Cache;
        interface Server#(CacheReq, Maybe#(CacheRsp)) ls_server;
        method Action updateBlock(CacheEntry new_entry, Index set, Way postion);
        method Maybe#(CacheEntry) getBlock(Index set, Way position);
    endinterface

    module mkCache(Cache);
        FIFO#(CacheReq) req_fifo <- mkFIFO;
        FIFO#(Maybe#(CacheRsp)) rsp_fifo <- mkFIFO;
        Wire#(Bool) update_in_progress <- mkDWire(False);
        Vector#(N_SETS, Vector#(ASSOCIATIVITY, Reg#(Maybe#(CacheEntry)))) data_field <- replicateM(replicateM(mkReg(tagged Invalid)));

        function Tuple2#(Bool, Way) findWay(Vector#(ASSOCIATIVITY, Reg#(Maybe#(CacheEntry))) set, Tag tag);
            Way pos = 0;
            Bool hit = False;

            for(Integer i = 0; i < valueOf(ASSOCIATIVITY); i = i + 1) begin
                let entry_i = set[i];
                if(entry_i matches tagged Valid .e) begin
                    if(e.tag == tag) begin
                        pos = fromInteger(i);
                        hit = True;
                    end
                end
            end
            return tuple2(hit, pos);
        endfunction

        rule handle_req(!update_in_progress);
            let req = req_fifo.first();
            req_fifo.deq();
            DecodedAddress addr;
            Data data = 0;
            if(req matches tagged Load .load)
                addr = load; // LoadReq was just a typedef to DecodedAddress
            else begin
                addr = req.Store.addr;
                data = req.Store.data;
            end

            let set = addr.index;
            let row = data_field[set];

            match {.hit, .pos} = findWay(row, addr.tag);
            CacheRsp rsp = unpack(0);
            if(hit) begin
                if(req matches tagged Load .load) begin
                    data = fromMaybe(defaultValue, row[pos]).data_block[addr.block_offset];
                    rsp = tagged LoadResponse LoadRsp{way: pos, data: data};
                end
                else if(req matches tagged Store .store) begin
                    let entry_data = fromMaybe(defaultValue, row[pos]).data_block;
                    entry_data[addr.block_offset] = data;

                    CacheEntry upd = CacheEntry{
                        dirty: True,
                        tag: addr.tag,
                        data_block: entry_data
                    };
                    data_field[set][pos] <= tagged Valid upd;
                    rsp = tagged StoreResponse pos;
                end
                rsp_fifo.enq(tagged Valid rsp);
            end
            else
                rsp_fifo.enq(tagged Invalid);
        endrule

        method Action updateBlock(CacheEntry new_entry, Index set, Way position);
            update_in_progress <= True;
            data_field[set][position] <= tagged Valid new_entry;
        endmethod

        method Maybe#(CacheEntry) getBlock(Index set, Way position);
            Maybe#(CacheEntry) block = data_field[set][position];
            return block;
        endmethod

        interface Server ls_server;
            interface Put request = toPut(req_fifo);
            interface Get response = toGet(rsp_fifo);
        endinterface
    endmodule
endpackage : Cache