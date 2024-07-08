#include "instruction.hpp"
#pragma once
class RType: public Instruction{
    public:
        RType(int instruction){
            opcode = instruction >> 26;
            rs = (instruction >> 21) & 0x1F;
            rt = (instruction >> 16) & 0x1F;
            rd = (instruction >> 11) & 0x1F;
            shamt = (instruction >> 6) & 0x1F;
            funct = instruction & 0x3F;
        }
        void execute() {
            return;
        }
        int opcode;
        int rs;
        int rt;
        int rd;
        int shamt;
        int funct;
};
