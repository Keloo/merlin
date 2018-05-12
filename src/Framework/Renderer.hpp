#pragma once 

#include "Framework/Shader.hpp"

namespace Framework {
    class Renderer {
        public:
            Renderer();
            ~Renderer();
            void init();
            void draw();
            void createProgram();
            void link() const;
            void attachShader(Shader*) const;
            unsigned int getGlProgramId();
        private:
            unsigned int glProgramId;
    };
}