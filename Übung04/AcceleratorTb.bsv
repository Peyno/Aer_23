package AcceleratorTb;
    import MyTypes::*;
    import GetPut::*;
    import ClientServer::*;
    import FIFO::*;
    import ImageFunctions::*;
    import Gauss::*;
    import StmtFSM::*;
    import Settings::*;
    import Vector::*;
    import GaussTop::*;
    import Watchdog::*;

    typedef enum {Init, Compute, Cleanup, Finish} TBState deriving(Bits, Eq);

    module mkAcceleratorTb(Empty);
        Reg#(TBState) state <- mkReg(Init);
        Reg#(UInt#(32)) readCounter <- mkReg(0);
        Reg#(UInt#(32)) writeCounter <- mkReg(0);
        Reg#(UInt#(64)) addressRead <- mkRegU;
        Reg#(UInt#(64)) addressWrite <- mkRegU;

        Reg#(UInt#(32)) n_pixels_in <- mkRegU;
        Reg#(UInt#(32)) n_pixels_out <- mkRegU;

        Watchdog watchdog <- mkWatchdog(32'h_00FFFFFF);

        // Unit under test (our filter)
        GaussTop uut <- mkGaussTop();

        rule init(state == Init);
             let t1 <- readImage_create("./picture.png");
            addressRead <= t1;
            $display("Reading image, is at: %d", t1);

            n_pixels_in <= fromInteger(width) * fromInteger(height);
            n_pixels_out <= fromInteger(width-2) * fromInteger(height-2);
            let t2 <- writeImage_create("./AcceleratorTbOut", 0, fromInteger(width-2), fromInteger(height-2));
            addressWrite <= t2;
            $display("Writing image, is at: %d", t2);
            state <= Compute;
        endrule : init

        rule cleanup(state == Cleanup);
            readImage_delete(addressRead);
            writeImage_delete(addressWrite);
            uut.clear();

            $display("Finished test");
            state <= Finish;
        endrule : cleanup

        rule finish (state == Finish);
            $finish();
        endrule : finish

        rule compute_in(state == Compute && readCounter != n_pixels_in);
            let pixel <- readImage_getPixel(addressRead);
            uut.pixel_server.request.put(pixel);
            readCounter <= readCounter + 1;
        endrule : compute_in

        rule compute_out(state == Compute && writeCounter != n_pixels_out);
            let new_pixel <- uut.pixel_server.response.get;
            writeImage_putPixel(addressWrite, new_pixel);
            writeCounter <= writeCounter + 1;
            if(writeCounter == n_pixels_out - 1)
                state <= Cleanup;
        endrule : compute_out

        /*
        Stmt convertImage = seq 
            action
                let t1 <- readImage_create("./picture.png");
                addressRead <= t1;
                $display("Reading image, is at: %d", t1);

                n_pixels_in <= fromInteger(width) * fromInteger(height);
                n_pixels_out <= fromInteger(width-2) * fromInteger(height-2);
                let t2 <- writeImage_create("./AcceleratorTbOut", 0, fromInteger(width-2), fromInteger(height-2));

                addressWrite <= t2;
                $display("Writing image, is at: %d", t2);
            endaction
            par
                for(readCounter <= 0; readCounter < n_pixels_in; readCounter <= readCounter + 1) action
                    let pixel <- readImage_getPixel(addressRead);
                    uut.pixel_server.request.put(pixel);
                endaction
                for(writeCounter <= 0; writeCounter < n_pixels_out; writeCounter <= writeCounter + 1) action
                    let new_pixel <- uut.pixel_server.response.get;
                    writeImage_putPixel(addressWrite, new_pixel);
                endaction
            endpar
            readImage_delete(addressRead);
            writeImage_delete(addressWrite);
            uut.clear();

            $display("Finished test");
        endseq;

        mkAutoFSM(convertImage);
        */


    endmodule
endpackage