#include "InstructionDecoder.hh"

void InstructionDecoder::OPCodeCB0x00() {
    // RLC B
    rlcRegister(B);
}

void InstructionDecoder::OPCodeCB0x01() {
    // RLC C
    rlcRegister(C);
}

void InstructionDecoder::OPCodeCB0x02() {
    // RLC D
    rlcRegister(D);
}

void InstructionDecoder::OPCodeCB0x03() {
    // RLC E
    rlcRegister(E);
}

void InstructionDecoder::OPCodeCB0x04() {
    // RLC H
    rlcRegister(H);
}

void InstructionDecoder::OPCodeCB0x05() {
    // RLC L
    rlcRegister(L);
}

void InstructionDecoder::OPCodeCB0x06() {
    // RLC (HL)

    // TODO test
    ptr<Register8bit> tmp { std::make_shared<Register8bit>("tmp") };
    loadFromMemory(tmp, HL);
    rlcRegister(tmp);
    loadIntoMemory(HL, tmp);
}

void InstructionDecoder::OPCodeCB0x07() {
    // RLC A
    rlcRegister(A);
}

void InstructionDecoder::OPCodeCB0x08() {
    // RRC B
    rrcRegister(B);
}

void InstructionDecoder::OPCodeCB0x09() {
    // RRC C
    rrcRegister(C);
}

void InstructionDecoder::OPCodeCB0x0A() {
    // RRC D
    rrcRegister(D);
}

void InstructionDecoder::OPCodeCB0x0B() {
    // RRC E
    rrcRegister(E);
}

void InstructionDecoder::OPCodeCB0x0C() {
    // RRC H
    rrcRegister(H);
}

void InstructionDecoder::OPCodeCB0x0D() {
    // RRC L
    rrcRegister(L);
}

void InstructionDecoder::OPCodeCB0x0E() {
    // RRC (HL)
    // TODO test

    ptr<Register8bit> tmp { std::make_shared<Register8bit>("tmp") };
    loadFromMemory(tmp, HL);
    rrcRegister(tmp);
    loadIntoMemory(HL, tmp);
}

void InstructionDecoder::OPCodeCB0x0F() {
    // RRC A
    rrcRegister(A);
}

void InstructionDecoder::OPCodeCB0x10() {
    // RL B
    rlRegister(B);
}

void InstructionDecoder::OPCodeCB0x11() {
    // RL C
    rlRegister(C);
}

void InstructionDecoder::OPCodeCB0x12() {
    // RL D
    rlRegister(D);
}

void InstructionDecoder::OPCodeCB0x13() {
    // RL E
    rlRegister(E);
}

void InstructionDecoder::OPCodeCB0x14() {
    // RL H
    rlRegister(H);
}

void InstructionDecoder::OPCodeCB0x15() {
    // RL L
    rlRegister(L);
}

void InstructionDecoder::OPCodeCB0x16() {
    // RL (HL)

    // TODO test
    ptr<Register8bit> tmp { std::make_shared<Register8bit>("tmp") };
    loadFromMemory(tmp, HL);
    rlRegister(tmp);
    loadIntoMemory(HL, tmp);
}

void InstructionDecoder::OPCodeCB0x17() {
    // RL A
    rlRegister(A);
}

void InstructionDecoder::OPCodeCB0x18() {
    // RR B
    rrRegister(B);
}

void InstructionDecoder::OPCodeCB0x19() {
    // RR C
    rrRegister(C);
}

void InstructionDecoder::OPCodeCB0x1A() {
    // RR D
    rrRegister(D);
}

void InstructionDecoder::OPCodeCB0x1B() {
    // RR E
    rrRegister(E);
}

void InstructionDecoder::OPCodeCB0x1C() {
    // RR H
    rrRegister(H);
}

void InstructionDecoder::OPCodeCB0x1D() {
    // RR L
    rrRegister(L);
}

void InstructionDecoder::OPCodeCB0x1E() {
    // RR (HL)

    // TODO test
    ptr<Register8bit> tmp { std::make_shared<Register8bit>("tmp") };
    loadFromMemory(tmp, HL);
    rrRegister(tmp);
    loadIntoMemory(HL, tmp);
}

void InstructionDecoder::OPCodeCB0x1F() {
    // RR A
    rrRegister(A);
}

void InstructionDecoder::OPCodeCB0x20() {
    // SLA B
    slaRegister(B);
}

