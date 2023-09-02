#include <bits/stdc++.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <vector>
#include <thread>
struct ClientAccept {
    int socket ;
    sockaddr_in addressSocket;
    std::thread* handleClientThread;
};

class Server {
    private:
        static Server* instance;
        int serverSocket;
        int listening;
        std::vector<ClientAccept*> clients;
    private:    
        Server(){
            this->clients = {};
            this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
            if (this->serverSocket < 0) 
                std::cout << "Error" << std::endl; 
        }
        void handleClient(int clientSocket) {
            const char* message = "Hello from the server!";
            send(clientSocket, message, strlen(message), 0);
        }
    public:
        int findPortEmpty(int, int);
        static Server* getInstance();
        void startListenningClient(int);
        bool checkConnect(ssize_t,int&);

        ~Server();
    
         
};
