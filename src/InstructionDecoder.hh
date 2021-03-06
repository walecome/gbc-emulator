#pragma once

// System headers
#include <array>
#include <memory>

// User headers
#include "Constants.hh"
#include "Memory.hh"
#include "Processor.hh"
#include "Register16bit.hh"
#include "Register8bit.hh"
#include "Timings.hh"

class InstructionDecoder {
   public:
    InstructionDecoder(ptr<Processor> processor);

    /**
        Execute the corresponding opcode function for the passed opcode.
        Lookup is done in the opcode_functions table.
    */
    void executeInstruction(opcode_t opcode);

    /**
        Execute the corresponding opcode_cb function for the passed opcode.
        Lookup is done in the opcode_cb_functions table.
    */
    void executeCBInstruction(opcode_t opcode);

    /**
     *  Does a CPU step by fetching the current instruction pointed at by the
     *  program counter, then increasing the program counter and executes the
     *  fetched instruction. If it is a CB instruction, the fetches that one,
     *  meaning the program counter will be incremented twice.
     */
    void step(bool verbose = false);

   private:
    // Keep pointer to CPU and registers
    ptr<Processor> cpu;

    ptr<Memory> program_memory, stack;
    ptr<Register16bit> SP, PC;
    ptr<Register8bit> A, B, C, D, E, F, H, L;
    ptr<Register16bit> AF, BC, DE, HL;

    std::array<opcode_function, NUMBER_OF_INSTRUCTIONS> opcode_functions {};
    std::array<opcode_function, NUMBER_OF_INSTRUCTIONS> opcode_cb_functions {};

    /**
    *   Maps the opcode functions to their correct index in the opcode_functions
        and opcode_cb_functions table.
    */
    void map_opcode_functions();
    void map_regular_opcodes();
    void map_cb_opcodes();

    // Opcode helpers

    /**
        Fetches the instruction currently pointed at by the program counter.
        Also increments the program counter to point at next instruction/data.
    */
    opcode_t fetchInstruction();

    /**
        Get the data pointed to by the program counter and increment the program
        counter.
    */
    byte_t getInstructionData();

    /**
        Loads data from where the program counter is pointing into the given
       register. Also increments the program counter.
    */
    void loadRegister(const ptr<Register8bit> &reg);

    /**
        Loads the data in data_reg into (address_reg).
        TODO double check that this works with program_memory.
    */
    void loadIntoMemory(const ptr<Register16bit> &address_reg,
                        const ptr<Register8bit> &data_reg);

    /**
        Loads the data in value into the address in (address_reg)
    */
    void loadIntoMemory(const ptr<Register16bit> &address_reg, byte_t value);

    /**
        Loads data from the memory address stored in (address_reg) and
       stores it in data_reg.
    */
    void loadFromMemory(const ptr<Register8bit> &data_reg,
                        const ptr<Register16bit> &address_reg);

    /**
        Loads from memory address (address_reg) and returns it.
    */
    byte_t loadFromMemory(const ptr<Register16bit> &address_reg);

    /**
        Increments the value of the passed register and sets flags accordingly.
        This function is only for 8bit registers since 16bit register increment
        doesn't affect flags.
    */
    void incrementRegister(const ptr<Register8bit> &reg);

    /**
        Decrements the value of the passed register and sets flags accordingly.
        This function is only for 8bit registers since 16bit register decrement
        doesn't affect flags.
    */
    void decrementRegister(const ptr<Register8bit> &reg);

    /**
        Copies the value from the destination register to the source register
    */
    void copyRegister(const ptr<Register8bit> &destination,
                      const ptr<Register8bit> &source);

    /**
        Adds the values in the destination and source registers and stores the
        result in the destination register
    */
    void addRegisters(const ptr<Register8bit> &destination,
                      const ptr<Register8bit> &source);

    /**
        Adds the values in the destination and source registers and stores the
        result in the destination register
    */
    void addRegisters(const ptr<Register16bit> &destination,
                      const ptr<Register16bit> &source);

    /**
        Subtracts the value in the accumulator (reg A) with the value in the
        source register and stores the results in the accumulator
    */
    void subRegisters(const ptr<Register8bit> &source);

