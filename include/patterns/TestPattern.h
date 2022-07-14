#pragma once

#include <cmath>

#include "Pattern.h"

using namespace std;

class TestPattern : public Pattern {
public:
    TestPattern(uint16_t newWidth, uint16_t newHeight) : Pattern(newWidth, newHeight) {};

    vector<PixelState> getUpdates() {
        vector<PixelState> updates;
        PixelState p;

        #pragma omp parallel for
        for (int y = 0; y < this->height; y++) {
            for (int x = 0; x < this->width; x++) {

                p.x = x;
                p.y = y;

                p.color = Color(
                    (sin(double(this->ms.count() + x * 250) / 10000) * 127) + 127,
                    (sin(double(this->ms.count() + y * 250) / 3333) * 127) + 127,
                    (sin(double(this->ms.count() + (x - y) * 250) / 7777) * 127) + 127
                );

                updates.push_back(p);
            }
        }

        return updates;
    };
};