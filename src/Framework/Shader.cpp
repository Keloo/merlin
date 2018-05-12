#include "Framework/Shader.hpp"
#include "Framework/GLDebug.hpp"

#include "Component/Exception.hpp"

#include <fstream>
#include <iostream>

namespace Framework {
    using namespace Component;

    Shader::Shader(std::string path) {
        loadFromFile(path);
        compile();
    }

    Shader::Shader(std::string path, Shader::ShaderType t) {
        type = t;
        loadFromFile(path);
        compile();
    }

    Shader::~Shader() {
        GLCall(glDeleteShader(glShaderId));
    }

    unsigned int Shader::getId() {
        return glShaderId;
    }

    void Shader::loadFromFile(std::string path) {
        std::ifstream fi(path);

        if (!fi.is_open()) {
            throw new Exception("Can not open shader file" + path);
        }

        std::string line;
        while (std::getline(fi, line)) {
            source +=  line + '\n';
        }
    }

    void Shader::setType(Shader::ShaderType t) {
        type = t;
    }

    Shader::ShaderType Shader::getType() {
        return type;
    }

    unsigned int Shader::getGlType() {
        switch (type) {
            case ShaderType::Fragment:
                return GL_FRAGMENT_SHADER;
            case ShaderType::Vertex:
                return GL_VERTEX_SHADER;
            default:
                throw new Exception("Invalid shader type");
        }
    }

    std::string Shader::getTypeToString() {
        switch (type) {
            case ShaderType::Vertex: return "VERTEX";
            case ShaderType::Fragment: return "FRAGMENT";
        }

        return "NONE";
    }

    void Shader::compile() {
        glShaderId = glCreateShader(getGlType());
        const char *shaderSource = source.c_str();
       
        GLCall(glShaderSource(glShaderId, 1, &shaderSource, NULL));
        GLCall(glCompileShader(glShaderId));

        int success;
        char infoLog[512];
        glGetShaderiv(glShaderId, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(glShaderId, 512, NULL, infoLog);
            std::cout << infoLog << std::endl;
            throw new Exception(getTypeToString() + ":SHADER:COMPILATION:FAILED" + std::string(infoLog));
        }
    }
}