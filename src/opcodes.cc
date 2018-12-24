#include "Processor.hh"

void Processor::OPCode0x00()
{
    // NOP
}

void Processor::OPCode0x01()
{
    // LD BC, d16

    // TODO check stack data order

    loadRegister(B);
    loadRegister(C);
}

void Processor::OPCode0x02()
{
    // LD (BC), A
    // TODO handle memory
}

void Processor::OPCode0x03()
{
    // INC BC
    BC->increment();
}

void Processor::OPCode0x04()
{
    // INC B
    B->increment();

    // TODO double check flag logic
    register8_t value_b = B->getValue();

    if (value_b == 0x00)
        setFlagZ(true);

    setFlagN(false);

    if ((value_b & 0x0F) == 0x00)
        setFlagH(true);
}

void Processor::OPCode0x05()
{
    // DEC B
    B->decrement();

    register8_t value_b = B->getValue();

    if (value_b == 0x00)
        setFlagZ(true);

    setFlagN(true);

    if ((value_b & 0x0F) == 0x00)
        setFlagH(true);
}

void Processor::OPCode0x06()
{
    // LD B, d8
    loadRegister(B);
}

void Processor::OPCode0x07()
{
    // RLCA
    // TODO bitwise rotation
}

void Processor::OPCode0x08()
{
    // LD (a16), SP
    // TODO memory management
}

void Processor::OPCode0x09()
{
    // ADD HL, BC

    register16_t value_hl = HL->getValue();

    register16_t value_bc = BC->getValue();

    value_hl += value_bc;

    HL->setValue(value_hl);
}

void Processor::OPCode0x0A()
{
    // LD A, (BC)
    // TODO memory management
}

void Processor::OPCode0x0B()
{
    // DEC BC
    BC->decrement();
}

void Processor::OPCode0x0C()
{
    // INC C
    C->increment();
}

void Processor::OPCode0x0D()
{
    // DEC C
    C->decrement();
}

void Processor::OPCode0x0E()
{
    // LD C, d8
    loadRegister(C);
}

void Processor::OPCode0x0F()
{
    // RRCA
    // TODO fix
}

void Processor::OPCode0x10()
{
    // STOP 0
    // TODO fix
}

void Processor::OPCode0x11()
{
    // LD DE, d16
    // TODO check stack data order
    loadRegister(E);
    loadRegister(D);
}

void Processor::OPCode0x12()
{
    // LD (DE), A
    // TODO memory management
}

void Processor::OPCode0x13()
{
    // INC DE
    DE->increment();
}

void Processor::OPCode0x14()
{
    // INC D
    D->increment();
}

void Processor::OPCode0x15()
{
    // DEC D
    D->decrement();
}

void Processor::OPCode0x16()
{
    // LD D, d8
    loadRegister(D);
}

void Processor::OPCode0x17()
{
    // RLA
    // TODO fix
}

void Processor::OPCode0x18()
{
    // JR d8
    // TODO double check logic
    program_counter += (int8_t)program_memory[program_counter];
}

void Processor::OPCode0x19()
{
    // ADD HL, DE
    register16_t value_hl = HL->getValue();
    register16_t value_de = DE->getValue();

    value_hl += value_de;

    HL->setValue(value_hl);
}

void Processor::OPCode0x1A()
{
    // LD A, (DE)
    // TODO memory management
}

void Processor::OPCode0x1B()
{
    // DEC DE
    DE->decrement();
}

void Processor::OPCode0x1C()
{
    // INC E
    E->increment();
}

void Processor::OPCode0x1D()
{
    // DEC E
    E->decrement();
}

void Processor::OPCode0x1E()
{
    // LD E, d8
    loadRegister(E);
}

void Processor::OPCode0x1F()
{
    // RRA
    // TODO fix
}

void Processor::OPCode0x20()
{
    // JR NZ, r8
    // TODO double check
    if (getFlagZ() == false)
    {
        program_counter += (int8_t)program_memory[program_counter];
    }
}

