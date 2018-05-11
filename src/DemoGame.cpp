#include "Component/Game.hpp"
#include "Component/Exception.hpp"
#include "Component/Logger.hpp"

#include "Framework/Window.hpp"
#include "Framework/Renderer.hpp"

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class DemoGame: public Component::Game {
    public:
        ~DemoGame(){};

        void run() {
            try {
                init();

                while (isRunning) {
                    if(glfwGetKey((*window).getGlWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                        isRunning = false;
                    }
                    glfwSwapBuffers((*window).getGlWindow());
                    glfwPollEvents();
                }
            } catch (Component::Exception *e) {
                Component::Logger::error((*e).getMessage());
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