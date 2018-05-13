#pragma once 

#include "Framework/Shader.hpp"
#include "Framework/IndexBuffer.hpp"
#include "Framework/VertexArray.hpp"

namespace Framework {
    class Renderer {
        public:
            enum class DrawMode { Triangle = 0, Line = 1 };
            Renderer();
            ~Renderer();
            void init();
            void draw(VertexArray*, IndexBuffer*);
            void link() const;
            void attachShader(Shader*) const;
            unsigned int getGlProgramId();
            void clear() const;
            unsigned int getGlDrawMode();
            DrawMode getDrawMode();
            void setDrawMode(DrawMode d);
        private:
            unsigned int glProgramId;
            DrawMode drawMode;
    };
}