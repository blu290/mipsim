#include "memory.hpp"

memory::memory(int size) {
    this->size = size;
    data = new uint8_t[size];
}

memory::~memory() {
    delete[] data;
}

void memory::writeByte(int address, int data) {
    try {
        checkAddress(address);
    } catch (const char* msg) {
        throw msg;
    }

    this->data[address] = data;
}

void memory::writeWord(int address, int data) {
    //we need to throw an exception if the address is not divisible by 4
    if (address % 4 != 0) {
        throw "Address is not divisible by 4";
    }

    try {
        checkAddress(address);
        checkAddress(address + 1);
        checkAddress(address + 2);
        checkAddress(address + 3);
    } catch (const char* msg) {
        throw msg;
    }

    this->data[address] = data & 0xF000;
    this->data[address + 1] = data & 0x0F00;
    this->data[address + 2] = data & 0x00F0;
    this->data[address + 3] = data & 0x000F;
}

uint8_t memory::readByte(int address) {
    try {
        checkAddress(address);
    } catch (const char* msg) {
        throw msg;
    }
    return this->data[address];
}

int memory::readWord(int address) {
    //we need to throw an exception if the address is not divisible by 4
    if (address % 4 != 0) {
        throw "Address is not divisible by 4";
    }

    try {
        checkAddress(address);
        checkAddress(address + 1);
        checkAddress(address + 2);
        checkAddress(address + 3);
    } catch (const char* msg) {
        throw msg;
    }

    return (this->data[address] << 12) | (this->data[address + 1] << 8) | (this->data[address + 2] << 4) | this->data[address + 3];
}

void memory::resize(int newSize) {
    uint8_t* newData = new uint8_t[newSize];
    for (int i = 0; i < newSize; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    size = newSize;
}

uint8_t memory::checkAddress(int address) {
    if (address < 0 || address >= size) {
        throw "Address out of bounds";
    }
    return data[address];
}