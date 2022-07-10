#include "LetterCore.h"

LetterCore::LetterCore(const char *ip, int port) 
    : commandSender(ip, port) {}

LetterCore::LetterCore(const char *ip, int port, std::vector<Pattern*> initialPatterns) 
    : commandSender(ip, port) {
        for (Pattern* pattern : initialPatterns) {
            this->addPattern(pattern);
        }
}

void LetterCore::addPattern(Pattern* pattern) {
    this->patterns.push_back(pattern);
}

int LetterCore::nextPattern() {
    if ((this->activePatternIdx + 1) < this->nTotalPatterns) {
        this->activePatternIdx++;
    } else {
        this->activePatternIdx = 0;
    }

    return this->activePatternIdx;
}

int LetterCore::setActivePatternIdx(int i) {
    if (0 <= i < (this->nTotalPatterns - 1)) {
        this->activePatternIdx = i;
    }

    return this->activePatternIdx;
}

void LetterCore::step(uint32_t timeSeconds, uint16_t timeMilliseconds) {
    std::vector<LEDCommand> commands = this->patterns[this->activePatternIdx]->step(timeSeconds, timeMilliseconds);

    BufferPacker bp(commands);

    this->commandSender.sendBuffer(
        (unsigned char *) bp.getBuffer(),
        bp.getBufferSizeBytes()
    );
} 