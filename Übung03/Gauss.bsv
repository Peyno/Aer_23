package Gauss;
    import ClientServer::*;
    import GetPut::*;
    import FIFO::*;
    import Vector::*;
    import MyTypes::*;

    typedef Server#(Vector#(3, Vector#(3, GrayScale)), GrayScale) FilterServer;

    /* 3x3 Gaussian kernel filter
            -------------
            | 1 | 2 | 1 |
            -------------
    1/16 *  | 2 | 4 | 2 |
            -------------
            | 1 | 2 | 1 |
            -------------
    */

    module mkGauss(FilterServer);
        // TODO: implement me (task 3.1b)
 FIFO#(Vector#(3, Vector#(3, GrayScale))) in <- mkFIFO();
        FIFO#(GrayScale) out <- mkFIFO();

        Vector#(3, Vector#(3, Integer)) weights = replicate(replicate(0)); // Hard-wired kernel weights
        weights[0][0] = 1;
        weights[0][1] = 2;
        weights[0][2] = 1;
        weights[1][0] = 2;
        weights[1][1] = 4;
        weights[1][2] = 2;
        weights[2][0] = 1;
        weights[2][1] = 2;
        weights[2][2] = 1;


        rule convolve;
            let pixels = in.first();
            in.deq();
            Bit#(12) mulres = 0;

            for(Integer i = 0; i < 3; i = i + 1) begin
                for(Integer j = 0; j < 3; j = j + 1) begin
                    Bit#(12) px_ex = extend(pixels[i][j]);
                    mulres = mulres + (px_ex << log2(weights[i][j]));
                end
            end
            out.enq(truncate(mulres >> 4));
        endrule

        interface Put request = toPut(in);
        interface Get response = toGet(out);
    endmodule : mkGauss
endpackage : Gauss