#include "CPU.hpp"
#include "instructionTypes.hpp"
#include "Rtype.hpp"
#include "Itype.hpp"
#include "Jtype.hpp"
#include <stdexcept>
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
    int instruction = 0;
    try{
    instruction = memory.readWord(cu.getPC());
    }catch(...){
        throw std::runtime_error("not word aligned memory access");
    }
    cu.setPC(cu.getPC() + 4);

    //decode instruction
    InstructionType type = cu.getInstructionType(instruction);
    switch (type) {
        case InstructionType::R:
            RType inst = cu.getInstruction<RType>(instruction);
            //
            break;
        case InstructionType::I:
            IType inst = cu.getInstruction<IType>(instruction);
            break;
        case InstructionType::J:
            JType inst = cu.getInstruction<JType>(instruction);
            break;
    }


}
