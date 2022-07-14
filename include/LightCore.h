#pragma once

#include <cstdint>
#include <chrono>
#include <thread>

#include "MatrixState.h"
#include "LightInterface.h"
#include "Pattern.h"

#define MS_PER_TICK(X) (1/(X * 0.001))

class LightCore {
private:
    const uint16_t width, height;
    const uint32_t tps, msPerPattern;
    std::chrono::milliseconds msAtLastTick, msAtLastPatternChange;
    MatrixState state;
    LightInterface interface;

    std::vector<Pattern*> patterns;
    uint8_t currPatternIdx = 0;

    void tick(std::chrono::milliseconds newMs);

public:
    LightCore(uint16_t newWidth, uint16_t newHeight, uint32_t newTPS, uint32_t newMsPerPattern);
    void run();

    void addPattern(Pattern *pattern);

    void setCurrPattern(uint8_t idx);
    void nextPattern();
};