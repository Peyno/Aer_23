package HelloBluespec; 

interface HelloBluespec; 
    (* always_enabled, always_ready *) method Bool led(); 
endinterface


module mkHelloTestbench(Empty); 

    HelloBluespec dut <- mkHelloBluespec(); 
    Reg#(UInt#(32)) counter <- mkReg(0); 
    Reg#(Bool) ledLastCycle <- mkReg(False); 

    rule checkLedStatus; 
        ledLastCycle <= dut.led(); 
        if(ledLastCycle == True && dut.led() == False) $display("LED aus"); 
        else if(ledLastCycle == False && dut.led() == True) $display("LED an"); 
    endrule
   
   

    rule counterIncr; 
        counter <= counter + 1; 
    endrule

    rule endSimulation (counter == 200000000); 
        $finish(); 
    endrule
   



endmodule: mkHelloTestbench





module mkHelloBluespec(HelloBluespec); 

    Reg#(UInt#(25)) counter <- mkReg(0); 
    Reg#(Bool) ledStatus <- mkReg(False); 

    rule count; 
        if(counter == 25'h1ffffff)
            counter <= 0; 
        else
        counter <= counter + 1; 
    endrule

    rule hellodisplay (counter == 25'h1ffffff); 
        $display("(%0d) Hello World!", $time); 
        ledStatus <= !ledStatus; 
    endrule

    method Bool led(); 
        return ledStatus; 
    endmethod

endmodule: mkHelloBluespec


endpackage: HelloBluespec