#include "Component/Logger.hpp"

#include "Event/EventDispatcher.hpp"
#include "Event/Game/TerminateEvent.hpp"

#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>

namespace Component {
    using namespace Event;

    Logger::Logger(){};
    Logger::~Logger(){};

    std::string Logger::logFile = "./var/logs/log.txt";

    void Logger::log(std::string message, std::string type) {
        std::ofstream fo(logFile, std::ios_base::app);
        if (!fo.is_open()) {
            std::cout << "Error, can not open log file" << std::endl;
            EventDispatcher::getInstance()->dispatch(Game::TerminateEvent::NAME, new Game::TerminateEvent());
            return;
        }
        auto nowClock = std::chrono::system_clock::now();
        std::time_t nowTime = std::chrono::system_clock::to_time_t(nowClock);
        fo << '\n' << std::ctime(&nowTime) << "[" << type << "]: " << message << std:: endl;

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