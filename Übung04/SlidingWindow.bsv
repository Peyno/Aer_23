package SlidingWindow;
    import FIFO::*;
    import FIFOF::*;
    import SpecialFIFOs::*;
    import GetPut::*;
    import ClientServer::*;
    import Vector::*;
    import MyTypes::*;

    interface SlidingWindow;
        interface Put#(GrayScale) new_pixel;
        interface Vector#(2, Client#(GrayScale, GrayScale)) buffer_client;
        method ActionValue#(Vector#(3, Vector#(3, GrayScale))) to_filter();
    endinterface : SlidingWindow

    (* synthesize *)
    module mkSlidingWindow(SlidingWindow);
        // TODO: implement me

        Vector#(3, Vector#(3, FIFO#(GrayScale))) field <- replicateM(replicateM(mkPipelineFIFO)); 

        Wire#(Bool) window_handled <- mkDWire(False); 

        for(Integer i=0; i<3; i=i+1) begin
            for(Integer j=0; j<2; j=j+1)begin
                rule propagate; 
                    field[i][j+1].enq(field[i][j].first()); 
                    field[i][j].deq(); 
                endrule: propagate
            end
        end

        rule discard_last(window_handled); 
            field[2][2].deq(); 
        endrule

        Vector#(2, Client#(GrayScale, GrayScale)) clients; 
        for(Integer i=0; i<2; i=i+1)begin
            clients[i] = interface Client; 
            interface Put response = toPut(field[i+1][0]); 
            interface Get request = toGet(field[i][2]); 
            endinterface; 
        end

        method ActionValue#(Vector#(3, Vector#(3, GrayScale))) to_filter(); 
            Vector#(3, Vector#(3, GrayScale)) res = replicate(replicate(0)); 
            for(Integer i=0; i < 3; i = i + 1) begin
                for(Integer j = 0; j < 3; j = j + 1)begin
                    res[i][j] = field[i][j].first(); 
                end
            end
            window_handled <= True; 
            return res; 
        endmethod

        method Action clear(); 
            for(Integer i = 0; i < 3; i = i + 1)
                for(Integer j = 0; j < 3; j = j + 1)
                    field[i][j].clear(); 
        endmethod

        interface Put new_pixel = toPut(field[0][0]); 

        interface buffer_client = clients; 

    endmodule : mkSlidingWindow

endpackage : SlidingWindow