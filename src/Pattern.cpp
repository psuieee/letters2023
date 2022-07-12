#include "Pattern.h"

using namespace std;
using namespace std::chrono;

Pattern::Pattern(uint16_t width, uint16_t height, milliseconds initMs) {
    this->ms = initMs;
    this->width = width;
    this->height = height;
}

vector<PixelState> Pattern::tick(milliseconds newMs) {
    this->ms = newMs;

    return this->getUpdates();
}