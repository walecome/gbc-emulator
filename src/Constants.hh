/*
    Useful constants and type declarations are defined in this file.
*/
#pragma once
#include <stdint.h>
#include <exception>
#include <functional>
#include <memory>
#include <stdexcept>

using opcode_t = uint8_t;
using byte_t = uint8_t;
using opcode_function = std::function<void()>;
constexpr const int NUMBER_OF_INSTRUCTIONS = 256;

constexpr const byte_t LSB_8BIT = 0x01;
constexpr const byte_t MSB_8BIT = 0x80;

// Register value constants

using register8_t = uint8_t;
using register16_t = uint16_t;

// ROM specific constants

// Starting position of program counter;
constexpr const register16_t PC_START = 0x100;
constexpr const register16_t PC_MAX = 0xFFFF;

// Starting position of stack pointer (Manual page 64)
constexpr const register16_t SP_START = 0xFFFE;

// Memory
constexpr const register16_t PC_MAX_SIZE = 0xFFFF;
constexpr const register16_t RAM_MAX_SIZE = 0xFFFF;
constexpr const register16_t RAM_DATA_OFFSET = 0xFF00;

// Flag bits (for AND operation on flag register)
constexpr const byte_t bit_c = 0x10;
constexpr const byte_t bit_h = 0x20;
constexpr const byte_t bit_n = 0x40;
constexpr const byte_t bit_z = 0x80;

template <typename T>
using ptr = std::shared_ptr<T>;