void Processor::OPCode0x21()
{
    // LD HL, d16
    loadRegister(H);
    loadRegister(L);
}

void Processor::OPCode0x22()
{
    // LD (HL+), A
    // TODO memory management
}

void Processor::OPCode0x23()
{
    // INC HL
    HL->increment();
}

void Processor::OPCode0x24()
{
    // INC H
    H->increment();
}

void Processor::OPCode0x25()
{
    // DEC H
    H->decrement();
}

void Processor::OPCode0x26()
{
    // LD H, d8
    loadRegister(H);
}

void Processor::OPCode0x27()
{
    // DAA
    // TODO fix
}

void Processor::OPCode0x28()
{
    // JR Z, R8
    // TODO double check

    if (getFlagZ())
    {
        program_counter += (int8_t)program_memory[program_counter];
    }
}

void Processor::OPCode0x29()
{
    // ADD HL, HL
    register16_t data_hl = HL->getValue();

    data_hl *= 2;

    HL->setValue(data_hl);
}

void Processor::OPCode0x2A()
{
    // LD A, (HL+)
    // TODO memory management
}

void Processor::OPCode0x2B()
{
    // DEC HL
    HL->decrement();
}

void Processor::OPCode0x2C()
{
    // INC L
    L->increment();
}

void Processor::OPCode0x2D()
{
    // DEC L
    L->decrement();
}

void Processor::OPCode0x2E()
{
    // LD L, d8
    loadRegister(L);
}

void Processor::OPCode0x2F()
{
    // CPL
    // TODO fix
}

void Processor::OPCode0x30()
{
    // JR NC, r8
    if (!getFlagC())
    {
        program_counter += (int8_t)program_memory[program_counter];
    }
}

void Processor::OPCode0x31()
{
    // LD SP, d16
    loadRegister(stack_pointer->getLowRegister());
    loadRegister(stack_pointer->getHighRegister());
}

void Processor::OPCode0x32()
{
    // LD (HL-), A
    // TODO memory management
}

void Processor::OPCode0x33()
{
    // INC SP
    stack_pointer->increment();
}

void Processor::OPCode0x34()
{
    // INC (HL)
    // TODO memory management
}

void Processor::OPCode0x35()
{
    // DEC (HL)
    // TODO memory management
}

void Processor::OPCode0x36()
{
    // LD (HL), d8
    // TODO memory management
}

void Processor::OPCode0x37()
{
    // DAA
    // TODO fix
}

void Processor::OPCode0x38()
{
    // JR C, r8
    if (getFlagC())
    {
        program_counter += (int8_t)program_memory[program_counter];
    }
}

void Processor::OPCode0x39()
{
    // ADD HL, SP
    register16_t data_hl = HL->getValue();
    register16_t data_sp = stack_pointer->getValue();

    data_hl += data_sp;

    HL->setValue(data_hl);
}

void Processor::OPCode0x3A()
{
    // LD A, (HL-)
    // TODO fix memory management
}

void Processor::OPCode0x3B()
{
    // DEC SP
    stack_pointer->decrement();
}

void Processor::OPCode0x3C()
{
    // INC A
    A->increment();
}

void Processor::OPCode0x3D()
{
    // DEC A
    A->decrement();
}

void Processor::OPCode0x3E()
{
    // LD A, d8
    loadRegister(A);
}

void Processor::OPCode0x3F()
{
    // CCF
    // TODO fix
}

void Processor::OPCode0x40()
{
    // LD B, B
    // Do nothing...
}

void Processor::OPCode0x41()
{
    // LD B, C
    copyRegister(B, C);
}

void Processor::OPCode0x42()
{
    // LD B, D
    copyRegister(B, D);
}

void Processor::OPCode0x43()
{
    // LD B, E
    copyRegister(B, E);
}

void Processor::OPCode0x44()
{
    // LD B, H
    copyRegister(B, H);
}

