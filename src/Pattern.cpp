#include "Pattern.h"

Pattern::Pattern() : Pattern(0, 0) {}

Pattern::Pattern(uint32_t startTimeSeconds, uint16_t startTimeMilliseconds) {
    this->seconds = startTimeSeconds;
    this->milliseconds = startTimeMilliseconds;
}