    /**
        Adds registers with the carry included in the addition
    */
    void addWithCarry(const ptr<Register8bit> &destination,
                      const ptr<Register8bit> &source);

    /**
        Subtracts the value in the accumulator (reg A) with the value in the
       source register. The subtraction also includes the carry value. Result is
       stored in the accumulator.
    */
    void subWithCarry(const ptr<Register8bit> &source);

    /**
        Performs a bitwise AND operation with the accumulator (reg A) and the
       passed in register. The result is stored in the accumulator.
    */
    void andRegisters(const ptr<Register8bit> &source);

    /**
        Performs a bitwise XOR operation with the accumulator (reg A) and the
       passed in register. The result is stored in the accumulator.
    */
    void xorRegisters(const ptr<Register8bit> &source);

    /**
        Performs a bitwise OR operation with the accumulator (reg A) and the
       passed in register. The result is store in the accumulator.
    */
    void orRegisters(const ptr<Register8bit> &source);

    /**
        Compares the value in the passed in register with the value in the
        accumulator (reg A). Sets flags as a regular subtraction but the result
        of the subtraction is not used.
    */
    void cmpRegisters(const ptr<Register8bit> &source);

    /**
        Pushes the value in the passed 16bit register into the program stack.
        This will decrement the stack pointer by 2.
    */
    void pushStack(const ptr<Register16bit> &source);

    /**
        Pops a 16bit value from the stack and stores the values in the passed in
        register. This will increment the stack pointer by 2.
    */
    void popStack(const ptr<Register16bit> &destination);

    /**
        Perform jump. Modifies the program counter by adding it to the value
       that is currently pointed at by the program counter.
    */
    void performJump();

    /**
        Performs a jump to a 16bit address stored in the program memory.
    */
    void jumpIm16bit();

    /**
        Performs a left bitwise rotation on the given register. MSB will also be
        stored in the carry flag.
    */
    void rlcRegister(const ptr<Register8bit> &source);

    /**
        Performs a right bitwise rotation on the given register. LSB will also
       be stored in the carry flag.
    */
    void rrcRegister(const ptr<Register8bit> &source);

    /**
        Performs a left bitwise rotation through the carry given the register.
    */
    void rlRegister(const ptr<Register8bit> &source);

    /**
        Performs a right bitwise rotation through the carry given the register.
    */
    void rrRegister(const ptr<Register8bit> &source);

    /**
        Performs a left bitwise shift into the carry.
    */
    void slaRegister(const ptr<Register8bit> &source);

    /**
        Performs a right bitwise shift into carry. Perserves MSB.
    */
    void sraRegister(const ptr<Register8bit> &source);

    /**
        Swaps the upper and lower nibbles of given register.
    */
    void swapNibbles(const ptr<Register8bit> &reg);

    /**
        Performs a right bitwise shift into carry. MSB is set to 0.
    */
    void srlRegister(const ptr<Register8bit> &reg);

    /**
        Tests bit b of register reg.
    */
    void testBit(int b, const ptr<Register8bit> &reg);

    /**
        Test bit b of data at address in address_reg.
    */
    void testBit(int b, const ptr<Register16bit> &reg);

    /**
        Sets bit b in reg to 0.
    */
    void resetBit(int b, const ptr<Register8bit> &reg);

    /**
        Sets bit b in data located at address of address_reg to 0.
    */
    void resetBit(int b, const ptr<Register16bit> &address_reg);

    /**
        Sets bit b in reg to 1.
    */
    void setBit(int b, const ptr<Register8bit> &reg);

    /**
        Sets bit b in data located at address of address_reg to 1.
    */
    void setBit(int b, const ptr<Register16bit> &reg);

