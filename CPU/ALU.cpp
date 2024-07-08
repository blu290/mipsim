//ALU function

#include "ALU.hpp"
#include <algorithm>

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
    execC(control, A, B);
}

void ALU::execC(int control, int A, int B) {
    switch (control) {
        case 0:
            result = A & B;
            zeroFlag = (result == 0);
            carryFlag = 0;
            overflowFlag = 0;
            break;
        case 1:
            result = A | B;
            zeroFlag = (result == 0);
            carryFlag = 0;
            overflowFlag = 0;
            break;
        case 2:
            result = A + B;
            zeroFlag = (result == 0);
            carryFlag = (result < std::max(A, B));
            overflowFlag = (result < A);
            break;
        case 6:
            result = A - B;
            zeroFlag = (result == 0);
            carryFlag = (result > A);
            overflowFlag = (result < A);
            break;
        case 7:
            result = (A < B);
            zeroFlag = (result == 0);
            carryFlag = 0;
            overflowFlag = 0;
            break;
        case 12:
            result = ~(A | B);
            zeroFlag = (result == 0);
            carryFlag = 0;
            overflowFlag = 0;
            break;
    }
}

void ALU::execL(int control,int A,int B){
    //TODO: implement the ALU in terms of logical operations
    return;
}