void Processor::OPCode0x45()
{
    // LD B, L
    copyRegister(B, L);
}

void Processor::OPCode0x46()
{
    // LD B, (HL)
    // TODO memory management
}

void Processor::OPCode0x47()
{
    // LD B, A
    copyRegister(B, A);
}

void Processor::OPCode0x48()
{
    // LD C, B
    copyRegister(C, B);
}

void Processor::OPCode0x49()
{
    // LD C, C
    // Do nothing...
}

void Processor::OPCode0x4A()
{
    // LD C, D
    copyRegister(C, D);
}

void Processor::OPCode0x4B()
{
    // LD C, E
    copyRegister(C, E);
}

void Processor::OPCode0x4C()
{
    // LD C, H
    copyRegister(C, H);
}

void Processor::OPCode0x4D()
{
    // LD C, L
    copyRegister(C, L);
}

void Processor::OPCode0x4E()
{
    // LD C, (HL)
    // TODO memory management
}

void Processor::OPCode0x4F()
{
    // LD C, A
    copyRegister(C, A);
}

void Processor::OPCode0x50()
{
    // LD D, B
    copyRegister(D, B);
}

void Processor::OPCode0x51()
{
    // LD D, C
    copyRegister(D, C);
}

void Processor::OPCode0x52()
{
    // LD D, D
    // Do nothing...
}

void Processor::OPCode0x53()
{
    // LD D, E
    copyRegister(D, E);
}

void Processor::OPCode0x54()
{
    // LD D, H
    copyRegister(D, H);
}

void Processor::OPCode0x55()
{
    // LD D, L
    copyRegister(D, L);
}

void Processor::OPCode0x56()
{
    // LD D, (HL)
    // TODO memory management
}

void Processor::OPCode0x57()
{
    // LD D, A
    copyRegister(D, A);
}

void Processor::OPCode0x58()
{
    // LD E, B
    copyRegister(E, B);
}

void Processor::OPCode0x59()
{
    // LD E, C
    copyRegister(E, C);
}

void Processor::OPCode0x5A()
{
    // LD E, D
    copyRegister(E, D);
}

void Processor::OPCode0x5B()
{
    // LD E, E
    // Do nothing...
}

void Processor::OPCode0x5C()
{
    // LD E, H
    copyRegister(E, H);
}

void Processor::OPCode0x5D()
{
    // LD E, L
    copyRegister(E, L);
}

void Processor::OPCode0x5E()
{
    // LD E, (HL)
    // TODO memory management
}

void Processor::OPCode0x5F()
{
    // LD E, A
    copyRegister(E, A);
}

void Processor::OPCode0x60()
{
    // LD H, B
    copyRegister(H, B);
}

void Processor::OPCode0x61()
{
    // LD H, C
    copyRegister(H, C);
}

void Processor::OPCode0x62()
{
    // LD H, D
    copyRegister(H, D);
}

void Processor::OPCode0x63()
{
    // LD H, E
    copyRegister(H, E);
}

void Processor::OPCode0x64()
{
    // LD H, H
    // Do nothing...
}

void Processor::OPCode0x65()
{
    // LD H, L
    copyRegister(H, L);
}

void Processor::OPCode0x66()
{
    // LD H, (HL)
    // TODO memory management
}

void Processor::OPCode0x67()
{
    // LD H, A
    copyRegister(H, A);
}

void Processor::OPCode0x68()
{
    // LD L, B
    copyRegister(L, B);
}

void Processor::OPCode0x69()
{
    // LD L, C
    copyRegister(L, C);
}

void Processor::OPCode0x6A()
{
    // LD L, D
    copyRegister(L, D);
}

void Processor::OPCode0x6B()
{
    // LD L, E
    copyRegister(L, E);
}

void Processor::OPCode0x6C()
{
    // LD L, H
    copyRegister(L, H);
}

void Processor::OPCode0x6D()
{
    // LD L, L
    // Do nothing...
}

