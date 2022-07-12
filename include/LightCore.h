#pragma once

#include <cstdint>
#include <chrono>

#include "MatrixState.h"
#include "LightInterface.h"

#define DEFAULT_WIDTH   10
#define DEFAULT_HEIGHT  10
#define MS_PER_PATTERN_CHANGE 5000
#define TPS 120

#define MS_PER_TICK (1/(TPS * 0.001))

class LightCore {
private:
    const uint16_t width, height;
    std::chrono::milliseconds ms;
    MatrixState state;
    LightInterface interface;
public:
    LightCore();
    LightCore(uint16_t newWidth, uint16_t newHeight);

    void tick(std::chrono::milliseconds newMs);

    void run();
};