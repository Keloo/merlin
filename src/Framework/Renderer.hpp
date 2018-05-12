#pragma once 

#include "Framework/Shader.hpp"

namespace Framework {
    class Renderer {
        public:
            Renderer();
            ~Renderer();
            void init();
            void draw(Shader*, Shader*);
        private:
            unsigned int glProgramId;
    };
}