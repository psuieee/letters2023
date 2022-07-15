#pragma once

#include <random>

#include "Pattern.h"

class TVStatic : public Pattern {
public:
    TVStatic(uint16_t newWidth, uint16_t newHeight) : Pattern(newWidth, newHeight) {
        this->updates = vector<PixelState>(newWidth * newHeight, PixelState{});
        for (int y = 0; y < this->height; y++) {
            for (int x = 0; x < this->width; x++) {
                uint32_t fullTarget = (y * this->height) + x;

                this->updates[fullTarget].x = x;
                this->updates[fullTarget].y = y;
            }
        }
    };

    vector<PixelState> getUpdates() {
        uint32_t fullTarget;

        for (int y = 0; y < this->height; y++) {
            for (int x = 0; x < this->width; x++) {
                fullTarget = (y * this->height) + x;

                if ((rand() % 2) == 0) {
                    this->updates[fullTarget].color = white;
                } else {
                    this->updates[fullTarget].color = black;
                }
                
            }
        }

        return updates;
    };

private:
    Color white = Color(255, 255, 255);
    Color black = Color(0, 0, 0);
    vector<PixelState> updates;
};