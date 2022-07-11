#pragma once

#include <cstdint>
#include <chrono>

#include "MatrixState.h"
#include "LightInterface.h"

#define DEFAULT_WIDTH   10
#define DEFAULT_HEIGHT  10

class LightCore {
public:
    LightCore();
    LightCore(uint16_t newWidth, uint16_t newHeight);

    void tick(std::chrono::milliseconds newMs);

private:
    const uint16_t width, height;
    std::chrono::milliseconds ms;
    MatrixState state;
    LightInterface interface;
};