#include "Pattern.h"

using namespace std::chrono;

Pattern::Pattern() : Pattern(milliseconds(0)) {}

Pattern::Pattern(milliseconds startMs) {
    this->ms = startMs;
}