#pragma once

#include "Pattern.h"

class AllWhite : public Pattern {
public:
    AllWhite(uint16_t newWidth, uint16_t newHeight) : Pattern(newWidth, newHeight) {};

    vector<PixelState> getUpdates() {
        vector<PixelState> updates;
        PixelState p;

        for (int y = 0; y < this->height; y++) {
            for (int x = 0; x < this->width; x++) {
                PixelState p;

                p.x = x;
                p.y = y;

                p.color.r = 255;
                p.color.g = 255;
                p.color.b = 255;

                updates.push_back(p);
            }
        }

        return updates;
    };
};