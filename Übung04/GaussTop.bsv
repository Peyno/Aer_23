package GaussTop;
    import Buffer::*;
    import RowBuffer::*;
    import MyTypes::*;
    import Settings::*;
    import SlidingWindow::*;
    import Gauss::*;

    import FIFO::*;
    import GetPut::*;
    import ClientServer::*;
    import Connectable::*;

    interface GaussTop;
        interface Server#(GrayScale, GrayScale) pixel_server;
    endinterface

    (* synthesize *)
    module mkGaussTop(GaussTop);
        // TODO: implement me
    endmodule : mkGaussTop

endpackage : GaussTop