/*
 * BufferPacker.h
 *
 * Copyright (c) Will McGloughlin 2022
 *
 * Class for generating command buffer to address individual LEDs in a matrix.
 * The buffer will consist of a number of LED commands, structured as follows:
 *
 * | Name      | Bytes | Datatype  | Description                                  |
 * |-----------|-------|-----------|----------------------------------------------|
 * | Column    | 4     | uint32_t  | Column # of target LED (leftmost column is 0,|
 * |           |       |           | rightmost column is width-1)                 |
 * | Row       | 4     | uint32_t  | Row # of target LED (bottom row is 0, topmost|
 * |           |       |           | row is height-1)                             |
 * | Red       | 1     | uint8_t   | Red component of LED color (0-255)           |
 * | Green     | 1     | uint8_t   | Green component of LED color (0-255)         |
 * | Blue      | 1     | uint8_t   | Blue component of LED color (0-255)          |
 * |           |       |           |                                              |
 *
 * Multiple of these LED commands can come in one message; multiple of these LED
 * color assignments can be put in the same buffer.
 */

#pragma once

#include <cstdint>
#include <vector>

#include "LEDCommand.h"

#define N_BYTES_PER_COMMAND 11

#define BYTE_COLUMN         0
#define BYTE_ROW            4
#define BYTE_RED            8
#define BYTE_GREEN          9
#define BYTE_BLUE           10

enum BufferPackerStatus{
    FAIL_UNKNOWN,
    FAIL_BUFFER_FULL,
    FAIL_BUFFER_NOT_FULL,
    FAIL_UNALLOCATED_BUFFER,
    FAIL_INVALID_DEST,
    SUCCESS_PACK,
    SUCCESS_CPY
};

class BufferPacker {
public:
    BufferPacker(int nCommands);
    BufferPacker(std::vector<LEDCommand> commands);
    BufferPackerStatus addCommand(uint32_t column, uint32_t row, uint8_t r, uint8_t g, uint8_t b);
    BufferPackerStatus addCommand(LEDCommand command);

    uint64_t getCurrentNCommands();
    uint64_t getTotalNCommands();
    uint64_t getBufferSizeBytes();
    void *getBuffer();
    BufferPackerStatus copyBuffer(void *dest);

    bool isBufferFull();


private:
    uint64_t currentNCommands;
    uint64_t totalNCommands;
    void *buf;
};

