//class for the control unit
#include "instructionTypes.hpp"
#include "instruction.hpp"
#include "Rtype.hpp"
#include "Itype.hpp"
#include "Jtype.hpp"

#include <type_traits>

class CU {
    public:
        CU() {
        return;
        }

        ~CU() {
            return;
        }
        InstructionType getInstructionType(int instruction);
        
        template <typename T>
        T getInstruction(int instruction) {
            static_assert(std::is_base_of<Instruction, T>::value, "T must be a subclass of Instruction");
            return T(instruction);
        }
    
    int getPC() {
        return PC;
    }
    void setPC(int newPC) {
        PC = newPC;
    }
    int getCIR() {
        return CIR;
    }

    void setCIR(int newCIR) {
        CIR = newCIR;
    }

    private:
        int PC;
        int CIR;
};