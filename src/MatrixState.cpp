#include "MatrixState.h"

/**
 * @brief MatrixState Constructor
 * 
 * @param newWidth  width of matrix in # of leds
 * @param newHeight height of matrix in # of leds
 */
MatrixState::MatrixState(uint16_t newWidth, uint16_t newHeight) 
    : width{newWidth}, height{newHeight} {

    // make state array
    this->state = std::vector<std::vector<Color>>(
        this->height, 
        std::vector<Color>(this->width, Color{0, 0, 0})
        );

}

/**
 * @brief Update state of matrix with a list of updates
 * 
 * @param updates vector of pixel state updates
 */
void MatrixState::updateState(std::vector<PixelState> updates) {
    for (PixelState update : updates) {
        (this->state)[update.y][update.x] = update.color;
    }
}

/**
 * @brief Get the entire matrix state
 * 
 * @return std::vector<PixelState> 
 */
std::vector<PixelState> MatrixState::getState() {
    std::vector<PixelState> fullState;

    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            fullState.push_back(this->getState(x, y));
        }
    }

    return fullState;
}

/**
 * @brief Get the state of a single pixel in the matrix
 * 
 * @param x x-coordinate
 * @param y y-coordinate
 * @return PixelState 
 */
PixelState MatrixState::getState(uint16_t x, uint16_t y) {
    PixelState p;

    p.x = x;
    p.y = y;
    p.color = this->state[y][x];

    return p;
}