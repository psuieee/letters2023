#pragma once

#include <cstdint>

class Color {
public:
    Color() : Color(0, 0, 0) {};
    Color(uint8_t r, uint8_t g, uint8_t b) { // rgb
        this->r = r;
        this->g = g;
        this->b = b;
    };
    Color(float c, float m, float y, float k) { // cmyk
        if (c < 0) {
            c = 0;
        } else if (c > 1) {
            c = 1;
        }

        if (y < 0) {
            y = 0;
        } else if (y > 1) {
            y = 1;
        }

        if (m < 0) {
            m = 0;
        } else if (m > 1) {
            m = 1;
        }

        if (k < 0) {
            k = 0;
        } else if (c > 1) {
            k = 1;
        }

        this->r = 255 * (1 - c) * (1 - k);
        this->g = 255 * (1 - m) * (1 - k);
        this->b = 255 * (1 - y) * (1 - k);
    };

    uint8_t r, g, b;
};