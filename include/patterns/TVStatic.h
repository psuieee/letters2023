#pragma once

#include <random>

#include "Pattern.h"

class TVStatic : public Pattern {
public:
    TVStatic(uint16_t newWidth, uint16_t newHeight) : Pattern(newWidth, newHeight) {};

    vector<PixelState> getUpdates() {
        vector<PixelState> updates;
        PixelState p;

        #pragma omp parallel for collapse(2)
        for (int y = 0; y < this->height; y++) {
            for (int x = 0; x < this->width; x++) {
                PixelState p;

                p.x = x;
                p.y = y;

                if ((rand() % 2) == 0) {
                    p.color.r = 255;
                    p.color.g = 255;
                    p.color.b = 255;
                } else {
                    p.color.r = 0;
                    p.color.g = 0;
                    p.color.b = 0;
                }

                updates.push_back(p);
            }
        }

        return updates;
    };
};