#include "CU.hpp"
#include "instructionTypes.hpp"
CU::CU() {
    
}

CU::~CU() {
    
}

InstructionType CU::getInstructionType(int instruction) {
    //we need the first 6 bits of the instruction to determine the type
    instruction = instruction >> 26;
    //type 0 is R-type
    if (instruction == 0) {
        return InstructionType::R;
    }
    if (instruction == 2 || instruction == 3) {
        return InstructionType::J;
    }
    return InstructionType::I;

}