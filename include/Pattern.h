#pragma once

#include <vector>
#include <chrono>

#include "LEDCommand.h"

class Pattern {
public:
    Pattern(); // defaults to Pattern(0, 0)
    Pattern(std::chrono::milliseconds startMs);
    virtual std::vector<LEDCommand> step(std::chrono::milliseconds newMs) = 0;

protected:
    std::chrono::milliseconds ms;
};