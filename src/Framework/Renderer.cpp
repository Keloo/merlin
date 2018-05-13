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
    Renderer::Renderer(){
        init();
        glProgramId = glCreateProgram();        
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

    void Renderer::draw(VertexArray *vertexArray, IndexBuffer *indexBuffer) {
        GLCall(glUseProgram(glProgramId));
        (*vertexArray).bind();
        (*indexBuffer).bind();

        GLCall(glDrawElements(GL_TRIANGLES, (*indexBuffer).getCount(), GL_UNSIGNED_INT, 0));
    }
}