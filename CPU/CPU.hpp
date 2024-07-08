#include "registers.hpp"
#include "ALU.hpp"
#include "memory.hpp"
#include "CU.hpp"
class CPU{


    public:
        CPU(int memorySize) : registers(), alu(), memory(memorySize), cu() {}
        void printRegisters();
        void setRegister(int reg, int value);
        int getRegister(int reg);
        void run();


        //debug functions
        void insertByte(int address, int data){
            memory.writeByte(address, data);
        }


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
        void execRType(RType inst);
        void execIType(IType inst);
        void execJType(JType inst);
        //function table for R Type instructions
        //same signature so we can use a function table to call the correct function, we can handle the different instructions in the function
        void add(int rd, int rs, int rt);   //100000
        void addu(int rd, int rs, int rt);  //100001
        void andf(int rd, int rs, int rt);  //100100
        void breakf(int rd,int rs,int rt);  //001101
        void div(int rd,int rs, int rt);    //011010
        void divu(int rd,int rs, int rt);   //011011
        void jalr(int rd,int rs, int rt);   //001001
        void jr(int rd,int rs, int rt);     //001000
        void mfhi(int rd,int rs, int rt);   //010000
        void mflo(int rd,int rs, int rt);   //010010
        void mthi(int rd,int rs, int rt);   //010001
        void mtlo(int rd,int rs, int rt);   //010011
        void mult(int rd,int rs, int rt);   //011000
        void multu(int rd,int rs, int rt);  //011001
        void nor(int rd,int rs, int rt);    //100111
        void orf(int rd,int rs, int rt);    //100101
        void sll(int rd,int rs, int rt);    //000000
        void sllv(int rd,int rs, int rt);   //000100
        void slt(int rd,int rs, int rt);    //101010
        void sltu(int rd,int rs, int rt);   //101011
        void sra(int rd,int rs, int rt);    //000011
        void srav(int rd,int rs, int rt);   //000111
        void srl(int rd,int rs, int rt);    //000010
        void srlv(int rd,int rs, int rt);   //000110
        void sub(int rd, int rs, int rt);   //100010
        void subu(int rd, int rs, int rt);  //100011
        void syscall(int rd, int rs, int rt);//001100
        void xorf(int rd, int rs, int rt);   //100110
        
        static void *RTypeJunction[32];


        
};