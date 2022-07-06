#include <iostream>

#include "BufferPacker.h"
#include "CommandSender.h"

using namespace std;

int main(int argc, char **argv) {

    vector<LEDCommand> commands;

    for (int c = 0; c < 32; c++) {
        for (int r = 0; r < 32; r++) {
            LEDCommand newCommand;

            newCommand.column = c;
            newCommand.row = r;

            newCommand.r = 0;
            newCommand.g = c * 7;
            newCommand.b = r * 7;

            commands.push_back(newCommand);
        }
    }

    BufferPacker bp(commands);

    CommandSender cs("192.168.0.35", 10000);

    cout << int(cs.sendBuffer((unsigned char *) bp.getBuffer(), bp.getBufferSizeBytes())) << endl;

    return 0;
}