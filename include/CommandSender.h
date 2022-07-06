#pragma once

#include <cstdint>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

enum BufferSendStatus {
    FAIL_GENERIC,
    FAIL_SOCK_CREATE,
    FAIL_CONNECT, 
    FAIL_SEND,
    SUCCESS_SEND
};

class CommandSender {
public:
    CommandSender(const char *ip, int port);
    CommandSender(struct sockaddr_in newAddr);
    BufferSendStatus sendBuffer(unsigned char *buf, uint64_t bufSizeBytes);

private:
    struct sockaddr_in addr;    

};
