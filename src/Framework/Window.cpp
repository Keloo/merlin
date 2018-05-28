#include "Framework/Window.hpp"
#include "Framework/GLDebug.hpp"
#include "Event/EventDispatcher.hpp"
#include "Event/Mouse/CursorPosition.hpp"

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
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
        glWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(glWindow);

        // set callbacks (resize, cursor)
        glfwSetFramebufferSizeCallback(glWindow, resizeCallback);
        glfwSetCursorPosCallback(glWindow, cursorPositionCallback);
    }

    void Window::resizeCallback(GLFWwindow*, int width, int height) {
        GLCall(glViewport(0, 0, width, height));
    }

    void Window::cursorPositionCallback(GLFWwindow* window, double offsetX, double offsetY) {
        Event::Event *event = new Event::Mouse::CursorPosition(offsetX, offsetY);
        Event::EventDispatcher::getInstance().dispatch(Event::Mouse::CursorPosition::NAME, event);
    }

    GLFWwindow* Window::getGlWindow() {
        return glWindow;
    }
}