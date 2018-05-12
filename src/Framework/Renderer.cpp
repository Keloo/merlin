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
        glProgramId = glCreateProgram();
    };

    Renderer::~Renderer(){};

    void Renderer::init() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            throw new Component::Exception("Failed to initialize GLAD");
        }
    }

    void Renderer::draw(Shader *vertexShader, Shader *fragmentShader) {
        GLCall(glAttachShader(glProgramId, (*vertexShader).getId()));
        GLCall(glAttachShader(glProgramId, (*fragmentShader).getId()));
        GLCall(glLinkProgram(glProgramId));
        GLCall(glUseProgram(glProgramId));
        // add some error checking

        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
    }
}