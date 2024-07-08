#include "registers.hpp"
#include "ALU.hpp"
#include "memory.hpp"
#include "CU.hpp"
class CPU{


    public:
        CPU(int memorySize);
        void printRegisters();
        void setRegister(int reg, int value);
        int getRegister(int reg);
        //instructions 
/*
        //arithmetic
        void add(int rd, int rs, int rt);
        void sub(int rd, int rs, int rt);
        void addi(int rt, int rs, int imm);
        void addu(int rd, int rs, int rt);
        void subu(int rd, int rs, int rt);
        void addiu(int rt, int rs, int imm);
        void mul(int rd, int rs, int rt);
        void mult(int rs, int rt);
        void div(int rs, int rt);
        //logical
        void andf(int rd, int rs, int rt);
        void orf(int rd, int rs, int rt);
        void andi(int rt, int rs, int imm);
        void ori(int rt, int rs, int imm);
        void sll(int rd, int rt, int shamt);
        void srl(int rd, int rt, int shamt);
        //memory
        void lw(int rt, int rs, int offset);
        void sw(int rt, int rs, int offset);
        void lui(int rt, int imm);
        void la(int rt, int imm);
        void li(int rt, int imm);
        void mfhi(int rd);
        void mflo(int rd);
        void move(int rd, int rs);
        //branching
        void beq(int rs, int rt, int offset);
        void bne(int rs, int rt, int offset);
        void bgt(int rs, int rt, int offset);
        void bge(int rs, int rt, int offset);
        void blt(int rs, int rt, int offset);
        void ble(int rs, int rt, int offset);
        //setting
        void slt(int rd, int rs, int rt);
        void slti(int rt, int rs, int imm);
        //jumping
        void j(int target);
        void jal(int target);
        void jr(int rs);
        */


    private:
        Registers registers;
        ALU alu;
        Memory memory;
        CU cu;
};