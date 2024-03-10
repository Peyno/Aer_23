package Tb; 
import FIFO::*; 
import StmtFSM::*; 


typedef enum {Red, RedYellow, Yellow, Green} AmpelState deriving(Bits, Eq); 
typedef enum {PRed, PGreen} PedestrianState deriving (Bits, Eq); 

interface AmpelIf; 
    (* always_enabled *)
    method Action request_pedestrian; 
    (* always_enabled *)
    method AmpelState get_state; 
    (* always_enabled *)
    method PedestrianState get_pedestrian_state; 
endinterface

module mkAmpel(AmpelIf); 
    Array#(Reg#(AmpelState)) state <- mkCReg(2, Red); 
    Array#(Reg#(PedestrianState)) pedestrian_state <- mkCReg(2, PRed); 
    Array#(Reg#(Bool)) pedestrian_request <- mkCReg(2, False); 
    Reg#(UInt#(8)) idle_counter <- mkRegU; 

    Stmt s = seq
        //1
        action 
        state[0] <= RedYellow; 
        endaction 
        //2
        action 
        state[0] <= Green; 
        idle_counter <= 15; 
        endaction 

        while(idle_counter > 0 )action 
            action 
            state[0] <= Green; 
            pedestrian_state[0] <= PRed; 
            endaction 
            
            //3
            if(pedestrian_request[1] && idle_counter > 5) action 
                idle_counter <= 5; 
            endaction 
            else action 
            idle_counter <= idle_counter - 1; 
            endaction 
            
        endaction 

        //4
        action 
        state[0] <= Yellow; 
        pedestrian_state[0] <= PRed; 
        endaction 

        //5
        action 
        state[0] <= Red; 
        endaction 

        // 6
        action 
        pedestrian_state[0] <= PGreen; 
        idle_counter <= 10; 
        endaction 
        while(idle_counter > 0)action 
            state[0] <= Red; 
            pedestrian_state[0] <= PGreen; 
        endaction 

        // vlt noch wieder in Zustand 0
    endseq ;
let fsm <- mkFSM(s); 
   

    rule start; 
        fsm.start(); 
    endrule

    method Action request_pedestrian; 
        pedestrian_request[0] <= True; 
    endmethod

    method AmpelState get_state; 
        return state[1]; 
    endmethod

    method PedestrianState get_pedestrian_state; 
        return pedestrian_state[1]; 
    endmethod

endmodule

















module mkAmpelTest(Empty);
        AmpelIf ampel <- mkAmpel();
        Reg#(int) counter <- mkReg(0);
        Stmt s = seq
            ampel.request_pedestrian();

            while (True) action
                let pedestrian = ampel.get_pedestrian_state;
                let ampelState = ampel.get_state;

                $display("time: %d ampel: %d, pedestrian: %d", $time, ampelState, pedestrian);
                counter <= counter + 1;
                if(counter > 50) $finish;
            endaction
        endseq;

        mkAutoFSM(s);
    endmodule


endpackage