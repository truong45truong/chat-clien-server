#include <bits/stdc++.h>
#include "client.h"

Client* Client::instance = nullptr;

int main(){
    Client* client = Client::getInstance();
    int port = client->findPortEmpty(3000,5000);
    client->startConnection(3000);

}