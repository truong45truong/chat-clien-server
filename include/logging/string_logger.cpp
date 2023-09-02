#include <bits/stdc++.h>
#include <ctime>

namespace config_string_logger {
    //Level

    static const char* level[4]                        = { "INFO","DEBUG","WARNING","ERROR" };

    // Date/time
    static const char* days[7]                         =      { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    static const char* daysAbbrev[7]                   =      { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    static const char* months[12]                      =      { "January", "February", "March", "April", "May", "June", "July", "August",
                                                                "September", "October", "November", "December"
                                                            };
    static const char* monthsAbbrev[12]                =      { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    static const char* defaultDateTimeFormat           =      "%Y-%M-%d %H:%m:%s,%g";
    static const char* defaultDateTimeFormatInFilename =      "%Y-%M-%d_%H-%m";
    static const char* am                              =      "AM";
    static const char* pm                              =      "PM";
}




struct StringLogger {
    int level;
    public:
        std::string getTimeDetail(){
            std::time_t currentTime = std::time(nullptr);
            std::tm* timeInfo = std::localtime(&currentTime);

            int day = timeInfo->tm_mday;
            int month = timeInfo->tm_mon;

            std::string session;

            if(timeInfo->tm_hour > 12){
                session =  config_string_logger::am;
            }else {
                session =  config_string_logger::pm;
            }

            char buffer[80];
            std::strftime(
                buffer, 
                sizeof(buffer), 
                config_string_logger::defaultDateTimeFormat, 
                timeInfo
            );

            std::string message = "";

            message += "[ ";
            message += config_string_logger::level[this->level];
            message += " ";
            message += config_string_logger::days[day];
            message += " ";
            message += config_string_logger::months[month];
            message += " ";
            message += buffer;
            message += " ";
            message += session;
            message += " ]";
            return message;
        }
};
