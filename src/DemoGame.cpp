#include "Component/Game.hpp"
#include "Component/Exception.hpp"
#include "Component/Logger.hpp"
#include "Component/Timer.hpp"
#include "Component/Camera/Camera.hpp"
#include "Component/Camera/FPSCamera.hpp"

#include "Framework/Window.hpp"
#include "Framework/Renderer.hpp"
#include "Framework/VertexBuffer.hpp"
#include "Framework/IndexBuffer.hpp"
#include "Framework/Shader.hpp"
#include "Framework/VertexArray.hpp"
#include "Framework/GLDebug.hpp"

#include <iostream>
#include <Framework/InputHandler.hpp>
#include <Event/EventDispatcher.hpp>
#include <Framework/Texture.hpp>

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
                registerEventListeners();

                Shader *vertexShader = new Shader("./res/shader/main.vert", Shader::ShaderType::Vertex);
                Shader *fragmentShader = new Shader("./res/shader/main.frag", Shader::ShaderType::Fragment);

                (*renderer).attachShader(vertexShader);
                (*renderer).attachShader(fragmentShader);
                (*renderer).link();

                float vertices[] = {
                        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
                        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
                        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
                        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

                        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
                        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
                        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
                        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

                        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

                        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

                        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
                        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

                        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
                        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
                        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
                };
                // world space positions of our cubes
                glm::vec3 cubePositions[] = {
                        glm::vec3( 0.0f,  0.0f,  0.0f),
                        glm::vec3( 2.0f,  5.0f, -15.0f),
                        glm::vec3(-1.5f, -2.2f, -2.5f),
                        glm::vec3(-3.8f, -2.0f, -12.3f),
                        glm::vec3( 2.4f, -0.4f, -3.5f),
                        glm::vec3(-1.7f,  3.0f, -7.5f),
                        glm::vec3( 1.3f, -2.0f, -2.5f),
                        glm::vec3( 1.5f,  2.0f, -2.5f),
                        glm::vec3( 1.5f,  0.2f, -1.5f),
                        glm::vec3(-1.3f,  1.0f, -1.5f)
                };

                unsigned int indices[] = {
                    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35
                };

                auto *vertexArray = new VertexArray();
                auto *vertexBuffer = new VertexBuffer(vertices, sizeof(vertices));

                auto *vertexBufferLayout = new VertexBufferLayout();
                (*vertexBufferLayout).pushFloat(3);
                (*vertexBufferLayout).pushFloat(2);
                (*vertexArray).addBuffer(*vertexBuffer, *vertexBufferLayout);
                auto *indexBuffer = new IndexBuffer(indices, 36);

                Texture *texture = new Texture("./res/texture/container.jpg");

                (*timer).start();
                while (isRunning) {
                    // @todo move to input handler
                    if (glfwGetKey((*window).getGlWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                        isRunning = false;
                    }

                    (*inputHandler).handleInput();

                    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
                    (*renderer).clear();
                    (*renderer).draw(window, camera, vertexArray, indexBuffer);

                    (*timer).reset();

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
            camera =  new Component::Camera::FPSCamera();
            inputHandler = new Framework::InputHandler(window, camera, timer);
            GLCall(glEnable(GL_DEPTH_TEST));
        }

        void registerEventListeners() {
            Event::EventDispatcher::getInstance().addListener((*inputHandler).getListenEvents(), inputHandler);
        }
        
    private:
        bool isRunning = true;
        Window *window;
        Renderer *renderer;
        Component::Timer *timer;
        Component::Camera::FPSCamera *camera;
        Framework::InputHandler *inputHandler;
};