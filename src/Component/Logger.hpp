#pragma once

#include <string>

namespace Component {
    class Logger {
        public:
            Logger();
            ~Logger();
            void static error(std::string message);
            void static warning(std::string message);
            void static info(std::string message);
        private:
            void static log(std::string message, std::string type);
            std::string static logFile;
    };
}