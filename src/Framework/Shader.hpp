#pragma once

#include <string>

namespace Framework {
    class Shader {
        public:
            enum class ShaderType { None = -1, Vertex = 0, Fragment = 1 };
            Shader(std::string file);
            void loadFromFile(std::string path);
            void setType(ShaderType type);
            ShaderType getType();
        private:
            std::string source;
            ShaderType type = ShaderType::None;
    };
}