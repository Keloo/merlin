#include "Framework/Input.hpp"
#include "Framework/Window.hpp"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Framework {
    Input::Input(){};
    Input::~Input(){};

    void Input::handleKeyboard(Framework::Window *window) {
        if (glfwGetKey((*window).getGlWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose((*window).getGlWindow(), true);

        if (glfwGetKey((*window).getGlWindow(), GLFW_KEY_W) == GLFW_PRESS);
            // camera.ProcessKeyboard(FORWARD, deltaTime);
    }
}