#pragma once

#include "Component/Logger.hpp"

#include "glad/glad.h"

#define GLCall(x) glGetError(); x; if (!GLLogCall(#x, __FILE__, __LINE__)) __builtin_trap();

inline std::string GLErrorCodeToString(int errorCode) {
    std::string error;
    switch (errorCode) {
        case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
        case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
        case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
        case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW"; break;
        case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW"; break;
        case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
        case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
    }

    return error;
}

bool GLLogCall(const char* function, const char* file, int32_t line) {
    unsigned int errorCode = glGetError();
    if (errorCode != GL_NO_ERROR) {
        Component::Logger::error(
            "[OpenGL Error] (" + GLErrorCodeToString(errorCode) + "): " + 
            std::string(function) + " " + std::string(file) + ":" + std::to_string(line)
        );

        return false;
    }

    return true;
}