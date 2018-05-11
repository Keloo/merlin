#include "Framework/Window.hpp"

#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Framework {
    Window::Window(std::string t = "", int w = 800, int h = 600): title(t), width(w), height(h) {
        init();
    };
    Window::~Window(){};

    void Window::init() {
        glfwInit();
        glWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(glWindow);        
    }

    GLFWwindow* Window::getGlWindow() {
        return glWindow;
    }
}