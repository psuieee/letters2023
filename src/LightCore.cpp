#include "LightCore.h"

LightCore::LightCore() : LightCore(DEFAULT_WIDTH, DEFAULT_HEIGHT) {}

LightCore::LightCore(uint16_t newWidth, uint16_t newHeight) 
    : width{newWidth}, 
      height{newHeight}, 
      state(newWidth, newHeight), 
      interface(newWidth, newHeight, &state)
      {
}

void LightCore::tick() {

}