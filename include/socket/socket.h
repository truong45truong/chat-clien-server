//
// Created by truong on 04/09/2023.
//

#ifndef CHAT_CLIENT_SERVER_SOCKET_H
#define CHAT_CLIENT_SERVER_SOCKET_H
#include <sys/socket.h>
#include "constants.h"
#include <vector>
#include <functional>
#include <memory>
#include <string>
#include <utility>

class Socket {
    public:
        explicit Socket(int sock_);
        virtual ~Socket();
        virtual bool Send(const void* data, size_t length) = 0;
        virtual ssize_t Receive(void* data, size_t length, int timeout_ms) = 0;
        virtual std::unique_ptr<Socket> Accept() { return nullptr; }
        virtual int GetLocalPort()=0;
        virtual int Close();

    protected:
        int sock_ = INVALID_SOCKET;
};

#endif //CHAT_CLIENT_SERVER_SOCKET_H
