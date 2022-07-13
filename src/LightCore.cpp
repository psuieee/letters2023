#include "LightCore.h"

using namespace std::chrono;

LightCore::LightCore(uint16_t newWidth, uint16_t newHeight, uint8_t newNPatterns) 
    : width{newWidth}, 
      height{newHeight}, 
      state(newWidth, newHeight), 
      interface(newWidth, newHeight, &state)
      {
  this->ms = milliseconds(0);
  this->totalNPatterns = newNPatterns;
  this->patterns = new Pattern* [newNPatterns];
}

void LightCore::tick(milliseconds newMs) {

  // get updates from the pattern
  std::vector<PixelState> updates = this->patterns[this->currPatternIdx]->tick(newMs);

  // update the matrix state
  this->state.updateState(updates);

  // have the lights reflect the matrix state
  this->interface.draw();
}

void LightCore::run() {
  while (true) {
      // check the time
      milliseconds newms = duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
        );

      // tick if necessary
      if ((newms - this->ms).count() > MS_PER_TICK) {
          this->ms = newms;
          this->tick(this->ms);
      }
    }
}

void LightCore::setPattern(Pattern *pattern, uint8_t idx) {
  this->patterns[idx] = pattern;
}

void LightCore::setCurrPattern(uint8_t idx) {
  this->currPatternIdx = idx;
}

void LightCore::nextPattern() {
  if (this->currPatternIdx + 1 < this->totalNPatterns) {
    this->currPatternIdx++;
  } else {
    this->currPatternIdx = 0;
  }
}