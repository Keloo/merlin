#include "Component/Exception.hpp"

namespace Component {
    Exception::Exception() = default;
    Exception::Exception(Exception const &) = default;
    Exception::Exception(std::string message): message(message) {};
    Exception::Exception(std::string message, unsigned int code): message(message), code(code) {};
    Exception::~Exception() = default;

    void Exception::setCode(unsigned int c) {
        code = c;
    };

    void Exception::setMessage(std::string m) {
        message = m;
    };

    std::string Exception::getMessage() {
        return message;
    }

    unsigned int Exception::getCode() {
        return code;
    }
}