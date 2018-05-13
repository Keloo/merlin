#include "Component/Exception.hpp"

#include "Framework/Renderer.hpp"
#include "Framework/GLDebug.hpp"
#include "Framework/Shader.hpp"
#include "Framework/VertexArray.hpp"
#include "Framework/IndexBuffer.hpp"

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Framework {
    Renderer::Renderer(): drawMode(Renderer::DrawMode::Triangle), glProgramId(glCreateProgram()) {
        init();
    };

    Renderer::~Renderer(){};

    void Renderer::init() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            throw new Component::Exception("Failed to initialize GLAD");
        }
    }

    unsigned int Renderer::getGlProgramId() {
        return glProgramId;
    }

    void Renderer::attachShader(Shader* shader) const {
        GLCall(glAttachShader(glProgramId, (*shader).getId()));
    }

    void Renderer::link() const {
        GLCall(glLinkProgram(glProgramId));
    }

    void Renderer::clear() const {
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }

    Renderer::DrawMode Renderer::getDrawMode() {
        return drawMode;
    }

    void Renderer::setDrawMode(DrawMode d) {
        drawMode = d;
    }

    unsigned int Renderer::getGlDrawMode() {
        switch (drawMode) {
            case Renderer::DrawMode::Triangle:  return GL_TRIANGLES;
            case Renderer::DrawMode::Line:      return GL_LINES;
        }
        throw new Component::Exception("Invalid GL draw mode");
        return -1;
    }

    void Renderer::draw(VertexArray *vertexArray, IndexBuffer *indexBuffer) {
        GLCall(glUseProgram(glProgramId));

        (*vertexArray).bind();
        (*indexBuffer).bind();

        GLCall(glDrawElements(getGlDrawMode(), (*indexBuffer).getCount(), GL_UNSIGNED_INT, 0));
    }
}