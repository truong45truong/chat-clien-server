#include <bits/stdc++.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "server.h"
#include "../logging/logging.h"

Logger* Logger::instance = nullptr;

Logger* logger = Logger::getInstance();

Server::~Server(){
    close(this->serverSocket);
}

Server* Server::getInstance(){
    if(instance == nullptr){
        instance = new Server();
    }
    return instance;
}

int Server::findPortEmpty(int startPort,int endPort){
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

void Server::startListenningClient(int port){
    char recv_buffer[1024];
    struct sockaddr_in server_addr;

    memset(recv_buffer,0,sizeof(recv_buffer));
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        std::cerr << "Error binding socket" << std::endl;
        // Handle error
    }
    listen(this->serverSocket,10);
    std::cout << "SERVER START RUNNING IN PORT: " << port << std::endl; 
    while (true)
    {
        sockaddr_in clientAddress;
        socklen_t clientSize = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientSize);
        if (clientSocket == -1) {
            std::cerr << "Error accepting connection" << std::endl;
            continue; // Continue to the next iteration
        }
        
        this->handleClient(clientSocket);
        std::string log = "Client accept" + std::to_string(clientSocket);
        logger->log(log );
        std::cout << "Client Accept" << std::endl;

        // Close the client socket
        close(clientSocket);
    }
    
}