void Processor::OPCode0x6E()
{
    // LD L, (HL)
    // TODO memory management
}

void Processor::OPCode0x6F()
{
    // LD L, A
    copyRegister(L, A);
}

void Processor::OPCode0x70()
{
    // LD (HL), B
    // TODO memory management
}

void Processor::OPCode0x71()
{
    // LD (HL), C
    // TODO memory management
}

void Processor::OPCode0x72()
{
    // LD (HL), D
    // TODO memory management
}

void Processor::OPCode0x73()
{
    // LD (HL), E
    // TODO memory management
}

void Processor::OPCode0x74()
{
    // LD (HL), H
    // TODO memory management
}

void Processor::OPCode0x75()
{
    // LD (HL), L
    // TODO memory management
}

void Processor::OPCode0x76()
{
    // HALT
    // TODO stop??
}

void Processor::OPCode0x77()
{
    // LD (HL), A
    // TODO memory management
}

void Processor::OPCode0x78()
{
    // LD A, B
    copyRegister(A, B);
}

void Processor::OPCode0x79()
{
    // LD A, C
    copyRegister(A, C);
}

void Processor::OPCode0x7A()
{
    // LD A, D
    copyRegister(A, D);
}

void Processor::OPCode0x7B()
{
    // LD A, E
    copyRegister(A, E);
}

void Processor::OPCode0x7C()
{
    // LD A, H
    copyRegister(A, H);
}

void Processor::OPCode0x7D()
{
    // LD A, L
    copyRegister(A, L);
}

void Processor::OPCode0x7E()
{
    // LD A, (HL)
    // TODO memory management
}

void Processor::OPCode0x7F()
{
    // LD A, A
    // Do nothing...
}

void Processor::OPCode0x80()
{
}

void Processor::OPCode0x81()
{
}

void Processor::OPCode0x82()
{
}

void Processor::OPCode0x83()
{
}

void Processor::OPCode0x84()
{
}

void Processor::OPCode0x85()
{
}

void Processor::OPCode0x86()
{
}

void Processor::OPCode0x87()
{
}

void Processor::OPCode0x88()
{
}

void Processor::OPCode0x89()
{
}

void Processor::OPCode0x8A()
{
}

void Processor::OPCode0x8B()
{
}

void Processor::OPCode0x8C()
{
}

void Processor::OPCode0x8D()
{
}

void Processor::OPCode0x8E()
{
}

void Processor::OPCode0x8F()
{
}

void Processor::OPCode0x90()
{
}

void Processor::OPCode0x91()
{
}

void Processor::OPCode0x92()
{
}

void Processor::OPCode0x93()
{
}

void Processor::OPCode0x94()
{
}

void Processor::OPCode0x95()
{
}

void Processor::OPCode0x96()
{
}

void Processor::OPCode0x97()
{
}

void Processor::OPCode0x98()
{
}

void Processor::OPCode0x99()
{
}

void Processor::OPCode0x9A()
{
}

void Processor::OPCode0x9B()
{
}

void Processor::OPCode0x9C()
{
}

void Processor::OPCode0x9D()
{
}

void Processor::OPCode0x9E()
{
}

void Processor::OPCode0x9F()
{
}

void Processor::OPCode0xA0()
{
}

void Processor::OPCode0xA1()
{
}

void Processor::OPCode0xA2()
{
}

void Processor::OPCode0xA3()
{
}

void Processor::OPCode0xA4()
{
}

void Processor::OPCode0xA5()
{
}

void Processor::OPCode0xA6()
{
}

void Processor::OPCode0xA7()
{
}

void Processor::OPCode0xA8()
{
}

void Processor::OPCode0xA9()
{
}

void Processor::OPCode0xAA()
{
}

void Processor::OPCode0xAB()
{
}

void Processor::OPCode0xAC()
{
}

void Processor::OPCode0xAD()
{
}

