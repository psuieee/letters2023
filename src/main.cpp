#include <iostream>
#include <chrono>

#include "LightCore.h"

#define LC_WIDTH 10
#define LC_HEIGHT 10

using namespace std;

int main(int argc, char **argv) {

    LightCore lc(LC_WIDTH, LC_HEIGHT);

    while (true) {
        lc.tick(std::chrono::milliseconds(0));
    }

    return 0;
}