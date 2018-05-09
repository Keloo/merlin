#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Framework/Game.hpp"
#include "Framework/Window.hpp"

namespace Framework {
    Game::Game(){};
    Game::~Game(){};
    
    void Game::run() {
        init();
        Window *window = new Window("Title", 800, 600);
        initGlad();

        while (isRunning) {
            if(glfwGetKey((*window).getGlWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                isRunning = false;
            }

            glfwSwapBuffers((*window).getGlWindow());
            glfwPollEvents();
        }
    }

    void Game::init() {
        glfwInit();
    }

    void Game::initGlad() {
        // @todo add logs
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            // @todo fire terminate event
        }
    }
}