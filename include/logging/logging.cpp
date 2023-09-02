#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include "logging.h"
#include "string_logger.cpp"

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

void Logger::info(const std::string message){
    struct StringLogger message_lo{0};
    std::lock_guard<std::mutex> lock(mtx);
    std::string context = message_lo.getTimeDetail() + "\n" + message ;
    messageQueue.push(context);
    std::cout<< message_lo.getTimeDetail()<< std::endl << message << std::endl;
    cv.notify_one();
}