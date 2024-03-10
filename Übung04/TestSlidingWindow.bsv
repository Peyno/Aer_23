package TestSlidingWindow;
    import GetPut::*;
    import ClientServer::*;
    import StmtFSM::*;
    import FIFO::*;
    import Vector::*;
    import Connectable::*;

    import MyTypes::*;
    import SlidingWindow::*;

    module mkTestSlidingWindowInEveryOutEveryCycle(FSM); 
        SlidingWindow dut <- mkSlidingWindow; 
        Reg#(UInt#(5)) count_in <- mkReg(0); 
        Reg#(UInt#(5)) window_count <- mkReg(0); 
        Vector#(2, Reg#(UInt#(5))) count_out <- replicateM(mkReg(0)); 
        Vector#(9, Reg#(GrayScale)) ref_vec <- replicateM(mkRegU); 
        Vector#(2, FIFO#(GrayScale)) client_ref_fifos <- replicateM(mkSizedFIFO(17)); 
        Vector#(2, Wire#(GrayScale)) buffer_wires <- replicateM(mkWire); 

        function Action put_and_rotate(GrayScale gs); 
            return action 
                ref_vec[0] <= gs; 
                for(Integer i = 0; i < 8; i = i + 1)begin
                    ref_vec[i+1] <= ref_vec[i]; 
                end
            endaction; 
        endfunction 

        function Action check_clients(Integer i); 
            return 
                action 
                    let outpx <- dut.buffer_client[i].request.get(); 
                    buffer_wires[i] <= outpx; 
                    dut.buffer_client[i].response.put(outpx); 

                    if(outpx != client_ref_fifos[i].first)begin
                        $display("Error, expected %d, got %d.", client_ref_fifos[i].first, outpx); 
                        $finish(); 
                    end
                    client_ref_fifos[i].deq(); 
                    count_out[i] <= count_out[i] + 1; 
                endaction; 
        endfunction 

        Stmt test = seq
            par
                while(count_in < 16) action 
                    GrayScale inpx = extend(pack(count_in)); 
                    dut.new_pixel.put(inpx); 
                    put_and_rotate(inpx); 
                    client_ref_fifos[0].enq(inpx); 
                    client_ref_fifos[1].enq(inpx); 
                    count_in <= count_in +1; 
                endaction 
                while(count_out[0] < 13)
                    check_clients(0); 
                
                while(count_out[1] < 10)
                    check_clients(1); 

                while(window_count < 8)action 
                    let vec <- dut.to_filter(); 
                    Vector#(3, Vector#(3, GrayScale)) reshape = unpack(pack(readVReg(ref_vec))); 
                    if(vec != reshape) begin 
                        $display("Error, expecte: ", fshow(reshape), ", got", fshow(vec)); 
                        $finish(); 
                    end
                    window_count <= window_count + 1;
                endaction 
            endpar
            $display("Test mkTestSlidingWindowInEveryOutEveryCycle successful!"); 
        endseq; 
        FSM fsm <- mkFSM(test); 
        return fsm; 
    endmodule: mkTestSlidingWindowInEveryOutEveryCycle












    module mkTestSlidingWindow(Empty);
        // TODO: implement me using a StmtFSM
    endmodule : mkTestSlidingWindow

endpackage : TestSlidingWindow