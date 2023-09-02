#include <bits/stdc++.h>
#include "ui_console.h"

UIConsole::UIConsole(){
    std::cout << "Start UI Console" << std::endl;
    this->isStart = true;
}

void UIConsole::showFeatureLoginClient(int &feature){
    std::cout << "=======================================================" << std::endl;
    std::cout << "=====================START CLIENT======================" << std::endl;
    std::cout << "=======================================================" << std::endl;
    std::cout << "== List the feature:                                 ==" << std::endl;
    std::cout << "== 1.Login                                           ==" << std::endl;
    std::cout << "== 2.Register                                        ==" << std::endl;
    std::cout << "=======================================================" << std::endl;
    std::cout << "SELECT FEATURE: "; std::cin >> feature;

}

void UIConsole::showLogin(std::string &username, std::string &password){
    std::cin.ignore();
    std::cout << "=======================================================" << std::endl;
    std::cout << "=====================LOGIN FEATURE=====================" << std::endl;
    std::cout << "=======================================================" << std::endl;
    std::cout << "Enter Username: "; getline(std::cin,username);
    std::cout << "Enter Password: "; std::cin >> password;
}