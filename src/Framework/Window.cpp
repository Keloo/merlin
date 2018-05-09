#include "Framework/Window.hpp"

namespace Framework {
    Window::Window(std::string t = "", int w = 800, int h = 600): title(t), width(w), height(h) {
        init();
    };
    Window::~Window(){};

    void Window::init() {
        glWindow = glfwCreateWindow(this->width, this->height, this->title.c_str(), nullptr, nullptr);
        // @todo handle error
        glfwMakeContextCurrent(glWindow);
        glViewport(0, 0, this->width, this->height);
        // glfwSetFramebufferSizeCallback(window, resizeCallback);
    }

    GLFWwindow* Window::getGlWindow() {
        return glWindow;
    }

    // void Window::resizeCallback(GLFWwindow* window, int w, int h) {
    //     width = w;
    //     height = h;
    //     glViewport(0, 0, width, height);
    // }
}