#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <string>

namespace Framework {
    class Window {
        private: 
            std::string title = "";
            int width = 800;
            int height = 600;
            GLFWwindow *glWindow;
        public: 
            Window(std::string, int, int h);
            ~Window();
            void init();
            void resizeCallback(GLFWwindow*, int, int);
            GLFWwindow* getGlWindow();
    };
}