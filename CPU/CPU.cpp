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
        case InstructionType::R:{
            RType instR = cu.getInstruction<RType>(instruction);
            //
            break;}
        case InstructionType::I:{
            IType instI = cu.getInstruction<IType>(instruction);
            break;}
        case InstructionType::J:{
            JType instJ = cu.getInstruction<JType>(instruction);
            break;}
    }


}

void CPU::add(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(2,rsValue, rtValue);
    if (alu.getOverflowFlag()){
        throw std::runtime_error("overflow");
    }
    int result = alu.getResult();
    registers.setRegister(rd, result);
}

void CPU::addu(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(2,rsValue, rtValue);
    int result = alu.getResult();
    registers.setRegister(rd, result);
}

void CPU::andf(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(0,rsValue, rtValue);
    int result = alu.getResult();
    registers.setRegister(rd, result);
}

void CPU::breakf(int rd, int rs, int rt){
    throw std::runtime_error("break");
}

void CPU::div(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(3,rsValue, rtValue);
}
void CPU::divu(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(3,rsValue, rtValue);
}

void CPU::mult(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(4,rsValue, rtValue);
}

void CPU::multu(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(4,rsValue, rtValue);
}

void CPU::jalr(int rd, int rs, int rt){
    throw std::runtime_error("not implemented");
}

void CPU::jr(int rd, int rs, int rt){
    throw std::runtime_error("not implemented");
}

void CPU::mfhi(int rd, int rs, int rt){
    registers.setRegister(rd, alu.getHi());
}

void CPU::mflo(int rd, int rs, int rt){
    registers.setRegister(rd, alu.getLo());
}

void CPU::mthi(int rd, int rs, int rt){
    alu.setHi(registers.getRegister(rd));
}

void CPU::mtlo(int rd, int rs, int rt){
    alu.setLo(registers.getRegister(rd));
}

void CPU::orf(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(1,rsValue, rtValue);
    int result = alu.getResult();
    registers.setRegister(rd, result);
}

void CPU::xorf(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(5,rsValue, rtValue);
    int result = alu.getResult();
    registers.setRegister(rd, result);
}

void CPU::slt(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(7,rsValue, rtValue);
    int result = alu.getResult();
    registers.setRegister(rd, result);
}

void CPU::sltu(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(7,rsValue, rtValue);
    int result = alu.getResult();
    registers.setRegister(rd, result);
}

void CPU::sra(int rd, int rs, int rt){
    throw std::runtime_error("not implemented");
}

void CPU::srl(int rd, int rs, int rt){
    int rtValue = registers.getRegister(rt);
    int shamt = rtValue & 0x1F;
    int rsValue = registers.getRegister(rs);
    alu.execute(8,rsValue, shamt);
    int result = alu.getResult();
    registers.setRegister(rd, result);
}


void CPU::sub(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(6,rsValue, rtValue);
    if (alu.getOverflowFlag()){
        throw std::runtime_error("overflow");
    }
    int result = alu.getResult();
    registers.setRegister(rd, result);
}

void CPU::subu(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(6,rsValue, rtValue);
    int result = alu.getResult();
    registers.setRegister(rd, result);
}

void CPU::syscall(int rd, int rs, int rt){
    throw std::runtime_error("not implemented");
}

void CPU::xorf(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(5,rsValue, rtValue);
    int result = alu.getResult();
    registers.setRegister(rd, result);
}

void CPU::nor(int rd, int rs, int rt){
    int rsValue = registers.getRegister(rs);
    int rtValue = registers.getRegister(rt);
    alu.execute(1,rsValue, rtValue);
    int result = alu.getResult();
    result = ~result;
    registers.setRegister(rd, result);
}