void InstructionDecoder::OPCodeCB0x21() {
    // SLA C
    slaRegister(C);
}

void InstructionDecoder::OPCodeCB0x22() {
    // SLA D
    slaRegister(D);
}

void InstructionDecoder::OPCodeCB0x23() {
    // SLA E
    slaRegister(E);
}

void InstructionDecoder::OPCodeCB0x24() {
    // SLA H
    slaRegister(H);
}

void InstructionDecoder::OPCodeCB0x25() {
    // SLA L
    slaRegister(L);
}

void InstructionDecoder::OPCodeCB0x26() {
    // SLA (HL)

    // TODO test
    ptr<Register8bit> tmp { std::make_shared<Register8bit>("tmp") };
    loadFromMemory(tmp, HL);
    slaRegister(tmp);
    loadIntoMemory(HL, tmp);
}

void InstructionDecoder::OPCodeCB0x27() {
    // SLA A
    slaRegister(A);
}

void InstructionDecoder::OPCodeCB0x28() {
    // SRA B
    sraRegister(B);
}

void InstructionDecoder::OPCodeCB0x29() {
    // SRA C
    sraRegister(C);
}

void InstructionDecoder::OPCodeCB0x2A() {
    // SRA D
    sraRegister(D);
}

void InstructionDecoder::OPCodeCB0x2B() {
    // SRA E
    sraRegister(E);
}

void InstructionDecoder::OPCodeCB0x2C() {
    // SRA H
    sraRegister(H);
}

void InstructionDecoder::OPCodeCB0x2D() {
    // SRA L
    sraRegister(L);
}

void InstructionDecoder::OPCodeCB0x2E() {
    // SRA (HL)

    // TODO test
    ptr<Register8bit> tmp { std::make_shared<Register8bit>("tmp") };
    loadFromMemory(tmp, HL);
    sraRegister(tmp);
    loadIntoMemory(HL, tmp);
}

void InstructionDecoder::OPCodeCB0x2F() {
    // SRA A
    sraRegister(A);
}

void InstructionDecoder::OPCodeCB0x30() {
    // SWAP B
    swapNibbles(B);
}

void InstructionDecoder::OPCodeCB0x31() {
    // SWAP C
    swapNibbles(C);
}

void InstructionDecoder::OPCodeCB0x32() {
    // SWAP D
    swapNibbles(D);
}

void InstructionDecoder::OPCodeCB0x33() {
    // SWAP E
    swapNibbles(E);
}

void InstructionDecoder::OPCodeCB0x34() {
    // SWAP H
    swapNibbles(H);
}

void InstructionDecoder::OPCodeCB0x35() {
    // SWAP L
    swapNibbles(L);
}

void InstructionDecoder::OPCodeCB0x36() {
    // SWAP (HL)

    // TODO test
    ptr<Register8bit> tmp { std::make_shared<Register8bit>("tmp") };
    loadFromMemory(tmp, HL);
    swapNibbles(tmp);
    loadIntoMemory(HL, tmp);
}

void InstructionDecoder::OPCodeCB0x37() {
    // SWAP A
    swapNibbles(A);
}

void InstructionDecoder::OPCodeCB0x38() {
    // SRL B
    srlRegister(B);
}

void InstructionDecoder::OPCodeCB0x39() {
    // SRL C
    srlRegister(C);
}

void InstructionDecoder::OPCodeCB0x3A() {
    // SRL D
    srlRegister(D);
}

void InstructionDecoder::OPCodeCB0x3B() {
    // SRL E
    srlRegister(E);
}

void InstructionDecoder::OPCodeCB0x3C() {
    // SRL H
    srlRegister(H);
}

void InstructionDecoder::OPCodeCB0x3D() {
    // SRL L
    srlRegister(L);
}

void InstructionDecoder::OPCodeCB0x3E() {
    // SRL (HL)

    // TODO test
    ptr<Register8bit> tmp { std::make_shared<Register8bit>("tmp") };
    loadFromMemory(tmp, HL);
    srlRegister(tmp);
    loadIntoMemory(HL, tmp);
}

void InstructionDecoder::OPCodeCB0x3F() {
    // SRL A
    srlRegister(A);
}

void InstructionDecoder::OPCodeCB0x40() {
    // BIT 0, B
    testBit(0, B);
}

void InstructionDecoder::OPCodeCB0x41() {
    // BIT 0, C
    testBit(0, C);
}

