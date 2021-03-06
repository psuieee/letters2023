#pragma once

#include <cstdint>
#include <opencv2/opencv.hpp>

#include "MatrixState.h"
#include "Color.h"

#define LIGHTBOARD_WIDTH_PX     500
#define LIGHTBOARD_HEIGHT_PX    500

class LightInterface {
public:
    LightInterface(uint16_t newWidth, uint16_t newHeight, MatrixState* state);

    void draw();

private:
    const uint16_t width, height;
    MatrixState* state;

    cv::Mat image;
};