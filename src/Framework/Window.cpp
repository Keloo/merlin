#pragma once

#include "Framework/Window.hpp"

namespace Framework {
    Window::Window(std::string t = "", int w = 800, int h = 600): title(t), width(w), height(h) {
        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    };
    Window::~Window(){};

    void Window::init() {
        
    }
}