void InstructionDecoder::OPCodeCB0x42() {
    // BIT 0, D
    testBit(0, D);
}

void InstructionDecoder::OPCodeCB0x43() {
    // BIT 0, E
    testBit(0, E);
}

void InstructionDecoder::OPCodeCB0x44() {
    // BIT 0, H
    testBit(0, H);
}

void InstructionDecoder::OPCodeCB0x45() {
    // BIT 0, L
    testBit(0, L);
}

void InstructionDecoder::OPCodeCB0x46() {
    // BIT 0, (HL)
    testBit(0, HL);
}

void InstructionDecoder::OPCodeCB0x47() {
    // BIT 0, A
    testBit(0, A);
}

void InstructionDecoder::OPCodeCB0x48() {
    // BIT 1, B
    testBit(1, B);
}

void InstructionDecoder::OPCodeCB0x49() {
    // BIT 1, C
    testBit(1, C);
}

void InstructionDecoder::OPCodeCB0x4A() {
    // BIT 1, D
    testBit(1, D);
}

void InstructionDecoder::OPCodeCB0x4B() {
    // BIT 1, E
    testBit(1, E);
}

void InstructionDecoder::OPCodeCB0x4C() {
    // BIT 1, H
    testBit(1, H);
}

void InstructionDecoder::OPCodeCB0x4D() {
    // BIT 1, L
    testBit(1, L);
}

void InstructionDecoder::OPCodeCB0x4E() {
    // BIT 1, (HL)
    testBit(1, HL);
}

void InstructionDecoder::OPCodeCB0x4F() {
    // BIT 1, A
    testBit(1, A);
}

void InstructionDecoder::OPCodeCB0x50() {
    // BIT 2, B
    testBit(2, B);
}

void InstructionDecoder::OPCodeCB0x51() {
    // BIT 2, C
    testBit(2, C);
}

void InstructionDecoder::OPCodeCB0x52() {
    // BIT 2, D
    testBit(2, D);
}

void InstructionDecoder::OPCodeCB0x53() {
    // BIT 2, E
    testBit(2, E);
}

void InstructionDecoder::OPCodeCB0x54() {
    // BIT 2, H
    testBit(2, H);
}

void InstructionDecoder::OPCodeCB0x55() {
    // BIT 2, L
    testBit(2, L);
}

void InstructionDecoder::OPCodeCB0x56() {
    // BIT 2, (HL)
    testBit(2, HL);
}

void InstructionDecoder::OPCodeCB0x57() {
    // BIT 2, A
    testBit(2, A);
}

void InstructionDecoder::OPCodeCB0x58() {
    // BIT 3, B
    testBit(3, B);
}

void InstructionDecoder::OPCodeCB0x59() {
    // BIT 3, C
    testBit(3, C);
}

void InstructionDecoder::OPCodeCB0x5A() {
    // BIT 3, D
    testBit(3, D);
}

void InstructionDecoder::OPCodeCB0x5B() {
    // BIT 3, E
    testBit(3, E);
}

void InstructionDecoder::OPCodeCB0x5C() {
    // BIT 3, H
    testBit(3, H);
}

void InstructionDecoder::OPCodeCB0x5D() {
    // BIT 3, L
    testBit(3, L);
}

void InstructionDecoder::OPCodeCB0x5E() {
    // BIT 3, (HL)
    testBit(3, HL);
}

void InstructionDecoder::OPCodeCB0x5F() {
    // BIT 3, A
    testBit(3, A);
}

void InstructionDecoder::OPCodeCB0x60() {
    // BIT 4, B
    testBit(4, B);
}

void InstructionDecoder::OPCodeCB0x61() {
    // BIT 4, C
    testBit(4, C);
}

void InstructionDecoder::OPCodeCB0x62() {
    // BIT 4, D
    testBit(4, D);
}

void InstructionDecoder::OPCodeCB0x63() {
    // BIT 4, E
    testBit(4, E);
}

void InstructionDecoder::OPCodeCB0x64() {
    // BIT 4, H
    testBit(4, H);
}

void InstructionDecoder::OPCodeCB0x65() {
    // BIT 4, L
    testBit(4, L);
}

void InstructionDecoder::OPCodeCB0x66() {
    // BIT 4, (HL)
    testBit(4, HL);
}

void InstructionDecoder::OPCodeCB0x67() {
    // BIT 4, A
    testBit(4, A);
}