void Processor::OPCode0xAE()
{
}

void Processor::OPCode0xAF()
{
}

void Processor::OPCode0xB0()
{
}

void Processor::OPCode0xB1()
{
}

void Processor::OPCode0xB2()
{
}

void Processor::OPCode0xB3()
{
}

void Processor::OPCode0xB4()
{
}

void Processor::OPCode0xB5()
{
}

void Processor::OPCode0xB6()
{
}

void Processor::OPCode0xB7()
{
}

void Processor::OPCode0xB8()
{
}

void Processor::OPCode0xB9()
{
}

void Processor::OPCode0xBA()
{
}

void Processor::OPCode0xBB()
{
}

void Processor::OPCode0xBC()
{
}

void Processor::OPCode0xBD()
{
}

void Processor::OPCode0xBE()
{
}

void Processor::OPCode0xBF()
{
}

void Processor::OPCode0xC0()
{
}

void Processor::OPCode0xC1()
{
}

void Processor::OPCode0xC2()
{
}

void Processor::OPCode0xC3()
{
}

void Processor::OPCode0xC4()
{
}

void Processor::OPCode0xC5()
{
}

void Processor::OPCode0xC6()
{
}

void Processor::OPCode0xC7()
{
}

void Processor::OPCode0xC8()
{
}

void Processor::OPCode0xC9()
{
}

void Processor::OPCode0xCA()
{
}

void Processor::OPCode0xCB()
{
}

void Processor::OPCode0xCC()
{
}

void Processor::OPCode0xCD()
{
}

void Processor::OPCode0xCE()
{
}

void Processor::OPCode0xCF()
{
}

void Processor::OPCode0xD0()
{
}

void Processor::OPCode0xD1()
{
}

void Processor::OPCode0xD2()
{
}

void Processor::OPCode0xD3()
{
}

void Processor::OPCode0xD4()
{
}

void Processor::OPCode0xD5()
{
}

void Processor::OPCode0xD6()
{
}

void Processor::OPCode0xD7()
{
}

void Processor::OPCode0xD8()
{
}

void Processor::OPCode0xD9()
{
}

void Processor::OPCode0xDA()
{
}

void Processor::OPCode0xDB()
{
}

void Processor::OPCode0xDC()
{
}

void Processor::OPCode0xDD()
{
}

void Processor::OPCode0xDE()
{
}

void Processor::OPCode0xDF()
{
}

void Processor::OPCode0xE0()
{
}

void Processor::OPCode0xE1()
{
}

void Processor::OPCode0xE2()
{
}

void Processor::OPCode0xE3()
{
}

void Processor::OPCode0xE4()
{
}

void Processor::OPCode0xE5()
{
}

void Processor::OPCode0xE6()
{
}

void Processor::OPCode0xE7()
{
}

void Processor::OPCode0xE8()
{
}

void Processor::OPCode0xE9()
{
}

void Processor::OPCode0xEA()
{
}

void Processor::OPCode0xEB()
{
}

void Processor::OPCode0xEC()
{
}

void Processor::OPCode0xED()
{
}

void Processor::OPCode0xEE()
{
}

void Processor::OPCode0xEF()
{
}

void Processor::OPCode0xF0()
{
}

void Processor::OPCode0xF1()
{
}

void Processor::OPCode0xF2()
{
}

void Processor::OPCode0xF3()
{
}

void Processor::OPCode0xF4()
{
}

void Processor::OPCode0xF5()
{
}

void Processor::OPCode0xF6()
{
}

void Processor::OPCode0xF7()
{
}

void Processor::OPCode0xF8()
{
}

void Processor::OPCode0xF9()
{
}

void Processor::OPCode0xFA()
{
}

void Processor::OPCode0xFB()
{
}

void Processor::OPCode0xFC()
{
}

void Processor::OPCode0xFD()
{
}

void Processor::OPCode0xFE()
{
}

void Processor::OPCode0xFF()
{
}
