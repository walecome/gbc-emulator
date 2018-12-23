#include "Processor.hh"

void Processor::readInstructions(const char *filename)
{
    // open the file as binary
    std::ifstream file(filename, std::ios::binary);

    // Stop eating new lines in binary mode
    file.unsetf(std::ios::skipws);

    std::streampos fileSize;

    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // reserve capacity
    instructions.reserve(fileSize);

    // read the data:
    instructions.insert(instructions.begin(),
                        std::istream_iterator<opcode_t>(file),
                        std::istream_iterator<opcode_t>());
}