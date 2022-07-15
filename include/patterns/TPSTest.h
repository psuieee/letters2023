#pragma once

#include "Pattern.h"

class TPSTest : public Pattern {
public:
    TPSTest(uint16_t newWidth, uint16_t newHeight) : Pattern(newWidth, newHeight) {
        updates = vector<PixelState>(newWidth * newHeight, PixelState{});
    };

    vector<PixelState> getUpdates() {
        topWhite = !topWhite;

        if (topWhite) {
            this->setColor(this->white, this->black);
        } else {
            this->setColor(this->black, this->white);
        }

        return this->updates;
    };

private:
    Color black = Color(0, 0, 0);
    Color white = Color(255, 255, 255);
    bool topWhite = false;
    vector<PixelState> updates;

    void setColor(Color top, Color bot) {
        uint32_t target;

        for (int y = 0; y < this->height; y++) {
            for (int x = 0; x < (this->width / 2); x++) {
                target = (x * this->width) + y;

                updates[target].x = x;
                updates[target].y = y;
                updates[target].color = top;
            }
            for (int x = (this->width / 2); x < this->width; x++) {
                target = (x * this->width) + y;

                updates[target].x = x;
                updates[target].y = y;
                updates[target].color = bot;
            }
        }
    }
};