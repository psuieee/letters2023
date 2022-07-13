#pragma once

#include <cstdint>
#include <vector>

#include "PixelState.h"

class MatrixState {
public:
    MatrixState(uint16_t width, uint16_t height);

    void updateState(std::vector<PixelState> updates);

    // state getters
    std::vector<PixelState> getState();
    PixelState              getState(uint16_t x, uint16_t y);

private:
    const uint16_t width, height;
    std::vector<std::vector<Color>> state;
};