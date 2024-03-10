package U1; 

    interface Blinky;
        method Bool blink(); 
        method Action start(); 
        method ActionValue#(int) stop();
    endinterface


    module mkBlinky(Blinky);

        Reg#(Bool) ctrl_on <- mkReg(False); 
        Reg#(Bool) led_on <- mkReg(False); 
        Reg#(int) blink_ctr <- mkReg(0); 

        rule regel(ctrl_on);
            Bool led_new = !led_on; 
            if(led_new) begin 
                blink_ctr <= blink_ctr +1; 
            end
            led_on <= led_new; 
        endrule

        method Bool blink(); 
            return led_on; 
        endmethod


        method Action start() if(!ctrl_on); 
            ctrl_on <= True;
            blink_ctr <= 0;  
        endmethod

        method ActionValue#(int) stop() if(ctrl_on); 
            ctrl_on <= False; 
            led_on <= False; 
            return blink_ctr; 
        endmethod

    endmodule

endpackage 