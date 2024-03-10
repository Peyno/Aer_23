package Tb; 
import Vector::*; 

typedef struct{
    Int#(32) opA; 
    Int#(32) opB; 
    AluOps operator; 
    Int#(32) expectedResult; 
} TestData deriving (Eq, Bits); 

module mkAluFSMTB(Empty); 

    Vector#(5, TestData) myVector; 
    myVector[0] = TestData{opA : 2, opB : 4, operator: Add, expectedResult : 6}; 
    myVector[1] = TestData {opA: 2, opB: 4, operator: Mul, expectedResult: 8}; 
    myVector[2] = TestData {opA: 4, opB: 2, operator: Div, expectedResult: 2}; 
    myVector[3] = TestData {opA: 4, opB: 0, operator: Pow, expectedResult: 1}; 
    myVector[4] = TestData {opA: 4, opB: 4, operator: Pow, expectedResult: 256};

    Reg#(UInt#(32)) dataPtr <- mkReg(0); 

    HelloALU uut <- mkHelloALU(); 

    Stmt checkStmt = {
        seq
            action 
                let currentData = myVector[dataPtr]; 
                uut.setupCalculation(currentData.operator, currentData.opA, currentData.opB); 
            endaction 
            action 
                let currentData = myVector[dataPtr]; 
                let result <- uut.getResult(); 
                let print = $format("Calculation : %d ", currentData.opA) + fshow(currentData.operator) + $format("%d", currentData.opB); 
                $display(print); 
                if(result == currentData.expectedResult)begin
                    $display("Result correct : %d", result); 
                end else begin
                    $display("Result incorrect: %d != ", result, currentData.expectedResult); 
                end
            endaction 
        endseq
    }; 

    FSM checkFSM <- mkFS(checkStmt); 

    Stmt mainFSM = {
        seq
            for(dataPtr <= 0; dataPtr < 5; dataPtr <= dataPtr + 1)seq
                checkFSM.start(); 
                checkFSM.waitTillDone(); 
            endseq
        endseq

    }; 
    mkAutoFSM(mainFSM); 

endmodule


endpackage: Tb