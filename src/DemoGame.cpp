#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Component/Game.hpp"
#include "Framework/Window.hpp"
#include "Framework/Renderer.hpp"

class DemoGame: public Component::Game {
    public:
        ~DemoGame(){};
        void run() {
            init();

            while (isRunning) {
                if(glfwGetKey((*window).getGlWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                    isRunning = false;
                }
                glfwSwapBuffers((*window).getGlWindow());
                glfwPollEvents();
            }
        }

        void init() {
            window = new Framework::Window("Title", 800, 600);
            renderer = new Framework::Renderer();
        }
    private:
        bool isRunning = true;
        Framework::Window *window;
        Framework::Renderer *renderer;
};