void InstructionDecoder::OPCodeCB0x68() {
    // BIT 5, B
    testBit(5, B);
}

void InstructionDecoder::OPCodeCB0x69() {
    // BIT 5, C
    testBit(5, C);
}

void InstructionDecoder::OPCodeCB0x6A() {
    // BIT 5, D
    testBit(5, D);
}

void InstructionDecoder::OPCodeCB0x6B() {
    // BIT 5, E
    testBit(5, E);
}

void InstructionDecoder::OPCodeCB0x6C() {
    // BIT 5, H
    testBit(5, H);
}

void InstructionDecoder::OPCodeCB0x6D() {
    // BIT 5, L
    testBit(5, L);
}

void InstructionDecoder::OPCodeCB0x6E() {
    // BIT 5, (HL)
    testBit(5, HL);
}

void InstructionDecoder::OPCodeCB0x6F() {
    // BIT 5, A
    testBit(5, A);
}

void InstructionDecoder::OPCodeCB0x70() {
    // BIT 6, B
    testBit(6, B);
}

void InstructionDecoder::OPCodeCB0x71() {
    // BIT 6, C
    testBit(6, C);
}

void InstructionDecoder::OPCodeCB0x72() {
    // BIT 6, D
    testBit(6, D);
}

void InstructionDecoder::OPCodeCB0x73() {
    // BIT 6, E
    testBit(6, E);
}

void InstructionDecoder::OPCodeCB0x74() {
    // BIT 6, H
    testBit(6, H);
}

void InstructionDecoder::OPCodeCB0x75() {
    // BIT 6, L
    testBit(6, L);
}

void InstructionDecoder::OPCodeCB0x76() {
    // BIT 6, (HL)
    testBit(6, HL);
}

void InstructionDecoder::OPCodeCB0x77() {
    // BIT 6, A
    testBit(6, A);
}

void InstructionDecoder::OPCodeCB0x78() {
    // BIT 7, B
    testBit(7, B);
}

void InstructionDecoder::OPCodeCB0x79() {
    // BIT 7, C
    testBit(7, C);
}

void InstructionDecoder::OPCodeCB0x7A() {
    // BIT 7, D
    testBit(7, D);
}

void InstructionDecoder::OPCodeCB0x7B() {
    // BIT 7, E
    testBit(7, E);
}

void InstructionDecoder::OPCodeCB0x7C() {
    // BIT 7, H
    testBit(7, H);
}

void InstructionDecoder::OPCodeCB0x7D() {
    // BIT 7, L
    testBit(7, L);
}

void InstructionDecoder::OPCodeCB0x7E() {
    // BIT 7, (HL)
    testBit(7, HL);
}

void InstructionDecoder::OPCodeCB0x7F() {
    // BIT 7, A
    testBit(7, A);
}

void InstructionDecoder::OPCodeCB0x80() {
    // RES 0, B
    resetBit(0, B);
}

void InstructionDecoder::OPCodeCB0x81() {
    // RES 0, C
    resetBit(0, C);
}

void InstructionDecoder::OPCodeCB0x82() {
    // RES 0, D
    resetBit(0, D);
}

void InstructionDecoder::OPCodeCB0x83() {
    // RES 0, E
    resetBit(0, E);
}

void InstructionDecoder::OPCodeCB0x84() {
    // RES 0, H
    resetBit(0, H);
}

void InstructionDecoder::OPCodeCB0x85() {
    // RES 0, L
    resetBit(0, L);
}

void InstructionDecoder::OPCodeCB0x86() {
    // RES 0, (HL)
    resetBit(0, HL);
}

void InstructionDecoder::OPCodeCB0x87() {
    // RES 0, A
    resetBit(0, A);
}

void InstructionDecoder::OPCodeCB0x88() {
    // RES 1, B
    resetBit(1, B);
}

void InstructionDecoder::OPCodeCB0x89() {
    // RES 1, C
    resetBit(1, C);
}

void InstructionDecoder::OPCodeCB0x8A() {
    // RES 1, D
    resetBit(1, D);
}

void InstructionDecoder::OPCodeCB0x8B() {
    // RES 1, E
    resetBit(1, E);
}

void InstructionDecoder::OPCodeCB0x8C() {
    // RES 1, H
    resetBit(1, H);
}

void InstructionDecoder::OPCodeCB0x8D() {
    // RES 1, L
    resetBit(1, L);
}

