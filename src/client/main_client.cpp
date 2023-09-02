#include <bits/stdc++.h>
#include "client.h"
#include "ui_console.h"

Client* Client::instance = nullptr;

int main(){
    Client* client = Client::getInstance();
    int port = client->findPortEmpty(3000,5000);
    client->startConnection(3000);
    // client->startReceive();
    UIConsole ui;
    int feature;
    std::string username,passwod;
    do{
        system("clear");
        ui.showFeatureLoginClient(feature);
        switch (feature)
        {
        case 1:
            ui.showLogin(username,passwod);
            client->sendMessage(username+","+passwod);
            break;
        
        default:
            break;
        }
    }while (feature != 0);
    
}