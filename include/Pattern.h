#pragma once

#include <chrono>
#include <vector>

#include "PixelState.h"

using namespace std;
using namespace std::chrono;

class Pattern {
public:
    Pattern(uint16_t width, uint16_t height, milliseconds initMs);

    vector<PixelState> tick(milliseconds newMs);

protected:
    virtual vector<PixelState> getUpdates() = 0;

    milliseconds ms;
    uint16_t width, height;
};