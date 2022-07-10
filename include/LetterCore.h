#pragma once

#include <vector>

#include "Pattern.h"
#include "CommandSender.h"
#include "BufferPacker.h"

class LetterCore {
public:
    LetterCore(const char *ip, int port);
    LetterCore(const char *ip, int port, std::vector<Pattern*> initialPatterns);

    void addPattern(Pattern* pattern);

    int nextPattern(); // go to the next pattern
    int setActivePatternIdx(int i); // change pattern to a specific pattern
    int getActivePatternIdx();

    void step(uint32_t timeSeconds, uint16_t timeMilliseconds); // calls step() of active pattern

private:
    int nTotalPatterns;
    int activePatternIdx;

    std::vector<Pattern*> patterns;

    CommandSender commandSender;
};