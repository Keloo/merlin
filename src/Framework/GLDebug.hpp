#pragma once

#include "Component/Logger.hpp"

#include "glad/glad.h"
#include "GL/glew.h"

#define GLCall(x) glGetError(); x; if (!GLLogCall(#x, __FILE__, __LINE__)) __debugbreak();

bool GLLogCall(const char* function, const char* file, int32_t line)
{
    unsigned int error = glGetError();
    if (error != GL_NO_ERROR)
    {
        Component::Logger::error(
            "[OpenGL Error] (" + std::to_string(error) + "): " + 
            std::string(function) + " " + std::string(file) + ":" + std::to_string(line)
        );
        return false;
    }
    return true;
}