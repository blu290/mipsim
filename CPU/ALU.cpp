//ALU function

#include "ALU.hpp"

ALU::ALU() {
    result = 0;
    zeroFlag = 0;
    carryFlag = 0;
    overflowFlag = 0;
}

int ALU::getCarryFlag() {
    return carryFlag;
}

int ALU::getOverflowFlag() {
    return overflowFlag;
}

int ALU::getZeroFlag() {
    return zeroFlag;
}

int ALU::getResult() {
    return result;
}

void ALU::execute(int control, int A, int B){
    //implement the ALU operations in terms of logic
    //this is going to be a fucking headache
    
}



