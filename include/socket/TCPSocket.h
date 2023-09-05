//
// Created by truong on 04/09/2023.
//

#ifndef CHAT_CLIENT_SERVER_TCPSOCKET_H
#define CHAT_CLIENT_SERVER_TCPSOCKET_H

#include "../custom_code/custom_macros."
#include "socket.h"


class TCPSocket : public Socket {h
public:
    explicit TCPSocket(int sock) : Socket(sock) {}
    bool Send(const void* data, size_t length) override;
    ssize_t Receive(void* data, size_t length, int timeout_ms) override;
    std::unique_ptr<Socket> Accept() override;
private:
    DISALLOW_COPY_AND_ASSIGN(TcpSocket);
};



#endif //CHAT_CLIENT_SERVER_TCPSOCKET_H
