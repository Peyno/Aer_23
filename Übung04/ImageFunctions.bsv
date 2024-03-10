package ImageFunctions;
    import MyTypes::*;
    import Settings::*;
    import Vector::*;
    
    /**
    * Allocate image for reading purposes at given path and return its address in memory as UInt#(64).
    */
    import "BDPI" function ActionValue#(UInt#(64)) readImage_create(String filename);

    /**
    * Open an image consisting of a basename and an iteration count. The suffix "padded" is appended automatically.
    * e.g., readImage_create_iter("AcceleratorTbOut", 0) opens an image AcceleratorTbOut0_padded.png and returns its
    * address.
    */
    import "BDPI" function ActionValue#(UInt#(64)) readImage_create_iter(String basename, UInt#(32) iteration);

    /**
    * Free the image memory located at the provided address.
    */
    import "BDPI" function Action readImage_delete(UInt#(64) addr);

    /**
    * Read the next pixel (row-major order) of the image located at addr.
    */
    import "BDPI" function ActionValue#(GrayScale) readImage_getPixel(UInt#(64) addr);

    /**
    * Retrieve pixel from image located at addr at index idx (row-major order).
    */
    import "BDPI" function GrayScale readImage_getPixelAt(UInt#(64) addr, UInt#(32) idx);

    /**
    * Allocate image for writing purposes with dimensions rows x columns and return its address. The resulting filename will be filename+iteration.png
    */
    import "BDPI" function ActionValue#(UInt#(64)) writeImage_create(String filename, UInt#(32) iteration, UInt#(32) columns, UInt#(32) rows);

    /**
    * Free the image at address addr.
    */
    import "BDPI" function Action writeImage_delete(UInt#(64) addr);

    /**
    * Write the next pixel (row-major order) to the result image located at address addr.
    */
    import "BDPI" function Action writeImage_putPixel(UInt#(64) addr, GrayScale pixel);

    /**
    * Write white padded image to disc. The file is saved with the suffix _padded.png.
    */
    import "BDPI" function Action writeImage_save_padded(UInt#(64) addr);

    // Oracles
    /**
    * Get reference result of provided image window.
    */
    import "BDPI" function GrayScale getGaussResult(Vector#(3, Vector#(3, GrayScale)) pixels);

    /**
    * Create stream-based oracle provided a readImage address and the input image dimensions and return its address.
    */
    import "BDPI" function ActionValue#(UInt#(64)) oracle_create(UInt#(64) input_addr, UInt#(32) width, UInt#(32) height);

    /**
    * Free the oracle at the provided address.
    */
    import "BDPI" function Action oracle_delete(UInt#(64) oracle);

    /**
    * Get the next result pixel from the oracle.
    */
    import "BDPI" function ActionValue#(GrayScale) oracle_get_next_pixel(UInt#(64) oracle);

    // Other utilities
    /**
    * Compute the index of a pixel in row-major order from given x and y coordinates (all zero-indexed).
    */
    function UInt#(32) xy_to_row_major(UInt#(32) x, UInt#(32) y);
        UInt#(32) res = y * fromInteger(width) + x;
        return res; // We don't need 64 bit here, as we will never load images with 4B x 4B resolution...
    endfunction

    /**
    * Convert a row-major index to x and y coordinates.
    */
    function Tuple2#(Int#(32), Int#(32)) row_major_to_xy(UInt#(32) idx);
        Int#(32) x = unpack(pack(idx)) % fromInteger(width);
        Int#(32) y = unpack(pack(idx)) / fromInteger(width);
        return tuple2(x,y);
    endfunction


    /**
    * Get a pixel from the provided readImage at coordinates x and y. If x and y are out-of-bounds this function
    * returns 0.
    */
    function GrayScale get_padded_pixel(UInt#(64) addressRead, Int#(32) x, Int#(32) y);
        GrayScale result = 0;
        if(x >= 0 && y >= 0 && x < fromInteger(width) && y < fromInteger(height)) begin
            let idx = xy_to_row_major(unpack(pack(x)), unpack(pack(y)));
            result = readImage_getPixelAt(addressRead, idx);
        end
        return result;
    endfunction
endpackage : ImageFunctions