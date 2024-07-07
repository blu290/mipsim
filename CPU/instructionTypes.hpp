enum class InstructionType {
    R, I, J
};

//instruction structs
struct RType {
    int opcode;
    int rs;
    int rt;
    int rd;
    int shamt;
    int funct;
};

struct IType {
    int opcode;
    int rs;
    int rt;
    int imm;
};

struct JType {
    int opcode;
    int target;
};