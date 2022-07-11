#include "MatrixState.h"

MatrixState::MatrixState(uint16_t newWidth, uint16_t newHeight) 
    : width{newWidth}, height{newHeight} {

    // make state array
    this->state = new Color *[this->height];
    for (int i = 0; i < this->height; i++) {
        this->state[i] = new Color[this->width];
    }
}

MatrixState::~MatrixState() {

}