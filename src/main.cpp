#include <iostream>

#include "BufferPacker.h"
#include "CommandSender.h"

using namespace std;

int main(int argc, char **argv) {

    BufferPacker bp(4);

    bp.addCommand(0, 0, 255, 255, 255);
    bp.addCommand(1, 1, 255, 0, 0);
    bp.addCommand(1, 0, 0, 255, 0);
    bp.addCommand(0, 1, 0, 0, 255);

    CommandSender cs("192.168.0.35", 10000);

    cs.sendBuffer((unsigned char *) bp.getBuffer(), bp.getBufferSizeBytes());

    return 0;
}