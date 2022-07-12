#pragma once

#include <cstdint>
#include <chrono>

#include "MatrixState.h"
#include "LightInterface.h"
#include "Pattern.h"

#define DEFAULT_WIDTH   10
#define DEFAULT_HEIGHT  10
#define TPS 120

#define MS_PER_TICK (1/(TPS * 0.001))

class LightCore {
private:
    uint8_t activePatternIdx;
    const uint16_t width, height;
    std::chrono::milliseconds ms;
    MatrixState state;
    LightInterface interface;
    std::vector<Pattern*> patterns;
public:
    LightCore();
    LightCore(uint16_t newWidth, uint16_t newHeight);

    void tick(std::chrono::milliseconds newMs);
    void addPattern(Pattern* newPattern);

    void start();

    uint8_t getActivePatternIdx() {
        return this->activePatternIdx;
    };
    void nextPattern() {
        if ((this->activePatternIdx + 1) < this->patterns.size()) {
            this->activePatternIdx++;
        } else {
            this->activePatternIdx = 0;
        }
    }
};