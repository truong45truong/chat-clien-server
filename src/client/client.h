#include <bits/stdc++.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>

class Client {
    private:
        static Client* instance;
        int clientSocket;
        std::thread threadReceive;
        bool stop = false;
    private:
        Client(){
                this->clientSocket = socket(AF_INET, SOCK_STREAM, 0);
                if (this->clientSocket < 0) 
                    std::cout << "Error" << std::endl; 
            }
    public:
        int findPortEmpty(int, int);
        static Client* getInstance();
        void startReceive();
        void startConnection(int);
        void sendMessage(std::string);
        ~Client();
    
         
};