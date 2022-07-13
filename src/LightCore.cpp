#include "LightCore.h"

using namespace std::chrono;

LightCore::LightCore(uint16_t newWidth, uint16_t newHeight, uint32_t newTPS, uint32_t newMsPerPattern) 
    : width{newWidth}, 
      height{newHeight}, 
      tps{newTPS},
      msPerPattern{newMsPerPattern},
      state(newWidth, newHeight), 
      interface(newWidth, newHeight, &state)
      {
  
  milliseconds currTime = duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
        );
  
  this->msAtLastTick = currTime;
  this->msAtLastPatternChange = currTime;
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

      // switch patterns if necessary
      if ((newms - this->msAtLastPatternChange).count() > this->msPerPattern) {
        this->msAtLastPatternChange = newms;
        this->nextPattern();
      }

      // tick if necessary
      if ((newms - this->msAtLastTick).count() > MS_PER_TICK(this->tps)) {
          this->msAtLastTick = newms;
          this->tick(this->msAtLastTick);
      }
    }
}

void LightCore::addPattern(Pattern *pattern) {
  this->patterns.push_back(pattern);
}

void LightCore::setCurrPattern(uint8_t idx) {
  this->currPatternIdx = idx;
}

void LightCore::nextPattern() {
  if (this->currPatternIdx + 1 < this->patterns.size()) {
    this->currPatternIdx++;
  } else {
    this->currPatternIdx = 0;
  }
}