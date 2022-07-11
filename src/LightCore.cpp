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
  this->state.updateState({PixelState{0, 0, 255, 255, 255}});

  interface.draw();

}