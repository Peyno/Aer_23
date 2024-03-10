package CacheCtrlTb;
    import Cache::*;
    import CacheCtrl::*;
    import ClientServer::*;
    import GetPut::*;
    import StmtFSM::*;
    import Vector::*;
    import BRAM::*;

    typedef TDiv#(CAPACITY, BYTES_PER_WORD) N_WORDS;

    function Action my_assert(Bool expression, Fmt message);
        return action
            if(!expression) begin
                $display(message);
                $finish();
            end
        endaction;
    endfunction

    module mkCacheCtrlTb(Empty);
        CacheCtrl dut <- mkCacheCtrl();
        Reg#(UInt#(32)) timeout_watchdog <- mkReg(32'h_FF_FF_FF); // this serves as a timeout
        Reg#(Bool) start_timeout <- mkReg(False);
        Reg#(Bool) check_no_mem <- mkReg(False);
        Reg#(Address) addr <- mkRegU();
        Reg#(Address) block <- mkRegU();

        
        Vector#(TAdd#(N_WORDS, N_WORDS), Data) testwords;
        for(Integer i = 0; i < valueOf(TAdd#(N_WORDS, N_WORDS)); i = i + 1)
            testwords[i] = fromInteger(-1 - i);

        function Action start_timeout_watchdog();
            return action
                timeout_watchdog <= 32'h_FF_FF_FF;
                start_timeout <= True;
            endaction;
        endfunction

        function Action stop_timeout_watchdog();
            return action
                start_timeout <= False;
            endaction;
        endfunction

        function Action watch_memory();
            return action
                check_no_mem <= True;
            endaction;
        endfunction

        function Action unwatch_memory() = action 
            check_no_mem <= False;
        endaction;

        Fmt prefix = $format("Error at 0x%h: ", addr);

        Stmt teststmt = seq 
            $display("Starting cache controller test FSM.");
            $display("Checking for compulsory read misses...");
            for(addr <= 0; addr < fromInteger(valueOf(CAPACITY)); addr <= addr + fromInteger(valueOf(BLOCK_SIZE))) seq
                action
                    dut.toCPU.request.put(tagged Read ReadReq {addr: addr});
                    start_timeout_watchdog();
                endaction
                for(block <= 0; block < fromInteger(valueOf(WORDS_PER_BLOCK)); block <= block + 1) action
                    let t <- dut.toMem.request.get();
                    my_assert(!t.write, prefix + $format("Memory request should be read, got write."));
                    my_assert(t.address == addr + block * fromInteger(valueOf(BYTES_PER_WORD)), prefix + $format("Address wrong. Expected 0x%h, got 0x%h", addr, t.address));
                    dut.toMem.response.put(testwords[(addr >> 2)+block]);
                endaction
                action
                    let t <- dut.toCPU.response.get();
                    if(t matches tagged Read .r) begin
                        my_assert(r == testwords[addr >> 2], prefix + $format("Wrong cache reponse. Expected 0x%h, got 0x%h", testwords[addr >> 2], r));
                    end
                    else begin
                        $display("Expected read response, got write.");
                        $finish();
                    end
                    stop_timeout_watchdog();
                endaction
            endseq
            $display("Checking for read hits...");
            for(addr <= 0; addr < fromInteger(valueOf(CAPACITY)); addr <= addr + fromInteger(valueOf(BYTES_PER_WORD))) seq
                action
                    dut.toCPU.request.put(tagged Read ReadReq {addr: addr});
                    watch_memory();
                endaction
                delay(20); // wait 20 cycles to have ensure no memory requests happen.
                action
                    let t <- dut.toCPU.response.get();
                    if(t matches tagged Read .r) begin
                        my_assert(r == testwords[addr >> 2], prefix + $format("Wrong cache reponse. Expected 0x%h, got 0x%h", testwords[addr >> 2], r));
                    end
                    else begin
                        $display("Expected read response, got write.");
                        $finish();
                    end
                    unwatch_memory();
                endaction
            endseq
            $display("Checking for write hits...");
            for(addr <= 0; addr < fromInteger(valueOf(CAPACITY)); addr <= addr + fromInteger(valueOf(BYTES_PER_WORD))) seq
                action
                    dut.toCPU.request.put(tagged Write WriteReq {addr: addr, data: testwords[addr >> 2]-1});
                    watch_memory();
                endaction
                delay(20); // wait 20 cycles to have ensure no memory requests happen.
                action
                    let t <- dut.toCPU.response.get();
                    if(t matches tagged Write .w) begin
                        my_assert(w, prefix + $format("Wrong cache reponse. Should be True"));
                    end
                    else begin
                        $display("Expected write response, got read.");
                        $finish();
                    end
                    unwatch_memory();
                endaction
            endseq

            $display("Checking previous writes and write allocate...");
            for(addr <= fromInteger(valueOf(CAPACITY)); addr < 2*fromInteger(valueOf(CAPACITY)); addr <= addr + fromInteger(valueOf(BLOCK_SIZE))) seq
                action
                    dut.toCPU.request.put(tagged Write WriteReq {addr: addr, data: testwords[addr >> 2]-1});
                    start_timeout_watchdog();
                endaction
                // First check writeback
                for(block <= 0; block < fromInteger(valueOf(WORDS_PER_BLOCK)); block <= block + 1) action
                    let t <- dut.toMem.request.get();
                    my_assert(t.write, prefix + $format("Writeback memory request should be write, got read."));
                    Address expected = addr-fromInteger(valueOf(CAPACITY)) + block * fromInteger(valueOf(BYTES_PER_WORD));
                    my_assert(t.address == expected, prefix + $format("Address wrong. Expected 0x%h, got 0x%h", expected, t.address));
                    my_assert(t.datain == testwords[expected >> 2]-1, prefix + $format("Data word is wrong. Expected 0x%h, got 0x%h", testwords[expected >> 2]-1, t.datain));
                endaction

                // Check write allocate
                for(block <= 0; block < fromInteger(valueOf(WORDS_PER_BLOCK)); block <= block + 1) action
                    let t <- dut.toMem.request.get();
                    my_assert(!t.write, prefix + $format("Write-allocate memory request should be read, got write."));
                    my_assert(t.address == addr + block * fromInteger(valueOf(BYTES_PER_WORD)), prefix + $format("Address wrong. Expected 0x%h, got 0x%h", addr, t.address));
                    dut.toMem.response.put(testwords[(addr >> 2)+block]);
                endaction

                action
                    stop_timeout_watchdog();
                    let t <- dut.toCPU.response.get();
                    if(t matches tagged Write .w) begin
                        my_assert(w, prefix + $format("Wrong cache reponse. Should be True"));
                    end
                    else begin
                        $display("ERROR: Expected write response, got read.");
                        $finish();
                    end
                endaction
            endseq

            // Check final write results
            $display("Checking last writes...");
            for(addr <= fromInteger(valueOf(CAPACITY)); addr < 2*fromInteger(valueOf(CAPACITY)); addr <= addr + fromInteger(valueOf(BLOCK_SIZE))) seq
                action
                    dut.toCPU.request.put(tagged Read ReadReq {addr: addr});
                    watch_memory();
                endaction
                delay(20); // wait 20 cycles to have ensure no memory requests happen.
                action
                    let t <- dut.toCPU.response.get();
                    if(t matches tagged Read .r) begin
                        my_assert(r == testwords[addr >> 2]-1, prefix + $format("Wrong cache reponse. Expected 0x%h, got 0x%h", testwords[addr >> 2]-1, r));
                    end
                    else begin
                        $display("Expected read response, got write.");
                        $finish();
                    end
                    unwatch_memory();
                endaction
            endseq
            $display("Test finished successfully");
        endseq;

        mkAutoFSM(teststmt);

        rule invalid_memory(check_no_mem);
            let t <- dut.toMem.request.get();
            $display(prefix+$format("Should not get memory request at this point."));
            $finish();
        endrule

        rule run_timer(start_timeout);
            timeout_watchdog <= timeout_watchdog - 1;
        endrule

        rule timeout_failure(timeout_watchdog == 0);
            $display("ERROR: Watchdog timed-out. Your controller hangs.");
            $finish();
        endrule
    endmodule
endpackage : CacheCtrlTb