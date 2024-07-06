#include "CPU.hpp"
#include <iostream>

CPU::CPU() {
    Registers registers = Registers();
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

