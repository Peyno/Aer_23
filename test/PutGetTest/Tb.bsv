package Tb; 
import GetPut::*; 
import FIFO::*; 
import StmtFSM::*; 


//keine Typen an Server notwending
    interface Server;
        interface Put#(Int#(32)) request;
        interface Get#(Int#(32)) response;
    endinterface

    module mkToPutTest(Server);
    
        FIFO#(Int #(32)) fifo_in <- mkFIFO;
        FIFO#(Int #(32)) fifo_out <- mkFIFO;

        rule do_sth;
        $display("öalsdj"); 
            let res = fifo_in.first; fifo_in.deq;
            fifo_out.enq(res);
        endrule
        

    //Einfügen & Getten wird extern über TB gemacht
    
        interface request = toPut(fifo_in);
        interface response = toGet(fifo_out);
    
    endmodule

 module mkToPutTestTb(Empty);

        Server server <- mkToPutTest;
        Reg#(Int#(32)) end_result <- mkRegU();
        Reg#(Bool) bol <- mkReg(False);  
       
        rule calc(!bol);
          $display ("Halloasöldfj"); 
            server.request.put(10);
             
        endrule

        rule r2; 
            let result <-server.response.get;
            end_result <= result; 
            bol <= True; 
        endrule


        rule r3(bol); 
        $display("Hallo"); 
            $display("Result is %0d", end_result);
        $finish(0); 
        endrule


    endmodule

    module mkTB (Empty); 
        Server server <- mkToPutTest(); 
        Wire#(Int#(32)) w <- mkWire(); 

        rule r1; 

            server.request.put(10); 

        endrule

        rule r2; 

            let t <-  server.response.get(); 
            w <= t; 
        endrule

        rule r3; 

            $display("Wert = %d", w); 
            $finish; 
        endrule

    endmodule


 module mkTB2 (Empty); 
        Server server <- mkToPutTest(); 
        Reg#(Int#(32)) w <- mkRegU(); 

Stmt s = seq
  
        server.request.put(10); 

        action 

            let t <- server.response.get(); 
            w <= t; 

        endaction 

        $display("Wert : %d", w); 
endseq; 

mkAutoFSM(s); 

    endmodule

endpackage