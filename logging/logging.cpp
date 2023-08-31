#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include "logging.h"

using namespace std;


Logger* Logger::getInstance(){
    if(instance == nullptr){
        instance = new Logger();
    }
    return instance;
}

Logger::~Logger(){
    {   
        std::lock_guard<std::mutex> lock(mtx);
        this->stopLogging = true;
    }
    this->cv.notify_one();
    this->loggingThread.join();
    file.close();
}

void Logger::log(const std::string message){
    std::lock_guard<std::mutex> lock(mtx);
    messageQueue.push(message);
    std::cout<< "LOG START: "<< message << std::endl;
    cv.notify_one();
}