    // Regular opcodes
    void OPCode0x00();
    void OPCode0x01();
    void OPCode0x02();
    void OPCode0x03();
    void OPCode0x04();
    void OPCode0x05();
    void OPCode0x06();
    void OPCode0x07();
    void OPCode0x08();
    void OPCode0x09();
    void OPCode0x0A();
    void OPCode0x0B();
    void OPCode0x0C();
    void OPCode0x0D();
    void OPCode0x0E();
    void OPCode0x0F();
    void OPCode0x10();
    void OPCode0x11();
    void OPCode0x12();
    void OPCode0x13();
    void OPCode0x14();
    void OPCode0x15();
    void OPCode0x16();
    void OPCode0x17();
    void OPCode0x18();
    void OPCode0x19();
    void OPCode0x1A();
    void OPCode0x1B();
    void OPCode0x1C();
    void OPCode0x1D();
    void OPCode0x1E();
    void OPCode0x1F();
    void OPCode0x20();
    void OPCode0x21();
    void OPCode0x22();
    void OPCode0x23();
    void OPCode0x24();
    void OPCode0x25();
    void OPCode0x26();
    void OPCode0x27();
    void OPCode0x28();
    void OPCode0x29();
    void OPCode0x2A();
    void OPCode0x2B();
    void OPCode0x2C();
    void OPCode0x2D();
    void OPCode0x2E();
    void OPCode0x2F();
    void OPCode0x30();
    void OPCode0x31();
    void OPCode0x32();
    void OPCode0x33();
    void OPCode0x34();
    void OPCode0x35();
    void OPCode0x36();
    void OPCode0x37();
    void OPCode0x38();
    void OPCode0x39();
    void OPCode0x3A();
    void OPCode0x3B();
    void OPCode0x3C();
    void OPCode0x3D();
    void OPCode0x3E();
    void OPCode0x3F();
    void OPCode0x40();
    void OPCode0x41();
    void OPCode0x42();
    void OPCode0x43();
    void OPCode0x44();
    void OPCode0x45();
    void OPCode0x46();
    void OPCode0x47();
    void OPCode0x48();
    void OPCode0x49();
    void OPCode0x4A();
    void OPCode0x4B();
    void OPCode0x4C();
    void OPCode0x4D();
    void OPCode0x4E();
    void OPCode0x4F();
    void OPCode0x50();
    void OPCode0x51();
    void OPCode0x52();
    void OPCode0x53();
    void OPCode0x54();
    void OPCode0x55();
    void OPCode0x56();
    void OPCode0x57();
    void OPCode0x58();
    void OPCode0x59();
    void OPCode0x5A();
    void OPCode0x5B();
    void OPCode0x5C();
    void OPCode0x5D();
    void OPCode0x5E();
    void OPCode0x5F();
    void OPCode0x60();
    void OPCode0x61();
    void OPCode0x62();
    void OPCode0x63();
    void OPCode0x64();
    void OPCode0x65();
    void OPCode0x66();
    void OPCode0x67();
    void OPCode0x68();
    void OPCode0x69();
    void OPCode0x6A();
    void OPCode0x6B();
    void OPCode0x6C();
    void OPCode0x6D();
    void OPCode0x6E();
    void OPCode0x6F();
    void OPCode0x70();
    void OPCode0x71();
    void OPCode0x72();
    void OPCode0x73();
    void OPCode0x74();
    void OPCode0x75();
    void OPCode0x76();
    void OPCode0x77();
    void OPCode0x78();
    void OPCode0x79();
    void OPCode0x7A();
    void OPCode0x7B();
    void OPCode0x7C();
    void OPCode0x7D();
    void OPCode0x7E();
    void OPCode0x7F();
    void OPCode0x80();
    void OPCode0x81();
    void OPCode0x82();
    void OPCode0x83();
    void OPCode0x84();
    void OPCode0x85();
    void OPCode0x86();
    void OPCode0x87();
    void OPCode0x88();
    void OPCode0x89();
    void OPCode0x8A();
    void OPCode0x8B();
    void OPCode0x8C();
    void OPCode0x8D();
    void OPCode0x8E();
    void OPCode0x8F();
    void OPCode0x90();
    void OPCode0x91();
    void OPCode0x92();
    void OPCode0x93();
    void OPCode0x94();
    void OPCode0x95();
    void OPCode0x96();
    void OPCode0x97();
    void OPCode0x98();
    void OPCode0x99();
    void OPCode0x9A();
    void OPCode0x9B();
    void OPCode0x9C();
    void OPCode0x9D();
    void OPCode0x9E();
    void OPCode0x9F();
    void OPCode0xA0();
    void OPCode0xA1();
    void OPCode0xA2();
    void OPCode0xA3();
    void OPCode0xA4();
    void OPCode0xA5();
    void OPCode0xA6();
    void OPCode0xA7();
    void OPCode0xA8();
    void OPCode0xA9();
    void OPCode0xAA();
    void OPCode0xAB();
    void OPCode0xAC();
    void OPCode0xAD();
    void OPCode0xAE();
    void OPCode0xAF();
    void OPCode0xB0();
    void OPCode0xB1();
    void OPCode0xB2();
    void OPCode0xB3();
    void OPCode0xB4();
    void OPCode0xB5();
    void OPCode0xB6();
    void OPCode0xB7();
    void OPCode0xB8();
    void OPCode0xB9();
    void OPCode0xBA();
    void OPCode0xBB();
    void OPCode0xBC();
    void OPCode0xBD();
    void OPCode0xBE();
    void OPCode0xBF();
    void OPCode0xC0();
    void OPCode0xC1();
    void OPCode0xC2();
    void OPCode0xC3();
    void OPCode0xC4();
    void OPCode0xC5();
    void OPCode0xC6();
    void OPCode0xC7();
    void OPCode0xC8();
    void OPCode0xC9();
    void OPCode0xCA();
    void OPCode0xCB();
    void OPCode0xCC();
    void OPCode0xCD();
    void OPCode0xCE();
    void OPCode0xCF();
    void OPCode0xD0();
    void OPCode0xD1();
    void OPCode0xD2();
    void OPCode0xD3();
    void OPCode0xD4();
    void OPCode0xD5();
    void OPCode0xD6();
    void OPCode0xD7();
    void OPCode0xD8();
    void OPCode0xD9();
    void OPCode0xDA();
    void OPCode0xDB();
    void OPCode0xDC();
    void OPCode0xDD();
    void OPCode0xDE();
    void OPCode0xDF();
    void OPCode0xE0();
    void OPCode0xE1();
    void OPCode0xE2();
    void OPCode0xE3();
    void OPCode0xE4();
    void OPCode0xE5();
    void OPCode0xE6();
    void OPCode0xE7();
    void OPCode0xE8();
    void OPCode0xE9();
    void OPCode0xEA();
    void OPCode0xEB();
    void OPCode0xEC();
    void OPCode0xED();
    void OPCode0xEE();
    void OPCode0xEF();
    void OPCode0xF0();
    void OPCode0xF1();
    void OPCode0xF2();
    void OPCode0xF3();
    void OPCode0xF4();
    void OPCode0xF5();
    void OPCode0xF6();
    void OPCode0xF7();
    void OPCode0xF8();
    void OPCode0xF9();
    void OPCode0xFA();
    void OPCode0xFB();
    void OPCode0xFC();
    void OPCode0xFD();
    void OPCode0xFE();
    void OPCode0xFF();

