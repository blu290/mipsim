//the MIPS ALU does the following operations:

// Z is the zero flag, set to 1 if the result is zero
// V is the overflow flag, set to 1 if the result overflows
//C is the carry flag, set to 1 if the result has a carry out

// control: 0000 = AND, Z = 1 if result is zero, V = 0, C = 0
// control: 0001 = OR, Z = 1 if result is zero, V = 0, C = 0
// control: 0010 = ADD, Z = 1 if result is zero, V = 1 if overflow, C = 1 if carry out
// control: 0110 = SUB, Z = 1 if result is zero, V = 1 if overflow, C = 1 if carry out
// control: 0111 = SLT, Z = 1 if result is zero, V = 0, C = 0
// control: 1100 = NOR, Z = 1 if result is zero, V = 0, C = 0


class ALU {
public:
    ALU() {
    result = 0;
    zeroFlag = 0;
    carryFlag = 0;
    overflowFlag = 0;
    hi = 0;
    lo = 0;
    }
    void execute(int control, int A, int B);
    int getResult();
    int getZeroFlag();
    int getCarryFlag();
    int getOverflowFlag();
    int getHi();
    int getLo();
    void setHi(int value);
    void setLo(int value);
    
private:
    int result;
    int zeroFlag;
    int carryFlag;
    int overflowFlag;
    int hi;
    int lo;
    void execL(int control, int A, int B);
    void execC(int control, int A, int B);
};