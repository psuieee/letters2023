#include "MatrixState.h"

MatrixState::MatrixState(uint16_t newWidth, uint16_t newHeight) 
    : width{newWidth}, height{newHeight} {

    // make state array
    this->state = std::vector<std::vector<Color>>(this->height, std::vector<Color>(this->width, Color{0, 0, 0}));

}

MatrixState::~MatrixState() {

}

void MatrixState::updateState(std::vector<PixelState> updates) {
    for (PixelState update : updates) {
        (this->state)[update.y][update.x] = update.color;
    }
}

std::vector<PixelState> MatrixState::getState() {
    std::vector<PixelState> fullState;

    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            fullState.push_back(this->getState(x, y));
        }
    }

    return fullState;
}

PixelState MatrixState::getState(uint16_t x, uint16_t y) {
    PixelState p;

    p.x = x;
    p.y = y;
    p.color = this->state[y][x];

    return p;
}