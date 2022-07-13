#include <iostream>
#include <chrono>

#include "LightCore.h"
#include "patterns/TestPattern.h"

#define LC_WIDTH    32
#define LC_HEIGHT   32

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {

    TestPattern tp(LC_WIDTH, LC_HEIGHT);

    LightCore lc(LC_WIDTH, LC_HEIGHT);

    lc.addPattern(&tp);

    lc.run();

    return 0;
}