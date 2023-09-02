#ifndef LOGGING_H
#define LOGGING_H

#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Logger {
    private:
        static Logger* instance;
        ofstream file;
        std::queue<std::string> messageQueue;
        std::mutex mtx;
        std::condition_variable cv;
        std::thread loggingThread;
        bool stopLogging = false;
        Logger(){
            this->file.open("../logging/logs/logs.txt",ios_base::app);
            loggingThread = std::thread([&]{
                while(true){
                    std::unique_lock<std::mutex> lock(mtx);

                    cv.wait(lock,[&]{
                        return !messageQueue.empty() || stopLogging;
                    });

                    while(!messageQueue.empty()){
                        file << messageQueue.front() << std::endl;
                        messageQueue.pop();
                    }

                    if (stopLogging) {
                        break;
                    }
                }
            });
        };
    public:
        static Logger* getInstance();
        void log(const std::string);
        void info(const std::string);
        ~Logger();
};

#endif