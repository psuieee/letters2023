#include "MatrixState.h"

/**
 * @brief MatrixState Constructor
 * 
 * @param newWidth  width of matrix in # of leds
 * @param newHeight height of matrix in # of leds
 */
MatrixState::MatrixState(uint16_t newWidth, uint16_t newHeight) 
    : width{newWidth}, height{newHeight} {

    this->state = new Color[this->height * this->width];
}

/**
 * @brief Update state of matrix with a list of updates
 * 
 * @param updates vector of pixel state updates
 */
void MatrixState::updateState(Color *newState) {
    this->state = newState;
}

/**
 * @brief Get the entire matrix state
 * 
 * @return std::vector<PixelState> 
 */
Color * MatrixState::getState() {
    return this->state;
}