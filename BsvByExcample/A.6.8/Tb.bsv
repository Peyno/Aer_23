package Tb; 

import PipelinedSyncROM_model::*; 

typedef UInt#(16) Addr; 
typedef UInt#(16) Data; 

(* synthesize *)
(* always_ready = "request, response" *)
(* always_enabled = "request" *)

module mkPipelinedSyncROM_model_specific (PipelineSyncROM#(Addr, Data)); 
    let m <- mkPipelinedSyncROM_model ("mem_init.data", 0, 31); 
    return m; 
endmodule

(* synthesize *)
module mkTb (Empty); 
    PipelinedSyncROM#(Addr, Data) rom <- mkPipelinedSyncROM_model_specific(); 

    Reg#(Addr) ra <- mkReg(0); 
    Reg#(int) cycle <- mkReg(0); 

    rule step_addr; 
        rom.request(ra); 
        if(ra > 15) $finish(0); 
        ra <= ra + 1; 
        cycle <= cycle + 1; 
        $display ("%0d: Sending address %0h", cycle, ra); 
    endrule

    rule show_data; 
        $display("%0d: Data returned is %0h", cycle, rom.response()); 
    endrule

endmodule: mkTb

endpackage: Tb