#pragma once

#include "Pattern.h"

class TPSTest : public Pattern {
public:
    TPSTest(uint16_t newWidth, uint16_t newHeight) : Pattern(newWidth, newHeight) {
        this->state = (Color *) calloc(this->height * this->width, sizeof(Color(0, 0, 0)));
    };

    Color * getUpdates() {
        this->leftWhite = !this->leftWhite;

        if (leftWhite) {
            #pragma omp parallel for
            for (int y = 0; y < this->height; y++) {
                for (int x = 0; x < (this->width / 2); x++) {
                    this->state[y * this->height + x] = white;
                }
                for (int x = (this->width / 2); x < this->width; x++) {
                    this->state[y * this->height + x] = black;
                }
            }
        } else {
            #pragma omp parallel for
            for (int y = 0; y < this->height; y++) {
                for (int x = 0; x < (this->width / 2); x++) {
                    this->state[y * this->height + x] = black;
                }
                for (int x = (this->width / 2); x < this->width; x++) {
                    this->state[y * this->height + x] = white;
                }
            }
        }

        return this->state;
    };

private:
    Color black = Color(0, 0, 0);
    Color white = Color(255, 255, 255);
    bool leftWhite = false;
    Color *state;
};