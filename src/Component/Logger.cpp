#include "Component/Logger.hpp"

#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>

namespace Component {
    Logger::Logger(){};
    Logger::~Logger(){};

    std::string Logger::logFile = "var/logs/log.txt";

    void Logger::log(std::string message, std::string type) {
        std::ofstream fo(logFile);
        if (!fo.is_open()) {
            std::cout << "Error, can not open log file" << std::endl;
            return; // @TODO Maybe throw terminate event
        }
        auto nowClock = std::chrono::system_clock::now();
        std::time_t nowTime = std::chrono::system_clock::to_time_t(nowClock);
        fo << "[" << std::ctime(&nowTime) << "][" << type << "]: " << message << std:: endl;

        fo.close();
    }

    void Logger::error(std::string message) {
        log(message, "Error");
    }

    void Logger::warning(std::string message) {
        log(message, "Warning");
    }

    void Logger::info(std::string message) {
        log(message, "Info");
    }
}