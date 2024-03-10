package BufferTb;
    import MyTypes::*;
    import Settings::*;
    import Buffer::*;
    import FIFO::*;
    import GetPut::*;
    import ClientServer::*;
    import StmtFSM::*;

    module mkBufferTb(Empty);
        // TODO: Implement this module (task 3.1e)

        BufferServer dut <- mkBRAMBuffer(); 

        Reg#(UInt#(32)) n_put <- mkReg(0); 
        Reg#(UInt#(32)) filled <- mkReg(0); 
        Reg#(UInt#(32)) drained <- mkReg(0); 
        Wire#(Bool) deq <- mkDWire(False); 


        Stmt do_test = seq 
            $display("Starting test"); 
            par
                seq
                    for(filled <= 0; filled < fromInteger(width) -3; fillded <= filled + 1) action 
                        dut.server.request.put(pack(filled)[7:0]); 
                        n_put <= n_put + 1; 
                    endaction 
                    $display("Put all values"); 
                endseq

                action 
                    let t <- dut.server.response.get(); 

                    if(n_put < fromInteger(width) -3)begin
                        $display("Error: Buffer should ot provide results before obtaining width-3 pixels. Just put %d values", n_put); 
                        $finsih(); 
                    end

                    if(t != 0)begin
                        $display("Wrong value at output. Expected 0, got %d", t); 
                        $finish(); 
                    end
                endaction 
                endpar
                par
                    action 
                        dut.server.request.put(pack(filled)[7:0]); 
                        n_put <= n_put + 1; 
                    endaction 
                    action 
                        let t <- dut.server.response.get(); 

                        if(n_put < fromInteger(width) -2)begin
                            $display("Error: Buffer should not provide a new value until filled again."); 
                            $finish(); 
                        end

                        if(t != 1)begin
                            $display("Error: Wrong value at output. Expected 1, got %d", t); 
                            $finish(); 
                        end
                    endaction 
                endpar
                
                action 
                    dut.server.request.put(pack(filled)[7:0]); 
                    n_put <= n_put + 1; 
                endaction 

                par
                    action
                        dut.server.request.put(pack(filled)[7:0]); 
                        
                        if(!deq)begin
                                $display("Error: request.put should have fired in the same cyle as response.get, but the deq is visivle"); 
                                $finish(); 
                        end
                    endaction 
                    action 
                        let t <- dut.server.response.get(); 
                        deq <= True; 
                    endaction 
                endpar

                par 
                    for(filled <= 3; filled < fromInteger(width-3); filled <= filled +1)action 
                        dut.server.request.put(0); 
                    endaction 

                    for(drained <= 3; drained < fromInteger(width-3); drained <= drained +1 )action 
                        let t <- dut.server.response.get(); 
                        if(t!= pack(drained)[7:0])begin
                        $display("Error: Wrong vlaue at %d, expected %d, got %d", drained, pack(drained)[7:0], t); 
                        $finish; 
                        end
                    endaction

                endpar

                $display("Test passed!"); 
        endseq; 

        mkAutoFMS(do_test); 



    endmodule : mkBufferTb


endpackage : BufferTb