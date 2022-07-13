#pragma once

#include <cstdint>
#include <vector>
#include <chrono>

#include "PixelState.h"

class Pattern {
public:
    Pattern(uint16_t newWidth, uint16_t newHeight) {
        this->width = newWidth;
        this->height = newHeight;

    };

    std::vector<PixelState> tick(std::chrono::milliseconds newms) {
        this->ms = newms;

        return getUpdates();
    }

protected:
    virtual std::vector<PixelState> getUpdates() = 0;

    std::chrono::milliseconds ms;
    uint16_t width, height;
};