    // Opcodes with CB prefix
    void OPCodeCB0x00();
    void OPCodeCB0x01();
    void OPCodeCB0x02();
    void OPCodeCB0x03();
    void OPCodeCB0x04();
    void OPCodeCB0x05();
    void OPCodeCB0x06();
    void OPCodeCB0x07();
    void OPCodeCB0x08();
    void OPCodeCB0x09();
    void OPCodeCB0x0A();
    void OPCodeCB0x0B();
    void OPCodeCB0x0C();
    void OPCodeCB0x0D();
    void OPCodeCB0x0E();
    void OPCodeCB0x0F();
    void OPCodeCB0x10();
    void OPCodeCB0x11();
    void OPCodeCB0x12();
    void OPCodeCB0x13();
    void OPCodeCB0x14();
    void OPCodeCB0x15();
    void OPCodeCB0x16();
    void OPCodeCB0x17();
    void OPCodeCB0x18();
    void OPCodeCB0x19();
    void OPCodeCB0x1A();
    void OPCodeCB0x1B();
    void OPCodeCB0x1C();
    void OPCodeCB0x1D();
    void OPCodeCB0x1E();
    void OPCodeCB0x1F();
    void OPCodeCB0x20();
    void OPCodeCB0x21();
    void OPCodeCB0x22();
    void OPCodeCB0x23();
    void OPCodeCB0x24();
    void OPCodeCB0x25();
    void OPCodeCB0x26();
    void OPCodeCB0x27();
    void OPCodeCB0x28();
    void OPCodeCB0x29();
    void OPCodeCB0x2A();
    void OPCodeCB0x2B();
    void OPCodeCB0x2C();
    void OPCodeCB0x2D();
    void OPCodeCB0x2E();
    void OPCodeCB0x2F();
    void OPCodeCB0x30();
    void OPCodeCB0x31();
    void OPCodeCB0x32();
    void OPCodeCB0x33();
    void OPCodeCB0x34();
    void OPCodeCB0x35();
    void OPCodeCB0x36();
    void OPCodeCB0x37();
    void OPCodeCB0x38();
    void OPCodeCB0x39();
    void OPCodeCB0x3A();
    void OPCodeCB0x3B();
    void OPCodeCB0x3C();
    void OPCodeCB0x3D();
    void OPCodeCB0x3E();
    void OPCodeCB0x3F();
    void OPCodeCB0x40();
    void OPCodeCB0x41();
    void OPCodeCB0x42();
    void OPCodeCB0x43();
    void OPCodeCB0x44();
    void OPCodeCB0x45();
    void OPCodeCB0x46();
    void OPCodeCB0x47();
    void OPCodeCB0x48();
    void OPCodeCB0x49();
    void OPCodeCB0x4A();
    void OPCodeCB0x4B();
    void OPCodeCB0x4C();
    void OPCodeCB0x4D();
    void OPCodeCB0x4E();
    void OPCodeCB0x4F();
    void OPCodeCB0x50();
    void OPCodeCB0x51();
    void OPCodeCB0x52();
    void OPCodeCB0x53();
    void OPCodeCB0x54();
    void OPCodeCB0x55();
    void OPCodeCB0x56();
    void OPCodeCB0x57();
    void OPCodeCB0x58();
    void OPCodeCB0x59();
    void OPCodeCB0x5A();
    void OPCodeCB0x5B();
    void OPCodeCB0x5C();
    void OPCodeCB0x5D();
    void OPCodeCB0x5E();
    void OPCodeCB0x5F();
    void OPCodeCB0x60();
    void OPCodeCB0x61();
    void OPCodeCB0x62();
    void OPCodeCB0x63();
    void OPCodeCB0x64();
    void OPCodeCB0x65();
    void OPCodeCB0x66();
    void OPCodeCB0x67();
    void OPCodeCB0x68();
    void OPCodeCB0x69();
    void OPCodeCB0x6A();
    void OPCodeCB0x6B();
    void OPCodeCB0x6C();
    void OPCodeCB0x6D();
    void OPCodeCB0x6E();
    void OPCodeCB0x6F();
    void OPCodeCB0x70();
    void OPCodeCB0x71();
    void OPCodeCB0x72();
    void OPCodeCB0x73();
    void OPCodeCB0x74();
    void OPCodeCB0x75();
    void OPCodeCB0x76();
    void OPCodeCB0x77();
    void OPCodeCB0x78();
    void OPCodeCB0x79();
    void OPCodeCB0x7A();
    void OPCodeCB0x7B();
    void OPCodeCB0x7C();
    void OPCodeCB0x7D();
    void OPCodeCB0x7E();
    void OPCodeCB0x7F();
    void OPCodeCB0x80();
    void OPCodeCB0x81();
    void OPCodeCB0x82();
    void OPCodeCB0x83();
    void OPCodeCB0x84();
    void OPCodeCB0x85();
    void OPCodeCB0x86();
    void OPCodeCB0x87();
    void OPCodeCB0x88();
    void OPCodeCB0x89();
    void OPCodeCB0x8A();
    void OPCodeCB0x8B();
    void OPCodeCB0x8C();
    void OPCodeCB0x8D();
    void OPCodeCB0x8E();
    void OPCodeCB0x8F();
    void OPCodeCB0x90();
    void OPCodeCB0x91();
    void OPCodeCB0x92();
    void OPCodeCB0x93();
    void OPCodeCB0x94();
    void OPCodeCB0x95();
    void OPCodeCB0x96();
    void OPCodeCB0x97();
    void OPCodeCB0x98();
    void OPCodeCB0x99();
    void OPCodeCB0x9A();
    void OPCodeCB0x9B();
    void OPCodeCB0x9C();
    void OPCodeCB0x9D();
    void OPCodeCB0x9E();
    void OPCodeCB0x9F();
    void OPCodeCB0xA0();
    void OPCodeCB0xA1();
    void OPCodeCB0xA2();
    void OPCodeCB0xA3();
    void OPCodeCB0xA4();
    void OPCodeCB0xA5();
    void OPCodeCB0xA6();
    void OPCodeCB0xA7();
    void OPCodeCB0xA8();
    void OPCodeCB0xA9();
    void OPCodeCB0xAA();
    void OPCodeCB0xAB();
    void OPCodeCB0xAC();
    void OPCodeCB0xAD();
    void OPCodeCB0xAE();
    void OPCodeCB0xAF();
    void OPCodeCB0xB0();
    void OPCodeCB0xB1();
    void OPCodeCB0xB2();
    void OPCodeCB0xB3();
    void OPCodeCB0xB4();
    void OPCodeCB0xB5();
    void OPCodeCB0xB6();
    void OPCodeCB0xB7();
    void OPCodeCB0xB8();
    void OPCodeCB0xB9();
    void OPCodeCB0xBA();
    void OPCodeCB0xBB();
    void OPCodeCB0xBC();
    void OPCodeCB0xBD();
    void OPCodeCB0xBE();
    void OPCodeCB0xBF();
    void OPCodeCB0xC0();
    void OPCodeCB0xC1();
    void OPCodeCB0xC2();
    void OPCodeCB0xC3();
    void OPCodeCB0xC4();
    void OPCodeCB0xC5();
    void OPCodeCB0xC6();
    void OPCodeCB0xC7();
    void OPCodeCB0xC8();
    void OPCodeCB0xC9();
    void OPCodeCB0xCA();
    void OPCodeCB0xCB();
    void OPCodeCB0xCC();
    void OPCodeCB0xCD();
    void OPCodeCB0xCE();
    void OPCodeCB0xCF();
    void OPCodeCB0xD0();
    void OPCodeCB0xD1();
    void OPCodeCB0xD2();
    void OPCodeCB0xD3();
    void OPCodeCB0xD4();
    void OPCodeCB0xD5();
    void OPCodeCB0xD6();
    void OPCodeCB0xD7();
    void OPCodeCB0xD8();
    void OPCodeCB0xD9();
    void OPCodeCB0xDA();
    void OPCodeCB0xDB();
    void OPCodeCB0xDC();
    void OPCodeCB0xDD();
    void OPCodeCB0xDE();
    void OPCodeCB0xDF();
    void OPCodeCB0xE0();
    void OPCodeCB0xE1();
    void OPCodeCB0xE2();
    void OPCodeCB0xE3();
    void OPCodeCB0xE4();
    void OPCodeCB0xE5();
    void OPCodeCB0xE6();
    void OPCodeCB0xE7();
    void OPCodeCB0xE8();
    void OPCodeCB0xE9();
    void OPCodeCB0xEA();
    void OPCodeCB0xEB();
    void OPCodeCB0xEC();
    void OPCodeCB0xED();
    void OPCodeCB0xEE();
    void OPCodeCB0xEF();
    void OPCodeCB0xF0();
    void OPCodeCB0xF1();
    void OPCodeCB0xF2();
    void OPCodeCB0xF3();
    void OPCodeCB0xF4();
    void OPCodeCB0xF5();
    void OPCodeCB0xF6();
    void OPCodeCB0xF7();
    void OPCodeCB0xF8();
    void OPCodeCB0xF9();
    void OPCodeCB0xFA();
    void OPCodeCB0xFB();
    void OPCodeCB0xFC();
    void OPCodeCB0xFD();
    void OPCodeCB0xFE();
    void OPCodeCB0xFF();
};