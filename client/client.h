#include <bits/stdc++.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class Client {
    private:
        static Client* instance;
        int clientSocket;
    private:
        Client(){
                this->clientSocket = socket(AF_INET, SOCK_STREAM, 0);
                if (this->clientSocket < 0) 
                    std::cout << "Error" << std::endl; 
            }
    public:
        int findPortEmpty(int, int);
        static Client* getInstance();
        void startConnection(int);
        void sendMessage(std::string);
        ~Client();
    
         
};