void InstructionDecoder::OPCodeCB0x8E() {
    // RES 1, (HL)
    resetBit(1, HL);
}

void InstructionDecoder::OPCodeCB0x8F() {
    // RES 1, A
    resetBit(1, A);
}

void InstructionDecoder::OPCodeCB0x90() {
    // RES 2, B
    resetBit(2, B);
}

void InstructionDecoder::OPCodeCB0x91() {
    // RES 2, C
    resetBit(2, C);
}

void InstructionDecoder::OPCodeCB0x92() {
    // RES 2, D
    resetBit(2, D);
}

void InstructionDecoder::OPCodeCB0x93() {
    // RES 2, E
    resetBit(2, E);
}

void InstructionDecoder::OPCodeCB0x94() {
    // RES 2, H
    resetBit(2, H);
}

void InstructionDecoder::OPCodeCB0x95() {
    // RES 2, L
    resetBit(2, L);
}

void InstructionDecoder::OPCodeCB0x96() {
    // RES 2, (HL)
    resetBit(2, HL);
}

void InstructionDecoder::OPCodeCB0x97() {
    // RES 2, A
    resetBit(2, A);
}

void InstructionDecoder::OPCodeCB0x98() {
    // RES 3, B
    resetBit(3, B);
}

void InstructionDecoder::OPCodeCB0x99() {
    // RES 3, C
    resetBit(3, C);
}

void InstructionDecoder::OPCodeCB0x9A() {
    // RES 3, D
    resetBit(3, D);
}

void InstructionDecoder::OPCodeCB0x9B() {
    // RES 3, E
    resetBit(3, E);
}

void InstructionDecoder::OPCodeCB0x9C() {
    // RES 3, H
    resetBit(3, H);
}

void InstructionDecoder::OPCodeCB0x9D() {
    // RES 3, L
    resetBit(3, L);
}

void InstructionDecoder::OPCodeCB0x9E() {
    // RES 3, (HL)
    resetBit(3, HL);
}

void InstructionDecoder::OPCodeCB0x9F() {
    // RES 3, A
    resetBit(3, A);
}

void InstructionDecoder::OPCodeCB0xA0() {
    // RES 4, B
    resetBit(4, B);
}

void InstructionDecoder::OPCodeCB0xA1() {
    // RES 4, C
    resetBit(4, C);
}

void InstructionDecoder::OPCodeCB0xA2() {
    // RES 4, D
    resetBit(4, D);
}

void InstructionDecoder::OPCodeCB0xA3() {
    // RES 4, E
    resetBit(4, E);
}

void InstructionDecoder::OPCodeCB0xA4() {
    // RES 4, H
    resetBit(4, H);
}

void InstructionDecoder::OPCodeCB0xA5() {
    // RES 4, L
    resetBit(4, L);
}

void InstructionDecoder::OPCodeCB0xA6() {
    // RES 4, (HL)
    resetBit(4, HL);
}

void InstructionDecoder::OPCodeCB0xA7() {
    // RES 4, A
    resetBit(4, A);
}

void InstructionDecoder::OPCodeCB0xA8() {
    // RES 5, B
    resetBit(5, B);
}

void InstructionDecoder::OPCodeCB0xA9() {
    // RES 5, C
    resetBit(5, C);
}

void InstructionDecoder::OPCodeCB0xAA() {
    // RES 5, D
    resetBit(5, D);
}

void InstructionDecoder::OPCodeCB0xAB() {
    // RES 5, E
    resetBit(5, E);
}

void InstructionDecoder::OPCodeCB0xAC() {
    // RES 5, H
    resetBit(5, H);
}

void InstructionDecoder::OPCodeCB0xAD() {
    // RES 5, L
    resetBit(5, L);
}

void InstructionDecoder::OPCodeCB0xAE() {
    // RES 5, (HL)
    resetBit(5, HL);
}

void InstructionDecoder::OPCodeCB0xAF() {
    // RES 5, A
    resetBit(5, A);
}

void InstructionDecoder::OPCodeCB0xB0() {
    // RES 6, B
    resetBit(6, B);
}

void InstructionDecoder::OPCodeCB0xB1() {
    // RES 6, C
    resetBit(6, C);
}

void InstructionDecoder::OPCodeCB0xB2() {
    // RES 6, D
    resetBit(6, D);
}

void InstructionDecoder::OPCodeCB0xB3() {
    // RES 6, E
    resetBit(6, E);
}

