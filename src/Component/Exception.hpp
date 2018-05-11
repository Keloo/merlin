#pragma once

#include <string>

namespace Component {
    class Exception {
        public:
            Exception();
            Exception(std::string);
            Exception(std::string, unsigned int);
            ~Exception();
            void setMessage(std::string message);
            std::string getMessage();
            void setCode(unsigned int code);
            unsigned int getCode();
        private:
            std::string message;
            unsigned int code;
    };
}