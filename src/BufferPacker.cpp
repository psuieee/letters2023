#include <cstring>
#include "BufferPacker.h"

BufferPacker::BufferPacker(int nCommands) {
    this->totalNCommands = nCommands;
    this->currentNCommands = 0;

    this->buf = new unsigned char[nCommands * N_BYTES_PER_COMMAND];
}

BufferPackerStatus BufferPacker::addCommand(
        uint32_t column, uint32_t row, uint8_t r, uint8_t g, uint8_t b) {

    // make sure a command can/should be added
    if (this->currentNCommands >= this->totalNCommands) {
        return FAIL_BUFFER_FULL;
    }

    // confirm that the buffer has been allocated
    if (this->buf == nullptr) {
        return FAIL_UNALLOCATED_BUFFER;
    }

    // get a pointer to the start of the command
    unsigned char *cmdStart = ((unsigned char *) buf) + (this->currentNCommands * N_BYTES_PER_COMMAND);

    memcpy(cmdStart + BYTE_COLUMN, &column, sizeof(uint32_t));
    memcpy(cmdStart + BYTE_ROW, &row, sizeof(uint32_t));
    memcpy(cmdStart + BYTE_RED, &r, sizeof(uint8_t));
    memcpy(cmdStart + BYTE_GREEN, &g, sizeof(uint8_t));
    memcpy(cmdStart + BYTE_BLUE, &b, sizeof(uint8_t));

    // increment the number of commands added
    this->currentNCommands++;

    return SUCCESS;
}

uint64_t BufferPacker::getCurrentNCommands() {return this->currentNCommands;}

uint64_t BufferPacker::getTotalNCommands() {return this->totalNCommands;}

void *BufferPacker::getBuffer() {
    return this->buf;
}

bool BufferPacker::isBufferFull() {return this->currentNCommands >= this->totalNCommands;}

BufferPackerStatus BufferPacker::copyBuffer(void *dest) {

    // confirm that buffer is full
    if (this->currentNCommands < this->totalNCommands) {
        return FAIL_BUFFER_NOT_FULL;
    }

    // confirm that the buffer has been allocated
    if (this->buf == nullptr) {
        return FAIL_UNALLOCATED_BUFFER;
    }

    // confirm that the destination is not nullptr
    if (dest == nullptr) {
        return FAIL_INVALID_DEST;
    }

    // copy over buffer
    memcpy(dest, this->buf, this->totalNCommands * N_BYTES_PER_COMMAND);

    return SUCCESS;
}