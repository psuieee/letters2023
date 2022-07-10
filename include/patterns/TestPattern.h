#pragma once

#include "Pattern.h"

using namespace std::chrono;

class TestPattern : public Pattern {
public:
    TestPattern(int newNColumns, int newNRows) : Pattern() {
        this->nColumns = newNColumns;
        this->nRows = newNRows;
    }

    std::vector<LEDCommand> step(milliseconds newMs) {
        
        std::vector<LEDCommand> commands;
        
        if ((this->ms + milliseconds(10)) < newMs) {

            // increment target column
            if ((this->targetCol + 1) < this->nColumns) {
                this->targetCol++;
            } else {
                this->targetCol = 0;
            }
            
            // increment target row
            if ((this->targetCol == 0) && ((this->targetRow + 1) < this->nRows)) {
                this->targetRow++;
            } else {
                this->targetRow = 0;
            }

            for (int i = 0; i < this->nColumns; i++) {
                for (int j = 0; j < this->nRows; j++) {
                    LEDCommand c;

                    c.col = i;
                    c.row = j;

                    if (i == this->targetCol) {
                        c.r = 255;
                    } else {
                        c.r = 0;
                    }

                    if (j == this->targetRow) {
                        c.g = 255;
                    } else {
                        c.g = 0;
                    }

                    c.b = 255;

                    commands.push_back(c);
                }
            }
        }

        return commands;
    }

private:
    int nColumns, nRows;
    int targetCol = 0, targetRow = 0;

};