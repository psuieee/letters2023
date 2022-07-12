#pragma once

#include <chrono>
#include <random>

#include "Pattern.h"

using namespace std;
using namespace std::chrono;

class TestPattern : public Pattern {
public:
    TestPattern(uint16_t width, uint16_t height, milliseconds initMs) 
        : Pattern(width, height, initMs) {};

private:
    vector<PixelState> getUpdates() {
        vector<PixelState> updates;

        for (int h = 0; h < this->height; h++) {
            for (int w = 0; w < this->width; w++) {
                PixelState p;

                p.x = w;
                p.y = h;

                p.color.r = rand() % 256;
                p.color.g = rand() % 256;
                p.color.b = rand() % 256;

                updates.push_back(p);
            }
        }

        return updates;
    };
};