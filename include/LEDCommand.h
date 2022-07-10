#pragma once

#include <cstdint>

struct LEDCommand {
    uint32_t column, row;
    uint8_t r, g, b;
};