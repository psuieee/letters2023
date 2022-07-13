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
        double rxSin, gxSin, bxSin, rySin, gySin, bySin;

        for (int y = 0; y < this->height; y++) {
            for (int x = 0; x < this->width; x++) {
                PixelState p;

                p.x = x;
                p.y = y;

                rxSin = sin((double(x) / double(this->width) * 2 * M_PI) + (double(this->ms.count()) / 10000));
                gxSin = sin((double(x) / double(this->width) * 2 * M_PI) + (double(this->ms.count()) / 7777));
                bxSin = sin((double(x) / double(this->width) * 2 * M_PI) + (double(this->ms.count()) / 5555));
                rySin = sin((double(y) / double(this->width) * 2 * M_PI) + (double(this->ms.count()) / 3333));
                gySin = sin((double(y) / double(this->width) * 2 * M_PI) + (double(this->ms.count()) / 1111));
                bySin = sin((double(y) / double(this->width) * 2 * M_PI) + (double(this->ms.count()) / 555));

                p.color.r = (127 * rxSin * rySin) + 127;
                p.color.g = (127 * gxSin * gySin) + 127;
                p.color.b = (127 * bxSin * bySin) + 127;

                updates.push_back(p);
            }
        }

        return updates;
    };
};