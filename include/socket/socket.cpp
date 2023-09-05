//
// Created by truong on 04/09/2023.
//
#include <bits/stdc++.h>
#include "socket.h"
#include <sys/socket.h>

Socket::Socket(int sock) : sock_(sock) {}
Socket::~Socket() {
        close(sock_);
}

int Socket::Close() {
    int ret = 0;
    if (sock_ != INVALID_SOCKET) {
        ret = close(sock_);
        sock_ = INVALID_SOCKET;
    }
    return ret;
}

