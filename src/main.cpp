#include <iostream>
#include <chrono>

#include "LightCore.h"
#include "patterns/TestPattern.h"
#include "patterns/GradientPattern.h"

#define LC_WIDTH 10
#define LC_HEIGHT 10

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {

    GradientPattern gp(10, 10, milliseconds(0));
    TestPattern tp(10, 10, milliseconds(0));

    LightCore lc(LC_WIDTH, LC_HEIGHT);

    lc.addPattern(&gp);
    lc.addPattern(&tp);

    lc.run();

    return 0;
}