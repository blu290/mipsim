#include "instruction.hpp"
#pragma once
class JType: public Instruction {
    public:
        JType(int instruction){
            opcode = instruction >> 26;
            target = instruction & 0x3FFFFFF;
        }
        void execute() {
            return;
        }
        int opcode;
        int target;
};