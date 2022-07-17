#pragma once

#include <cstdint>
#include <vector>
#include <chrono>
#include <stdlib.h>

#include "Color.h"

class Pattern {
public:
    Pattern(uint16_t newWidth, uint16_t newHeight) {
        this->width = newWidth;
        this->height = newHeight;
    };

    Color * tick(std::chrono::milliseconds newms) {
        this->ms = newms;

        return getUpdates();
    }

protected:
    virtual Color * getUpdates() = 0;

    std::chrono::milliseconds ms;
    uint16_t width, height;
};