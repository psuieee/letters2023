#pragma once

#include "Pattern.h"

class TPSTest : public Pattern {
public:
    TPSTest(uint16_t newWidth, uint16_t newHeight) : Pattern(newWidth, newHeight) {
        this->leftwhitestate = (Color *) calloc(this->height * this->width, sizeof(Color(0, 0, 0)));
        this->rightwhitestate = (Color *) calloc(this->height * this->width, sizeof(Color(0, 0, 0)));

        for (int y = 0; y < this->height; y++) {
            for (int x = 0; x < (this->width / 2); x++) {
                this->leftwhitestate[y * this->height + x] = white;
            }
            for (int x = (this->width / 2); x < this->width; x++) {
                this->leftwhitestate[y * this->height + x] = black;
            }
        }

        for (int y = 0; y < this->height; y++) {
            for (int x = 0; x < (this->width / 2); x++) {
                this->rightwhitestate[y * this->height + x] = black;
            }
            for (int x = (this->width / 2); x < this->width; x++) {
                this->rightwhitestate[y * this->height + x] = white;
            }
        }
    };

    Color * getUpdates() {
        this->leftWhite = !this->leftWhite;

        if (leftWhite) {
            return leftwhitestate;
        } else {
            return rightwhitestate;
        }
    };

private:
    Color black = Color(0, 0, 0);
    Color white = Color(255, 255, 255);
    bool leftWhite = false;
    Color *leftwhitestate, *rightwhitestate;
};