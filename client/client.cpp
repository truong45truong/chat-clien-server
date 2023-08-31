#include "client.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

Client::~Client(){
    close(this->clientSocket);
}

Client* Client::getInstance(){
    if(instance == nullptr){
        instance = new Client();
    }
    return instance;
}

int Client::findPortEmpty(int startPort,int endPort){
    for (int port = startPort; port <= endPort; ++port) {
        int tempSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (tempSocket == -1) {
            continue; // Failed to create a socket, try the next port
        }

        sockaddr_in serverAddress;
        memset(&serverAddress,0,sizeof(serverAddress));

        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(port);
        serverAddress.sin_addr.s_addr = INADDR_ANY;

        int bindResult = bind(tempSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
        close(tempSocket);

        if (bindResult == 0) {
            return port; // Found an available port
        }
    }
    return -1; // No available port found
}

void Client::startConnection(int port){
    char recv_buffer[1024];
    struct sockaddr_in server_addr;

    memset(recv_buffer,0,sizeof(recv_buffer));
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (connect(this->clientSocket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        std::cerr << "Error connecting to server" << std::endl;
        close(clientSocket);
        return;
    }
    
}
void Client::sendMessage(std::string msg){
    const char* message = "Hello from the server!";
    send(this->clientSocket, message, strlen(message), 0);
}