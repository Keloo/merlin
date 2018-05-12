#pragma once

#include <string>

#include "glad/glad.h"

namespace Framework {
    class Shader {
        public:
            enum class ShaderType { None = -1, Vertex = 0, Fragment = 1 };
            Shader(std::string file);
            void loadFromFile(std::string path);
            void setType(ShaderType type);
            ShaderType getType();
            void compile();
            unsigned int getGlType();
        private:
            std::string getTypeToString();
            std::string source;
            ShaderType type = ShaderType::None;
            unsigned int glShaderId;
    };
}