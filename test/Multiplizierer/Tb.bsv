package Multiplier;

    interface Mltplctr_interface;
        method Action put_x(Int#(32) x);
        method Action put_y(Int #(32) y);
        method Int#(32) result;
    endinterface


    module mkMultiplier(Mltplctr_interface);

        Reg#(Int #(32)) reg_x <- mkReg(0);
        Reg#(Int #(32)) reg_y <- mkReg(0);
        Reg#(Int #(32)) reg_rslt <- mkReg(0);
        Reg#(Bool) set_x <- mkReg(False);
        Reg#(Bool) set_y <- mkReg(False);

        rule calc ((reg_y != 0) && set_x && set_y);
            if(lsb(reg_y) == 1) reg_rslt <= reg_rslt + reg_x;

            reg_x <= reg_x << 1;
            reg_y <= reg_y >> 1;
        endrule

        method Action put_x(Int#(32) x) if(!set_x);
            reg_rslt <= 0; 
            reg_x <= x;
            set_x <= True;
        endmethod

        method Action put_y(Int#(32) y)if(!set_y);
            reg_y <= y;
            set_y <= True;
        endmethod

        method Int#(32) result() if((reg_y == 0) && set_x && set_y);
        
            return reg_rslt;
     
        endmethod

    endmodule


/*  Reg#(Bool) reg_set_x <- mkReg(False);
    Reg#(Bool) reg_set_y <- mkReg(False);

        method Bool set_x;
            reg_set_x <= True;
        endmethod

        method Bool set_y;
            reg_set_y <= True;
        endmethod
*/

    module mkTb(Empty);
        Mltplctr_interface dut <- mkMultiplier;

    //Rules und Methoden aufrufen
        rule calc_real;
            dut.put_x(3);
            dut.put_y(2);
        endrule

        rule result_real;
            let val_res = dut.result;
            $display("Result is %0d", val_res);
            $finish(0);
        endrule
    endmodule
endpackage