package GaussTb;
    import FIFO::*;
    import Vector::*;
    import Gauss::*;
    import MyTypes::*;
    import GetPut::*;
    import ClientServer::*;
    import Settings::*;
    import ImageFunctions::*;


    module mkGaussTb(Empty);
        FilterServer dut <- mkGauss();

        Reg#(UInt#(32)) read_x <- mkReg(1);
        Reg#(UInt#(32)) read_y <- mkReg(1);
        Reg#(UInt#(32)) writeCounter <- mkReg(0);
        Reg#(UInt#(64)) addressRead <- mkRegU;
        Reg#(UInt#(64)) addressWrite <- mkRegU;
        Reg#(Bool) started <- mkReg(False);

        Reg#(UInt#(32)) n_pixels <- mkRegU;

        rule init(!started);
            let t1 <- readImage_create("./picture.png");
            addressRead <= t1;

            n_pixels <= fromInteger(width-2) * fromInteger(height-2);
            let t2 <- writeImage_create("./GaussTbOut", 0, fromInteger(width-2), fromInteger(height-2));
            addressWrite <= t2;
            started <= True; // we are ready to crunch some numbers!
        endrule : init

        rule pixels_in (started && read_y < fromInteger(height-1));
            // Housekeeping
            if(read_x == fromInteger(width-2)) begin
                read_x <= 1;
                read_y <= read_y + 1;
            end
            else begin
                read_x <= read_x + 1;
            end
            // Prepare inputs for gauss kernel
            Vector#(3, Vector#(3, GrayScale)) field = replicate(replicate(0)); // Make the compiler happy...
            for(Int#(32) ky = -1; ky <= 1; ky = ky + 1) begin
                for(Int#(32) kx = -1; kx <= 1; kx = kx + 1) begin
                    field[ky+1][kx+1] = get_padded_pixel(addressRead, unpack(pack(read_x))+kx, unpack(pack(read_y))+ky);
                end
            end
            dut.request.put(field);
        endrule : pixels_in

        rule pixels_out(writeCounter != n_pixels);
            let new_pixel <- dut.response.get();
            writeImage_putPixel(addressWrite, new_pixel);
            writeCounter <= writeCounter + 1;
        endrule : pixels_out

        rule clean_up(writeCounter == n_pixels);
            readImage_delete(addressRead);
            writeImage_delete(addressWrite);
            $finish();
        endrule : clean_up
    endmodule : mkGaussTb
endpackage : GaussTb