#pragma once

#include <vector>

#include "LEDCommand.h"

class Pattern {
public:
    Pattern(); // defaults to Pattern(0, 0)
    Pattern(uint32_t startTimeSeconds, uint16_t startTimeMilliseconds);
    virtual std::vector<LEDCommand> step(uint32_t timeSeconds, uint16_t timeMilliseconds) = 0;

private:
    uint32_t seconds;
    uint16_t milliseconds;
};