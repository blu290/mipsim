#include "instruction.hpp"
class IType: public Instruction{
    public:
        IType(int instruction){
            opcode = instruction >> 26;
            rs = (instruction >> 21) & 0x1F;
            rt = (instruction >> 16) & 0x1F;
            imm = instruction & 0xFFFF;
        }
        int opcode;
        int rs;
        int rt;
        int imm;
};