void InstructionDecoder::OPCodeCB0xB4() {
    // RES 6, H
    resetBit(6, H);
}

void InstructionDecoder::OPCodeCB0xB5() {
    // RES 6, L
    resetBit(6, L);
}

void InstructionDecoder::OPCodeCB0xB6() {
    // RES 6, (HL)
    resetBit(6, HL);
}

void InstructionDecoder::OPCodeCB0xB7() {
    // RES 6, A
    resetBit(6, A);
}

void InstructionDecoder::OPCodeCB0xB8() {
    // RES 7, B
    resetBit(7, B);
}

void InstructionDecoder::OPCodeCB0xB9() {
    // RES 7, C
    resetBit(7, C);
}

void InstructionDecoder::OPCodeCB0xBA() {
    // RES 7, D
    resetBit(7, D);
}

void InstructionDecoder::OPCodeCB0xBB() {
    // RES 7, E
    resetBit(7, E);
}

void InstructionDecoder::OPCodeCB0xBC() {
    // RES 7, H
    resetBit(7, H);
}

void InstructionDecoder::OPCodeCB0xBD() {
    // RES 7, L
    resetBit(7, L);
}

void InstructionDecoder::OPCodeCB0xBE() {
    // RES 7, (HL)
    resetBit(7, HL);
}

void InstructionDecoder::OPCodeCB0xBF() {
    // RES 7, A
    resetBit(7, A);
}

void InstructionDecoder::OPCodeCB0xC0() {
    // SET 0, B
    setBit(0, B);
}

void InstructionDecoder::OPCodeCB0xC1() {
    // SET 0, C
    setBit(0, C);
}

void InstructionDecoder::OPCodeCB0xC2() {
    // SET 0, D
    setBit(0, D);
}

void InstructionDecoder::OPCodeCB0xC3() {
    // SET 0, E
    setBit(0, E);
}

void InstructionDecoder::OPCodeCB0xC4() {
    // SET 0, H
    setBit(0, H);
}

void InstructionDecoder::OPCodeCB0xC5() {
    // SET 0, L
    setBit(0, L);
}

void InstructionDecoder::OPCodeCB0xC6() {
    // SET 0, (HL)
    setBit(0, HL);
}

void InstructionDecoder::OPCodeCB0xC7() {
    // SET 0, A
    setBit(0, A);
}

void InstructionDecoder::OPCodeCB0xC8() {
    // SET 1, B
    setBit(1, B);
}

void InstructionDecoder::OPCodeCB0xC9() {
    // SET 1, C
    setBit(1, C);
}

void InstructionDecoder::OPCodeCB0xCA() {
    // SET 1, D
    setBit(1, D);
}

void InstructionDecoder::OPCodeCB0xCB() {
    // SET 1, E
    setBit(1, E);
}

void InstructionDecoder::OPCodeCB0xCC() {
    // SET 1, H
    setBit(1, H);
}

void InstructionDecoder::OPCodeCB0xCD() {
    // SET 1, L
    setBit(1, L);
}

void InstructionDecoder::OPCodeCB0xCE() {
    // SET 1, (HL)
    setBit(1, HL);
}

void InstructionDecoder::OPCodeCB0xCF() {
    // SET 1, A
    setBit(1, A);
}

void InstructionDecoder::OPCodeCB0xD0() {
    // SET 2, B
    setBit(2, B);
}

void InstructionDecoder::OPCodeCB0xD1() {
    // SET 2, C
    setBit(2, C);
}

void InstructionDecoder::OPCodeCB0xD2() {
    // SET 2, D
    setBit(2, D);
}

void InstructionDecoder::OPCodeCB0xD3() {
    // SET 2, E
    setBit(2, E);
}

void InstructionDecoder::OPCodeCB0xD4() {
    // SET 2, H
    setBit(2, H);
}

void InstructionDecoder::OPCodeCB0xD5() {
    // SET 2, L
    setBit(2, L);
}

void InstructionDecoder::OPCodeCB0xD6() {
    // SET 2, (HL)
    setBit(2, HL);
}

void InstructionDecoder::OPCodeCB0xD7() {
    // SET 2, A
    setBit(2, A);
}

void InstructionDecoder::OPCodeCB0xD8() {
    // SET 3, B
    setBit(3, B);
}

void InstructionDecoder::OPCodeCB0xD9() {
    // SET 3, C
    setBit(3, C);
}

