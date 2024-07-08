#include "CPU.hpp"
#include "instructionTypes.hpp"
#include "Rtype.hpp"
#include "Itype.hpp"
#include "Jtype.hpp"
void CPU::printRegisters() {
    registers.printRegisters();
}

void CPU::setRegister(int reg, int value) {
    registers.setRegister(reg, value);
}

int CPU::getRegister(int reg) {
    return registers.getRegister(reg);
}

void CPU::run(){
    //fetch instruction
    int instruction = memory.readWord(cu.getPC());
    cu.setPC(cu.getPC() + 4);
    //decode instruction
    Instruction* inst;
    InstructionType type = cu.getInstructionType(instruction);
    switch (type) {
        case InstructionType::R:
            inst = &cu.getInstruction<RType>(instruction);
            break;
        case InstructionType::I:
            inst = &cu.getInstruction<IType>(instruction);
            break;
        case InstructionType::J:
            inst = &cu.getInstruction<JType>(instruction);
            break;
    }
    

}
