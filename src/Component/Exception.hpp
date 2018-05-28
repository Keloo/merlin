#pragma once

#include <string>
#include <exception>

namespace Component {
    class Exception: public std::exception {
        public:
            Exception() noexcept(false);
            Exception(Exception const&) noexcept(false);
            explicit Exception(std::string) noexcept(false);
            Exception(std::string, unsigned int) noexcept(false);
            ~Exception() override ;

            void setMessage(std::string message);
            std::string getMessage();

            void setCode(unsigned int code);
            unsigned int getCode();
        private:
            std::string message;
            unsigned int code;
    };
}