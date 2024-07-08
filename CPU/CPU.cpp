#include "CPU.hpp"
#include <iostream>

/*CPU::CPU(int memorySize) {
    Registers registers = Registers();
    ALU alu = ALU();
    Memory memory = Memory(memorySize);
    CU cu = CU();
}*/
CPU::CPU(int memorySize) : registers(), alu(), memory(memorySize), cu() {
}

void CPU::printRegisters() {
    registers.printRegisters();
}

void CPU::setRegister(int reg, int value) {
    registers.setRegister(reg, value);
}

int CPU::getRegister(int reg) {
    return registers.getRegister(reg);
}

