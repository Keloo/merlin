#pragma once

#include "lib/glad/glad.h"
#include "GLFW/glfw3.h"

#include "Framework/Game.hpp"
#include "Framework/Window.hpp"

namespace Framework {
    Game::Game(){};
    Game::~Game(){};
    
    void Game::run() {
        init();

        Window *window = new Window("Learning");

        // while (isRunning) {
            
        // }
    }

    void init() {
        glfwInit();

    }
}