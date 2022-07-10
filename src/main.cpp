#include <iostream>
#include <chrono>

#include "LetterCore.h"
#include "patterns/TestPattern.h"

using namespace std;

int main(int argc, char **argv) {

    std::vector<Pattern*> patterns;

    patterns.push_back(new TestPattern(32, 32));

    LetterCore core("192.168.0.2", 10000, patterns);

    while (true) {
        std::chrono::milliseconds s = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
            );

        core.step(s);
    }
    

    return 0;
}