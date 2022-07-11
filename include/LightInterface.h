#pragma once

#include <cstdint>

#include "MatrixState.h"

class LightInterface {
public:
    LightInterface(uint16_t newWidth, uint16_t newHeight, MatrixState* state);

    void draw();

private:
    const uint16_t width, height;
    const MatrixState* state;

};