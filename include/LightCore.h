#pragma once

#include <cstdint>
#include <chrono>

#include "MatrixState.h"
#include "LightInterface.h"
#include "Pattern.h"

#define TPS 120

#define MS_PER_TICK (1/(TPS * 0.001))

class LightCore {
private:
    const uint16_t width, height;
    std::chrono::milliseconds ms;
    MatrixState state;
    LightInterface interface;

    Pattern **patterns;
    uint8_t totalNPatterns;
    uint8_t currPatternIdx = 0;

    void tick(std::chrono::milliseconds newMs);

public:
    LightCore(uint16_t newWidth, uint16_t newHeight, uint8_t newNPatterns);
    void run();

    void setPattern(Pattern *pattern, uint8_t idx);

    void setCurrPattern(uint8_t idx);
    void nextPattern();
};