package Watchdog;

    interface Watchdog;
        method Action restart();
    endinterface
    module mkWatchdog#(parameter UInt#(32) initval)(Watchdog);
        Reg#(UInt#(32)) timer <- mkReg(initval);

        rule run(timer > 0);
            timer <= timer - 1;
        endrule

        rule expire(timer == 0);
            $display("Watchdog timed out. Your simulation probably hangs.");
            $finish();
        endrule

        method Action restart();
            timer <= initval;
        endmethod
    endmodule
endpackage : Watchdog