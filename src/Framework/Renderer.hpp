#pragma once 

#include "Framework/Shader.hpp"
#include "Framework/IndexBuffer.hpp"
#include "Framework/VertexArray.hpp"

namespace Framework {
    class Renderer {
        public:
            Renderer();
            ~Renderer();
            void init();
            void draw(VertexArray*, IndexBuffer*);
            void link() const;
            void attachShader(Shader*) const;
            unsigned int getGlProgramId();
        private:
            unsigned int glProgramId;
    };
}