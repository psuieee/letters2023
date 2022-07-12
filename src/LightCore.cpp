#include "LightCore.h"

using namespace std::chrono;

LightCore::LightCore() : LightCore(DEFAULT_WIDTH, DEFAULT_HEIGHT) {}

LightCore::LightCore(uint16_t newWidth, uint16_t newHeight) 
    : width{newWidth}, 
      height{newHeight}, 
      state(newWidth, newHeight), 
      interface(newWidth, newHeight, &state)
      {
}

void LightCore::tick(milliseconds newMs) {
  std::vector<PixelState> updates = this->patterns[this->activePatternIdx]->tick(newMs);

  this->state.updateState(updates);

  this->interface.draw();
}

void LightCore::addPattern(Pattern* newPattern) {
  this->patterns.push_back(newPattern);
}

void LightCore::start() {
  while (true) {
        milliseconds newms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

        if ((newms - this->ms).count() > MS_PER_TICK) {
            this->ms = newms;
            this->tick(this->ms);
        }
    }
}