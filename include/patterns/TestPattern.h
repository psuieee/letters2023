#pragma once

#include "Pattern.h"

using namespace std;

class TestPattern : public Pattern {
public:
    TestPattern(uint16_t newWidth, uint16_t newHeight) : Pattern(newWidth, newHeight) {};

    vector<PixelState> getUpdates() {
        vector<PixelState> updates;

        for (int y = 0; y < this->height; y++) {
            for (int x = 0; x < this->width; x++) {
                PixelState p;

                p.x = x;
                p.y = y;

                p.color.r = x * (255 / this->width);
                p.color.g = y * (255 / this->height);
                p.color.b = 0;

                updates.push_back(p);
            }
        }

        return updates;
    };
};