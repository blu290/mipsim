//registers for the mips simulator
/*{"$zero", 
"$at", 
"$v0", "$v1", 
"$a0", "$a1", "$a2", "$a3",
"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7",
"$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
"$t8", "$t9", 
"$k0", "$k1", 
"$gp", "$sp", "$fp", "$ra"};*/
#include <unordered_map>
#include <string>

class Registers {
    public:
        Registers() {
            for (int i = 0; i < 32; i++) {
            registers[i] = 0;
            }
        };
        std::unordered_map<std::string, int> regNames = {
            {"$zero", 0},
            {"$at", 1},
            {"$v0", 2}, {"$v1", 3},
            {"$a0", 4}, {"$a1", 5}, {"$a2", 6}, {"$a3", 7},
            {"$t0", 8}, {"$t1", 9}, {"$t2", 10}, {"$t3", 11}, {"$t4", 12}, {"$t5", 13}, {"$t6", 14}, {"$t7", 15},
            {"$s0", 16}, {"$s1", 17}, {"$s2", 18}, {"$s3", 19}, {"$s4", 20}, {"$s5", 21}, {"$s6", 22}, {"$s7", 23},
            {"$t8", 24}, {"$t9", 25},
            {"$k0", 26}, {"$k1", 27},
            {"$gp", 28}, {"$sp", 29}, {"$fp", 30}, {"$ra", 31}
        };
        //map the register names to their index,
        void setRegister(int reg, int value);
        int getRegister(int reg);
        int getRegister(std::string reg);
        void printRegisters();
    private:
        int registers[32];
        
};