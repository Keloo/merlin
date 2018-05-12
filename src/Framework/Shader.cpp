#include "Event/EventDispatcher.hpp"
#include "Event/Game/TerminateEvent.hpp"

#include "Framework/Shader.hpp"
#include "Framework/GLDebug.hpp"

#include "Component/Exception.hpp"

#include <fstream>

namespace Framework {
    using namespace Event;
    using namespace Component;

    Shader::Shader(std::string path) {
        loadFromFile(path);
    }

    void Shader::loadFromFile(std::string path) {
        std::ifstream fi(path);

        if (!fi.is_open()) {
            throw new Exception("Can not open shader file" + path);
        }

        std::string line;
        while (std::getline(fi, line)) {
            if (line.find("#shader") != std::string::npos) {
                if (line.find("vertex") != std::string::npos) 
                    setType(ShaderType::Vertex);
                else if (line.find("fragment") != std::string::npos) 
                    setType(ShaderType::Fragment);
            }
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

    void Shader::compile() {
        glShaderId = GLCall(glCreateShader(getGlType()));
    }
}