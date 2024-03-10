package ReplacementStrategy;
    import Cache::*;
    import RegFile::*;
  
    interface ReplacementStrategy;
        method ActionValue#(Way) getReplacementFor(Index set);
        method Action updateAccesses(Index set, Way way);
    endinterface
  
    module mkRoundRobin(ReplacementStrategy);
        RegFile#(Index, Way) next_way <- mkRegFile(0, fromInteger(valueOf(N_SETS)-1));

        method ActionValue#(Way) getReplacementFor(Index set);
            let repl = next_way.sub(set);
            next_way.upd(set, repl + 1); // For ASSOCIATIVITY = 2^x this will wrap around nicely
            return repl;
        endmethod

        method Action updateAccesses(Index set, Way way);
            noAction(); // this round-robin does not care about accesses
        endmethod
    endmodule
  
    module mkHotPotato(ReplacementStrategy);
        RegFile#(Index, Way) next_way <- mkRegFile(0, fromInteger(valueOf(N_SETS)-1));
  
        method ActionValue#(Way) getReplacementFor(Index set);
            noAction();
            return next_way.sub(set);
        endmethod
  
        method Action updateAccesses(Index set, Way way);
            let way_curr = next_way.sub(set);
            next_way.upd(set, way == way_curr ? next_way.sub(set) + 1 : way_curr);
        endmethod
    endmodule
  
    typedef TSub#(ASSOCIATIVITY,1) PLRU_WIDTH;
  
    module mkPLRU(ReplacementStrategy);
        RegFile#(Index, Bit#(PLRU_WIDTH)) plru_bits <- mkRegFile(0, fromInteger(valueOf(N_SETS)-1)); // These hold the PLRU pointers, the lsb holds the root. The children of node i are at 2i+1 and 2i+2, respectively
  
        method ActionValue#(Way) getReplacementFor(Index set);
            noAction();
            // TODO: 6.1g
            return 0;
        endmethod
  
        method Action updateAccesses(Index set, Way way);
            // TODO: 6.1g
            noAction();
        endmethod
    endmodule
endpackage