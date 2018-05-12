#include "Component/Game.hpp"
#include "Component/Exception.hpp"
#include "Component/Logger.hpp"

#include "Framework/Window.hpp"
#include "Framework/Renderer.hpp"
#include "Framework/VertexBuffer.hpp"
#include "Framework/IndexBuffer.hpp"
#include "Framework/Shader.hpp"

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class DemoGame: public Component::Game {
    public:
        ~DemoGame(){};

        void run() {
            try {
                init();

                float vertices[] = {
                    0.5f,  0.5f, 0.0f,  // top right
                    0.5f, -0.5f, 0.0f,  // bottom right
                    -0.5f, -0.5f, 0.0f,  // bottom left
                    -0.5f,  0.5f, 0.0f   // top left 
                };
                unsigned int indices[] = {  // note that we start from 0!
                    0, 1, 3,   // first triangle
                    1, 2, 3    // second triangle
                };

                Framework::VertexBuffer *vertexBuffer = new Framework::VertexBuffer(vertices, sizeof(vertices));
                Framework::IndexBuffer *indexBuffer = new Framework::IndexBuffer(indices, 6);

                Framework::Shader *vertexShader = new Framework::Shader("./res/shader.main.vs");
                Framework::Shader *fragmentShader = new Framework::Shader("./res/shader.main.fs");

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