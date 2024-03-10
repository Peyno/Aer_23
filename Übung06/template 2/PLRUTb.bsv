package PLRUTb;
    import GetPut::*;
    import FIFO::*;
    import Cache::*;
    import ReplacementStrategy::*;
    import StmtFSM::*;
    import Vector::*;

    module mkPLRUTb(Empty);
        ReplacementStrategy dut <- mkPLRU();

        Vector#(6, Tuple2#(Way, Way)) accesses; // (Accessed way, expected output after access)
        accesses[0] = tuple2(0, 2);
        accesses[1] = tuple2(0, 2);
        accesses[2] = tuple2(2, 1);
        accesses[3] = tuple2(1, 3);
        accesses[4] = tuple2(3, 0);
        accesses[5] = tuple2(3, 0);

        Reg#(Bit#(TAdd#(INDEX_WIDTH,1))) curr_set <- mkRegU;
        Reg#(Bit#(3)) access_idx <- mkRegU;
        Stmt s = seq 
            for(curr_set <= 0; curr_set < fromInteger(valueOf(N_SETS)); curr_set <= curr_set + 1) seq 
                for(access_idx <= 0; access_idx < 6; access_idx <= access_idx + 1) seq
                    dut.updateAccesses(truncate(curr_set), tpl_1(accesses[access_idx]));
                    action
                        let out <- dut.getReplacementFor(truncate(curr_set));
                        let expected = tpl_2(accesses[access_idx]);
                        if(out != expected) begin
                            $display("ERROR: [set = %d] Expected %d, got %d", curr_set, expected, out);
                            $finish();
                        end
                    endaction
                endseq
            endseq
            $display("Test finished successfully!");
        endseq;
        mkAutoFSM(s);

    endmodule : mkPLRUTb
endpackage : PLRUTb