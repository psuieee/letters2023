#include <iostream>
#include <chrono>

#include "LightCore.h"

// patterns
#include "patterns/TPSTest.h"

#define LC_WIDTH    32
#define LC_HEIGHT   32
#define LC_TPS      30
#define LC_MS_PATT  5000

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {

    // declare patterns
    TPSTest tt(LC_WIDTH, LC_HEIGHT);

    // declare the core
    LightCore lc(LC_WIDTH, LC_HEIGHT, LC_TPS, LC_MS_PATT);

    // add the patterns
    lc.addPattern(&tt);

    // set the core running
    lc.run();

    return 0;
}