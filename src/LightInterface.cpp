#include "LightInterface.h"

using namespace cv;

LightInterface::LightInterface(
    uint16_t newWidth, uint16_t newHeight, MatrixState* newState) : 
    width{newWidth},
    height{newHeight},
    state{newState},
    image(newHeight, newWidth, CV_8UC3, Scalar(0, 0, 0))
    {}

void LightInterface::draw() {
    // update image with matrix state
    PixelState p;
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            p = this->state->getState(x, y);
            this->image.at<Vec3b>(Point(x, y)) = Vec3b(p.color.r, p.color.g, p.color.b);
        }
    }

    Mat scaledImage;
    resize(image, scaledImage, Size(100, 100));

    // show image 
    namedWindow("LightBoard", WINDOW_AUTOSIZE );
    imshow("LightBoard", scaledImage);

    waitKey(1);
}