void InstructionDecoder::OPCodeCB0xDA() {
    // SET 3, D
    setBit(3, D);
}

void InstructionDecoder::OPCodeCB0xDB() {
    // SET 3, E
    setBit(3, E);
}

void InstructionDecoder::OPCodeCB0xDC() {
    // SET 3, H
    setBit(3, H);
}

void InstructionDecoder::OPCodeCB0xDD() {
    // SET 3, L
    setBit(3, L);
}

void InstructionDecoder::OPCodeCB0xDE() {
    // SET 3, (HL)
    setBit(3, HL);
}

void InstructionDecoder::OPCodeCB0xDF() {
    // SET 3, A
    setBit(3, A);
}

void InstructionDecoder::OPCodeCB0xE0() {
    // SET 4, B
    setBit(4, B);
}

void InstructionDecoder::OPCodeCB0xE1() {
    // SET 4, C
    setBit(4, C);
}

void InstructionDecoder::OPCodeCB0xE2() {
    // SET 4, D
    setBit(4, D);
}

void InstructionDecoder::OPCodeCB0xE3() {
    // SET 4, E
    setBit(4, E);
}

void InstructionDecoder::OPCodeCB0xE4() {
    // SET 4, H
    setBit(4, H);
}

void InstructionDecoder::OPCodeCB0xE5() {
    // SET 4, L
    setBit(4, L);
}

void InstructionDecoder::OPCodeCB0xE6() {
    // SET 4, (HL)
    setBit(4, HL);
}

void InstructionDecoder::OPCodeCB0xE7() {
    // SET 4, A
    setBit(4, A);
}

void InstructionDecoder::OPCodeCB0xE8() {
    // SET 5, B
    setBit(5, B);
}

void InstructionDecoder::OPCodeCB0xE9() {
    // SET 5, C
    setBit(5, C);
}

void InstructionDecoder::OPCodeCB0xEA() {
    // SET 5, D
    setBit(5, D);
}

void InstructionDecoder::OPCodeCB0xEB() {
    // SET 5, E
    setBit(5, E);
}

void InstructionDecoder::OPCodeCB0xEC() {
    // SET 5, H
    setBit(5, H);
}

void InstructionDecoder::OPCodeCB0xED() {
    // SET 5, L
    setBit(5, L);
}

void InstructionDecoder::OPCodeCB0xEE() {
    // SET 5, (HL)
    setBit(5, HL);
}

void InstructionDecoder::OPCodeCB0xEF() {
    // SET 5, A
    setBit(5, A);
}

void InstructionDecoder::OPCodeCB0xF0() {
    // SET 6, B
    setBit(6, B);
}

void InstructionDecoder::OPCodeCB0xF1() {
    // SET 6, C
    setBit(6, C);
}

void InstructionDecoder::OPCodeCB0xF2() {
    // SET 6, D
    setBit(6, D);
}

void InstructionDecoder::OPCodeCB0xF3() {
    // SET 6, E
    setBit(6, E);
}

void InstructionDecoder::OPCodeCB0xF4() {
    // SET 6, H
    setBit(6, H);
}

void InstructionDecoder::OPCodeCB0xF5() {
    // SET 6, L
    setBit(6, L);
}

void InstructionDecoder::OPCodeCB0xF6() {
    // SET 6, (HL)
    setBit(6, HL);
}

void InstructionDecoder::OPCodeCB0xF7() {
    // SET 6, A
    setBit(6, A);
}

void InstructionDecoder::OPCodeCB0xF8() {
    // SET 7, B
    setBit(7, B);
}

void InstructionDecoder::OPCodeCB0xF9() {
    // SET 7, C
    setBit(7, C);
}

void InstructionDecoder::OPCodeCB0xFA() {
    // SET 7, D
    setBit(7, D);
}

void InstructionDecoder::OPCodeCB0xFB() {
    // SET 7, E
    setBit(7, E);
}

void InstructionDecoder::OPCodeCB0xFC() {
    // SET 7, H
    setBit(7, H);
}

void InstructionDecoder::OPCodeCB0xFD() {
    // SET 7, L
    setBit(7, L);
}

void InstructionDecoder::OPCodeCB0xFE() {
    // SET 7, (HL)
    setBit(7, HL);
}

void InstructionDecoder::OPCodeCB0xFF() {
    // SET 7, A
    setBit(7, A);
}
