package U2_3;

    interface CalcUnit;
      method Action put(Int#(32) x);
      method ActionValue#(Int#(32)) result();
    endinterface

    interface CalcUnitChangeable;
      interface CalcUnit calc;
      method Action setParameter(Int#(32) param);
    endinterface


    module mkAddA(CalcUnitChangeable); 
      Reg#(Int#(32)) a <- mkRegU; 
      Wire#(Int#(32)) in <- mkWire; 

      method Action setParameter(Int#(32) param); 
        a <= param; 
      endmethod

      interface CalcUnit calc; 
        method Action put(Int#(32) x); 
          in <= x; 
        endmethod

        method ActionValue#(Int#(32)) result(); 
          noAction; 
          return in + a; 
        endmethod
      endinterface
    endmodule

    module mkMul(CalcUnitChangeable); 
      Reg#(Int#(32)) b <- mkRegU; // or c
      Wire#(Int#(32)) in <- mkWire; 

      method Action setParameter(Int#(32) param); 
        b <= param; 
      endmethod

      interface CalcUnit calc; 
        method Action put(Int#(32) x); 
          in <= x; 
        endmethod

        method ActionValue#(Int#(32)) result(); 
          noAction; 
          return in * b; 
        endmethod
      endinterface
    endmodule 

    module mkDiv(CalcUnit); 
      Wire#(Int#(32)) in <- mkWire; 

      method Action put(Int#(32) x); 
        in <= x; 
      endmethod

      method ActionValue#(Int#(32)) result(); 
        noAction; 
        return in / 4; 
      endmethod
    endmodule

    module mkAdd128(CalcUnit); 
      Wire#(Int#(32)) in <- mkWire; 

      method Action put(Int#(32) x); 
        in <= x; 
      endmethod

      method ActionValue#(Int#(32)) result(); 
        noAction; 
        return in + 128; 
      endmethod
    endmodule

    module mkMulVariable(CalcUnitChangeable); 
      Reg#(Int#(32)) p <- mkRegU; 
      Reg#(Int#(32)) a <- mkRegU; 
      Reg#(Int#(32)) b <- mkRegU; 
      Reg#(Int#(32)) w <- mkRegU; 
      Reg#(Bool) got_in <- mkReg(False); 

      rule compute(b != 0 && got_In); 
        if(lsb(b) == 1) w <= w + a; 
        a <= a << 1; 
        b <= b >> 1; 
      endrule

      method Action setParameter(Int#(32) param); 
        p <= param; 
      endmethod

      interface CalcUnit calc; 
        method Action put(Int#(32) x) if(!got_in); 
          a <= x; 
          b <= p; 
          w <= 0; 
          got_in <= True; 
        endmethod

        method ActionValue#(Int#(32)) result() if(b == 0 && got_in); 
          got_in <= False; 
          return w; 
        endmethod
      endinterface
    endmodule




    interface Pipeline;
        interface CalcUnit calc;
        method Action setParam(UInt#(2) addr, Int#(32) val);
    endinterface


    module mkPipeline(Pipeline); 
      CalcUnitChangeable stage0 <- mkAddA; 
      CalcUnitChangeable stage1 <- mkMul; 
      CalcUnitChangeable stage2 <- mkMul; 
      CalcUnit stage3 <- mkDiv4; 
      CalcUnit stage4 <- mkAdd128; 

      Vector#(3, CalcUnitChangeable) changeables; 
      changeables[0] = stage0; 
      changeables[1] = stage1; 
      changeables[2] = stage2; 

      Vector(5, CalcUnit) stages; 
      stages[0] = stage0.calc; 
      stages[1] = stage1.calc; 
      stages[2] = stage2.calc; 
      stages[3] = stage3; 
      stages[4] = stage4; 

      FIFOF#(Int#(32)) fifo_in <- mkFIFOF; 
      FIFO#(Int#(32)) fifo_out <- mkFIFO; 
      Vector#(4, Array#(Reg#(Maybe#(Int#(32))))) regs <- replicateM(mkCReg(2, tagged Invalid)); 

      function Bool setParamAllowed(); 
        Bool allDone = !fifo_in.notEmpty(); 
        for(Integer i = 0; i < 2; i = i + 1) allDone = allDone &&& regs[i][0] matches tagged Invalid ? True : False; 
        return allDone; 
      endfunction

      for(Integer i = 0; i < 5; i = i + 1) begin
          rule push; 
            if(i == 0)
              stages[i].put(fifo_in.first); 
            else if (regs[i-1][0] matches tagged Valid .x)
              stages[i].put(x); 
          endrule
      end

      ule pull_0 if(regs[0][1] matches tagged Invalid);
        fifo_in.deq();
        let t <- stages[0].result();
        regs[0][1] <= tagged Valid t;
    endrule

    for(Integer i = 1; i < 4; i = i + 1) begin
        rule pull if (regs[i][1] matches tagged Invalid &&& isValid(regs[i-1][0]));
            regs[i-1][0] <= tagged Invalid;
            let t <- stages[i].result();
            regs[i][1] <= tagged Valid t;
        endrule
    end

    rule pull_4 if(isValid(regs[3][0]));
        regs[3][0] <= tagged Invalid;
        let t <- stages[4].result();
        fifo_out.enq(t);
    endrule

    method Action setParam(UInt#(2) addr, Int#(32) val) if(setParamAllowed);
        changeables[addr].setParameter(val);
    endmethod

    interface CalcUnit calc;
        method Action put(Int#(32) x);
            fifo_in.enq(x);
        endmethod

        method ActionValue#(Int#(32)) result();
            fifo_out.deq();
            return fifo_out.first;
        endmethod
    endinterface
    endmodule


endpackage