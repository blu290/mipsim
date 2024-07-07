//memory class for the CPU
#include <cstdint>
class Memory{
    public:
        Memory(int size);
        ~Memory();
        void writeByte(int address, int data);
        void writeWord(int address, int data);
        uint8_t readByte(int address);
        int readWord(int address);
    private:
        uint8_t* data;
        int size;
        void resize(int newSize);
        uint8_t checkAddress(int address);
};