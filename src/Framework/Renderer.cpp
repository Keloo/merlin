#include "Framework/Renderer.hpp"
#include "Component/Logger.hpp"
#include "Framework/GLDebug.hpp"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

namespace Framework {
    Renderer::Renderer(){
        init();
    };

    Renderer::~Renderer(){};

    void Renderer::init() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            Component::Logger::error("Failed to initialize GLAD");
        }

                const void *data;
        GLCall(glTexImage2D(GL_TEXTURE_3D, 0, GL_RGB, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, data));
// std::cout << glGetError() << std::endl; // returns 1280 (invalid enum)

    }
}