#include <bits/stdc++.h>
#include "server.h"

Server* Server::instance = nullptr;

int main(){
    Server* server = Server::getInstance();
    int port = server->findPortEmpty(3000,5000);
    server->startListenningClient(port);

}