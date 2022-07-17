#include "LightCore.h"

using namespace std::chrono;

/**
 * @brief LightCore constructor
 * 
 * @param newWidth        width of matrix in # of leds
 * @param newHeight       height of matrix in # of leds
 * @param newTPS          maximum tps to run the matrix
 * @param newMsPerPattern ms per change of pattern
 */
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

/**
 * @brief Do one tick
 * 
 * The core will tell the active pattern to tick, use the returned value to
 * update the matrix state, and tell the light interface to redraw the lights.
 * 
 * @param newMs current time
 */
void LightCore::tick(milliseconds newMs) {

  // get updates from the pattern
  Color * updates = this->patterns[this->currPatternIdx]->tick(newMs);

  // update the matrix state
  this->state.updateState(updates);

  // have the lights reflect the matrix state
  this->interface.draw();
}

/**
 * @brief Run the lights
 * 
 * Run will start an infinite loop to check the time and switch patterns and/or
 * tick if necessary.
 * 
 */
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

      std::this_thread::sleep_for(milliseconds(1));
    }
}

/**
 * @brief Add pattern
 * 
 * Add a pattern to the core's pattern list
 * 
 * @param pattern pointer to pattern
 */
void LightCore::addPattern(Pattern *pattern) {
  this->patterns.push_back(pattern);
}

/**
 * @brief Set the current pattern
 * 
 * Set the current pattern to be the pattern at the given index
 * 
 * @param idx index of desired pattern
 */
void LightCore::setCurrPattern(uint8_t idx) {
  this->currPatternIdx = idx;
}

/**
 * @brief Go to the next pattern
 * 
 * Go to the next pattern or roll over to the first pattern
 * 
 */
void LightCore::nextPattern() {
  if (this->currPatternIdx + 1 < this->patterns.size()) {
    this->currPatternIdx++;
  } else {
    this->currPatternIdx = 0;
  }
}