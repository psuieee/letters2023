#include <iostream>

#include "BufferPacker.h"

using namespace std;

int main(int argc, char **argv) {

    BufferPacker bp(3);

    bp.addCommand(0, 0, 0, 0, 0);
    bp.addCommand(1, 1, 255, 0, 0);
    bp.addCommand(1, 0, 0, 255, 0);

    return 0;
}