#include "CommandSender.h"

CommandSender::CommandSender(struct sockaddr_in newAddr) {
    this->addr = newAddr;
}

CommandSender::CommandSender(const char *ip, int port) {
    this->addr.sin_family = AF_INET;
    this->addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &this->addr.sin_addr);
}

BufferSendStatus CommandSender::sendBuffer(unsigned char *buf, uint64_t bufSizeBytes) {

    // variables
    int sock, client_fd, nSent;

    // make socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // check socket
    if (sock < 0) {
        return FAIL_SOCK_CREATE;
    }

    // make connection
    client_fd = connect(sock, (struct sockaddr *) &this->addr, sizeof(this->addr));

    // check connection
    if (client_fd < 0) {
        return FAIL_CONNECT;
    }

    // send command
    nSent = send(sock, buf, bufSizeBytes, 0);

    // check send
    if (nSent < 0) {
        return FAIL_SEND;
    }

    return SUCCESS_SEND;
}