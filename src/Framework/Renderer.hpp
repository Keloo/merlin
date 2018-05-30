#pragma once

#include <Component/Camera/FPSCamera.hpp>
#include <Component/Cube.hpp>
#include "Framework/Shader.hpp"
#include "Framework/IndexBuffer.hpp"
#include "Framework/VertexArray.hpp"
#include "Window.hpp"

namespace Framework {
    class Renderer {
        public:
            enum class DrawMode { Triangle = 0, Line = 1 };
            Renderer();
            ~Renderer();
            void init();
            void draw(Framework::Window *window, Component::Camera::FPSCamera*, VertexArray*, IndexBuffer*, Component::Cube*);
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