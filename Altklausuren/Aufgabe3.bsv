package Aufgabe3

module mkTestbench(Empty); 
    Server#(Grayscale, Grayscale) golden_model <- mkGoldenModel(); 
    Server#(Grayscale, Grayscale) dut <- mkNegative(); 

    Reg#(UInt#(32)) a <- mkRegU; 
    Reg#(UInt#(32)) b <- mkRegU; 
    Reg#(int) false <- mkReg(0); 

    Stmt test = seq
            par
                seq 
                    for(a <= 0; < 11; a <= a + 1) action 
                        dut.request.put(truncate(a)); 
                        golden_model.put(truncate(a)); 
                    endaction 
                endseq
                seq 
                    for(b <= 0; b < 11; b <= b + 1)action 
                        let dutval <- dut.response.get(); 
                        let goldenval <- golden.dut.response.get(); 
                        if(dutval != goldenval) action 
                            falses <= false + 1; 
                            $display("ERROR"); 
                            $finish(0); 
                        endaction 

                    endaction 
                endseq
            endpar
    if(false == 0) action 
        $dispaly("SUCCESS!"); 
    endaction 
    $finish(0); 
    endseq;
    mkAutoFSM(test); 


endmodule


endpackage