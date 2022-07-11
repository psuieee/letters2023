#pragma once

#include <cstdint>

#include "Color.h"

struct PixelState {
    uint16_t x, y;
    Color color;
};