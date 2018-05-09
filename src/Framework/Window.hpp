#pragma once

#include "GLFW/glfw3.h"

#include <string>

namespace Framework {
    class Window {
        private: 
            std::string title = "";
            int width = 800, height = 600;
            GLFWwindow *window;
        public: 
            Window(std::string t = "", int w = 800, int h = 600);
            ~Window();
            void init();
    };
}