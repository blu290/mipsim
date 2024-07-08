#include "instruction.hpp"

class JType: public Instruction {
    public:
        JType(int instruction){
            opcode = instruction >> 26;
            target = instruction & 0x3FFFFFF;
        }
        int opcode;
        int target;
};