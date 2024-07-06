#include "registers.hpp"
#include <iostream>

Registers::Registers() {
    for (int i = 0; i < 32; i++) {
        registers[i] = 0;
    }
}

void Registers::setRegister(int reg, int value) {
    registers[reg] = value;
}

int Registers::getRegister(int reg) {
    return registers[reg];
}

void Registers::printRegisters() {
    for (int i = 0; i < 32; i++) {
        std::cout << regNames[i] << ": " << registers[i] << std::endl;
    }
}

