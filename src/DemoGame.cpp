#include "Component/Game.hpp"
#include "Component/Exception.hpp"
#include "Component/Logger.hpp"
#include "Component/Timer.hpp"

#include "Framework/Window.hpp"
#include "Framework/Renderer.hpp"
#include "Framework/VertexBuffer.hpp"
#include "Framework/IndexBuffer.hpp"
#include "Framework/Shader.hpp"
#include "Framework/VertexArray.hpp"

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

using namespace Framework;

class DemoGame: public Component::Game {
    public:
        DemoGame(): window(nullptr), renderer(nullptr), timer(nullptr) {};
        ~DemoGame() = default;

        void run() override {
            try {
                init();

                Shader *vertexShader = new Shader("./../res/shader/main.vs", Shader::ShaderType::Vertex);
                Shader *fragmentShader = new Shader("./../res/shader/main.fs", Shader::ShaderType::Fragment);

                (*renderer).attachShader(vertexShader);
                (*renderer).attachShader(fragmentShader);
                (*renderer).link();

                float vertices[] = {
                    0.5f,  0.5f, 0.0f,  // top right
                    0.5f, -0.5f, 0.0f,  // bottom right
                    -0.5f, -0.5f, 0.0f,  // bottom left
                    -0.5f,  0.5f, 0.0f   // top left 
                };
                unsigned int indices[] = {  // note that we start from 0!
                    0, 1, 3,  // first Triangle
                    1, 2, 3   // second Triangle
                };

                auto *vertexArray = new VertexArray();
                auto *vertexBuffer = new VertexBuffer(vertices, sizeof(vertices));

                auto *vertexBufferLayout = new VertexBufferLayout();
                (*vertexBufferLayout).pushFloat(3);

                (*vertexArray).addBuffer(*vertexBuffer, *vertexBufferLayout);

                auto *indexBuffer = new IndexBuffer(indices, 6);

                while (isRunning) {
                    if (glfwGetKey((*window).getGlWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                        isRunning = false;
                    }

                    std::cout << (*timer).elapsed().count();

                    (*renderer).clear();
                    (*renderer).draw(vertexArray, indexBuffer);

                    glfwSwapBuffers((*window).getGlWindow());
                    glfwPollEvents();
                }

            } catch (Component::Exception *e) {
                Component::Logger::error((*e).getMessage());
            }
        }

        void init() {
            window = new Window("Title", 800, 600);
            renderer = new Renderer();
            timer = new Component::Timer();
        }
    private:
        bool isRunning = true;
        Window *window;
        Renderer *renderer;
        Component::Timer *timer;
};