// System headers
#include <iomanip>

// User headers
#include "Processor.hh"
#include "Utility.hh"

void Processor::readInstructions(const std::string &filename, bool verbose) {
    // open the file as binary
    std::ifstream file(filename, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error reading file " << filename << std::endl;
        return;
    }

    // Stop eating new lines in binary mode
    file.unsetf(std::ios::skipws);

    std::streampos fileSize;

    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    if (verbose)
        std::cout << "Reading instructions from binary file..." << std::endl;

    // read the data:
    rom_data.insert(rom_data.begin(), std::istream_iterator<opcode_t>(file),
                    std::istream_iterator<opcode_t>());

    if (verbose)
        std::cout << "Loaded " << rom_data.size() << " bytes from ROM file"
                  << std::endl;

    PC->setValue(0x0000);
    for (opcode_t val : rom_data) {
        program_memory->setData(PC->getValue(), val);
        PC->increment();
    }

    PC->setValue(PC_START);
}

void Processor::printStack(int radius) {
    register16_t start = std::max<int>(0, (int)(SP->getValue()) - radius);
    register16_t end =
        std::min<int>(SP_START + 1, (int)(SP->getValue()) + radius + 1);

    std::cout << "Stack: " << std::endl;
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::endl;
    byte_t value;
    while (start != end) {
        value = stack->getData(start);

        std::cout << "\t";
        Util::hexPrint(start, 4);
        std::cout << ": ";
        Util::hexPrint(value, 2);

        if (start == SP->getValue()) {
            std::cout << " <---";
        }

        std::cout << std::endl;
        ++start;
    }
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::endl;
    std::cout << "Done printing stack" << std::endl;
}

void Processor::printProgramMemory(int radius) {
    register16_t start = std::max<int>(0, (int)(PC->getValue()) - radius);
    register16_t end =
        std::min<int>(PC_MAX + 1, (int)(PC->getValue()) + radius + 1);

    std::cout << "Program memory: " << std::endl;
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::endl;
    byte_t value;
    while (start != end) {
        value = program_memory->getData(start);

        std::cout << "\t";
        Util::hexPrint(start, 4);
        std::cout << ": ";
        Util::hexPrint(value, 2);

        if (start == PC->getValue()) {
            std::cout << " <---";
        }

        std::cout << std::endl;
        ++start;
    }
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::endl;
    std::cout << "Done printing program memory" << std::endl;
}

void Processor::printPMAddressData(register16_t address) {
    byte_t data = program_memory->getData(address);
    std::cout << Util::hexString(data, 2) << std::endl;
}

void Processor::dump() {
    std::cout << "Printing processor" << std::endl;
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::endl;
    std::cout << "\t" << *A << "\t\t" << *B << std::endl
              << "\t" << *D << "\t\t" << *C << std::endl
              << "\t" << *E << "\t\t" << *F << std::endl
              << "\t" << *H << "\t\t" << *L << std::endl;

    std::cout << "\t" << *AF << "\t" << *BC << std::endl;
    std::cout << "\t" << *DE << "\t" << *HL << std::endl;
    std::cout << "\t" << *SP << "\t";
    std::cout << *PC << std::endl;
    std::cout << "\t"
              << "C: " << getFlagC();
    std::cout << "\t"
              << "H: " << getFlagH() << std::endl;
    std::cout << "\t"
              << "N: " << getFlagN();
    std::cout << "\t"
              << "Z: " << getFlagZ() << std::endl;

    std::cout << "\tCPU cycles: " << clock_cycles << std::endl;
    std::cout << "\tMachine cycles: " << machine_cycles << std::endl;
    std::cout << "\tExecuted instructions: " << executed_instructions
              << std::endl;
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::endl;
}

CPU_info Processor::getCPUInfo() const {
    CPU_info info { SP, PC };
    info.bit8_regs.push_back(A);
    info.bit8_regs.push_back(B);
    info.bit8_regs.push_back(C);
    info.bit8_regs.push_back(D);

    info.bit8_regs.push_back(E);
    info.bit8_regs.push_back(F);
    info.bit8_regs.push_back(H);
    info.bit8_regs.push_back(L);

    info.bit16_regs.push_back(AF);
    info.bit16_regs.push_back(BC);
    info.bit16_regs.push_back(DE);
    info.bit16_regs.push_back(HL);

    // Get some info from PM

    int radius = 5;
    register16_t start = std::max<int>(0, (int)(PC->getValue()) - radius);
    register16_t end =
        std::min<int>(PC_MAX + 1, (int)(PC->getValue()) + radius + 1);

    byte_t value;
    while (start != end) {
        value = program_memory->getData(start);

        info.PM.push_back({ start, value });
        ++start;
    }

    return info;
}