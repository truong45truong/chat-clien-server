#include <bits/stdc++.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "server.h"
#include "../../include/logging/logging.h"
#include "../base/constants/message_code.cpp"
#include <thread>

using namespace logger_constant;

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

bool Server::checkConnect(ssize_t bytesRead , int &clientSocket){
    if (bytesRead == -1) {
        if (errno == ECONNRESET || errno == EPIPE) {
            logger->info(logger_constant::DISCONNECT_CLIENT);
            close(clientSocket);
            return false;
        } else {
            logger->info(logger_constant::REV_DATA);
            return false;
        }
    }
    return true;
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
        logger->info(logger_constant::ERROR_BLIND);
        // Handle error
    }
    listen(this->serverSocket,10);
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(server_addr.sin_addr), ip, INET_ADDRSTRLEN);

    std::cout << "SERVER START RUNNING: " << ip <<":" << port << std::endl; 
    while (true)
    {
        sockaddr_in clientAddress;
        socklen_t clientSize = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientSize);
        if (clientSocket == -1) {
            logger->info(logger_constant::ERROR_ACCEPT);
            continue; // Continue to the next iteration
        }
        try {
            std::thread handleClientThread = std::thread([&]{
                char buffer[1024];
                while (true)
                {
                    memset(buffer, 0, sizeof(buffer));
                    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
                    bool connectionSocket = this->checkConnect(bytesRead,clientSocket);
                    if(connectionSocket == false) break;
                    logger->info("Client send: " + (std::string)buffer);
                }
                
            }); 
            struct ClientAccept client = {
                clientSocket,
                clientAddress,
                &handleClientThread
            };
            handleClientThread.detach(); 
            this->clients.push_back(&client);
        }catch (const std::exception& e) {
            // Xử lý ngoại lệ ở đây
            std::cerr << "Caught an exception: " << e.what() << std::endl;
        }
        char clientIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(clientAddress.sin_addr), clientIP, INET_ADDRSTRLEN);

        this->handleClient(clientSocket);
        std::string log = "Client accept: " + (std::string)clientIP;

        logger->info(log );
        // Close the client socket
        // close(clientSocket);
    }
    
}
