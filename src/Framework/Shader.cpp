#include "Event/EventDispatcher.hpp"
#include "Event/Game/TerminateEvent.hpp"

#include "Framework/Shader.hpp"
#include "Framework/GLDebug.hpp"

#include "Component/Logger.hpp"

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
            Logger::error("Can not open Shader file: "+path);
            EventDispatcher::getInstance()->dispatch(Game::TerminateEvent::NAME, new Game::TerminateEvent());
            return;
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
                throw std::exception();
        }
    }

    void Shader::compile() {
        glShaderId = GLCall(glCreateShader(getGlType()));
    }

}