#pragma once

#include <cstdint>

struct LEDCommand {
    uint32_t col, row;
    uint8_t r, g, b;
};