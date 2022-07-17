#pragma once

#include <cstdint>
#include <vector>
#include <stdlib.h>

#include "Color.h"

class MatrixState {
public:
    MatrixState(uint16_t width, uint16_t height);

    void updateState(Color *newState);

    // state getters
    Color * getState();

    const uint16_t width, height;

private:
    Color *state;
};