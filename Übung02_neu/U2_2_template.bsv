package U2Tb;
    import U2::*;
    import StmtFSM::*;
    import Vector::*;
    
    module mkU2Tb(Empty);
        Pipeline dut <- mkPipeline;
        Reg#(UInt#(32)) idx_put <- mkReg(0);
        Reg#(UInt#(32)) idx_get <- mkReg(0);
        Reg#(UInt#(32)) correct_tests <- mkReg(0);

        Vector#(20, Int#(32)) testvec;
        testvec[0] = 401; // values 0-9 for a = 42, b = 2, c = 13
        testvec[1] = 407;
        testvec[2] = 414;
        testvec[3] = 420;
        testvec[4] = 427;
        testvec[5] = 433;
        testvec[6] = 440;
        testvec[7] = 446;
        testvec[8] = 453;
        testvec[9] = 459;
        testvec[10] = 344; // value 10 - 19 for a = 7, b = 3, c = 17
        testvec[11] = 357;
        testvec[12] = 370;
        testvec[13] = 383;
        testvec[14] = 395;
        testvec[15] = 408;
        testvec[16] = 421;
        testvec[17] = 434;
        testvec[18] = 446;
        testvec[19] = 459;

        Stmt s = seq
            // TODO: write statement
            dut.setParam(0, 42); 
            dut.setParam(1, 2); 
            dut.setParam(2, 13); 
            $display("Initialized parameters, starting test..."); 
            par
                seq
                    for(idx_put <= 0; idx_put < 10; idx_put <= idx_put + 1)action 
                        dut.calc.put(unpack(pack(idx_put))); 
                    endaction 
                    dut.setParam(0, 7); 
                    dut.setParam(1, 3); 
                    dut.setParam(2, 17); 
                    for(idx_put <= 10; idx_put < 20; idx_put <= idx_put + 1)action 
                        dut.calc.put(unpack(pack(idx_put))); 
                    endaction 
                endseq

                seq
                    for(idx_get <= 0; idx_get < 20; idx_get <= idx_get + 1)action 
                        $display("Checking results for %d", idx_get); 
                        let r <- dut.cal.result(); 
                        if(r == testvec[idx_get])begin 
                            correct_tests <= correct_tests + 1; 
                        end
                        else begin 
                            $display("Expected %d, got %d", testvec[idx_get], r); 
                        end
                    endaction 
                endseq
                
                
            endpar
            $display("%d of 20 tests passed", correct_tests); 
            if(correct_tests == 20)
                $display("SUCCESS!"); 
            else
                $display("FAILURE"); 

            $finish(); 
                

        endseq

        mkAutoFSM(s); 

        // TODO: instantiate FSM

    endmodule

endpackage