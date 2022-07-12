#pragma once

#include <chrono>
#include <random>

#include "Pattern.h"

using namespace std;
using namespace std::chrono;

class GradientPattern : public Pattern {
public:
    GradientPattern(uint16_t width, uint16_t height, milliseconds initMs) 
        : Pattern(width, height, initMs) {};

private:
    vector<PixelState> getUpdates() {
        vector<PixelState> updates;

        for (int h = 0; h < this->height; h++) {
            for (int w = 0; w < this->width; w++) {
                PixelState p;

                p.x = w;
                p.y = h;

                p.color.r = w * (255 / this->width);
                p.color.g = h * (255 / this->height);
                p.color.b = 0;

                updates.push_back(p);
            }
        }

        return updates;
    };
};