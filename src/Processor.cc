#include "Processor.hh"

Processor::Processor() {
    PC->setValue(PC_START);
    SP->setValue(SP_START);
}

// Flags
void Processor::checkFlagZ(register8_t result) { setFlagZ(result == 0x00); }
void Processor::checkFlagC(int result) { setFlagC(result > 0xFF); }
void Processor::checkFlagH(register8_t result) {
    // TODO double check
    setFlagH((result & 0x10) == 0x10);
}

opcode_t Processor::fetchInstruction() {
    return program_memory->getData(PC->getValue());
}