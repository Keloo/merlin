#include "Framework/Renderer.hpp"
#include "Component/Logger.hpp"

#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace Framework {
    Renderer::Renderer(){
        init();
    };

    Renderer::~Renderer(){};

    void Renderer::init() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            Component::Logger::error("Failed to initialize GLAD");
        }
    }
}