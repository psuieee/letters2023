#pragma once

#include <cstdint>

#include "MatrixState.h"
#include "LightInterface.h"

#define DEFAULT_WIDTH   10
#define DEFAULT_HEIGHT  10

class LightCore {
public:
    LightCore();
    LightCore(uint16_t newWidth, uint16_t newHeight);

    void tick();

private:
    const uint16_t width, height;
    MatrixState state;
    LightInterface interface;
};