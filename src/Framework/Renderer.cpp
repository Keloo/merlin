#include "Component/Exception.hpp"

#include "Framework/Renderer.hpp"
#include "Framework/GLDebug.hpp"
#include "Framework/Shader.hpp"

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Framework {
    Renderer::Renderer(){
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

    void Renderer::createProgram() {
        glProgramId = glCreateProgram();        
    }

    void Renderer::attachShader(Shader* shader) const {
        GLCall(glAttachShader(glProgramId, (*shader).getId()));
    }

    void Renderer::link() const {
        GLCall(glLinkProgram(glProgramId));
    }

    void Renderer::draw() {
        GLCall(glUseProgram(glProgramId));
        // add some error checking

        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
    }
}