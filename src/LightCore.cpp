#include "LightCore.h"

using namespace std::chrono;

LightCore::LightCore() : LightCore(DEFAULT_WIDTH, DEFAULT_HEIGHT) {}

LightCore::LightCore(uint16_t newWidth, uint16_t newHeight) 
    : width{newWidth}, 
      height{newHeight}, 
      state(newWidth, newHeight), 
      interface(newWidth, newHeight, &state)
      {
  this->ms = milliseconds(0);
}

void LightCore::tick(milliseconds newMs) {

  // get updates from the pattern
  std::vector<PixelState> updates = this->patterns[this->activePatternIdx]->tick(newMs);

  // update the matrix state
  this->state.updateState(updates);

  // have the lights reflect the matrix state
  this->interface.draw();
}

void LightCore::addPattern(Pattern* newPattern) {
  this->patterns.push_back(newPattern);
}

void LightCore::run() {
  while (true) {
      // check the time
      milliseconds newms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

      // tick if necessary
      if ((newms - this->ms).count() > MS_PER_TICK) {
          this->ms = newms;
          this->tick(this->ms);
      }
    }
}