#include <iostream>
#include <chrono>

#include "LightCore.h"

#define LC_WIDTH 10
#define LC_HEIGHT 10

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {

    LightCore lc(LC_WIDTH, LC_HEIGHT);

    lc.run();

    return 0;
}