#pragma once

#include "Pattern.h"

class TPSCheck : public Pattern {
public:
    TPSCheck(uint16_t newWidth, uint16_t newHeight) : Pattern(newWidth, newHeight) {};

    vector<PixelState> getUpdates() {
        topWhite = !topWhite;

        vector<PixelState> updates;
        PixelState p;

        Color white = Color(255, 255, 255);
        Color black = Color(0, 0, 0);

        for (int x = 0; x < this->width; x++) {
            p.x = x;

            if (topWhite) {
                p.color = white;
                for (int y = 0; y < (this->height / 2); y++) {
                    p.y = y;
                    updates.push_back(p);
                }

                p.color = black;
                for (int y = (this->height / 2); y < this->height; y++) {
                    p.y = y;
                    updates.push_back(p);
                }
            } else {
                p.color = black;
                for (int y = 0; y < (this->height / 2); y++) {
                    p.y = y;
                    updates.push_back(p);
                }

                p.color = white;
                for (int y = (this->height / 2); y < this->height; y++) {
                    p.y = y;
                    updates.push_back(p);
                }
            }
        }

        return updates;
    };

private:
    bool topWhite = false;
};