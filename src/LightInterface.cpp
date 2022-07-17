#include "LightInterface.h"

using namespace cv;

/**
 * @brief LightInterface constructor
 * 
 * @param newWidth  width of matrix in # of leds
 * @param newHeight height of matrix in # of leds
 * @param newState  pointer to matrix state object
 */
LightInterface::LightInterface(
    uint16_t newWidth, uint16_t newHeight, MatrixState* newState) : 
    width{newWidth},
    height{newHeight},
    state{newState},
    image(newHeight, newWidth, CV_8UC3, Scalar(0, 0, 0))
{       
    namedWindow("LightBoard", WINDOW_AUTOSIZE );
}

/**
 * @brief Draw
 * 
 * Updates lights using the MatrixState
 * 
 */
void LightInterface::draw() {
    // update image with matrix state
    Color *c = this->state->getState();
    for (uint16_t y = 0; y < this->height; y++) {
        for (uint16_t x = 0; x < this->width; x++) {
            this->image.at<Vec3b>(Point(x, y)) = Vec3b(
                c[y * this->state->height + x].b,
                c[y * this->state->height + x].g,
                c[y * this->state->height + x].r
                );
        }
    }

    Mat scaledImage;
    resize(image, scaledImage, Size(LIGHTBOARD_WIDTH_PX, LIGHTBOARD_HEIGHT_PX));

    // show image
    imshow("LightBoard", scaledImage);

    waitKey(1);
}