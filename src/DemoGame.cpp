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
#include <Component/Object.hpp>
#include <Component/Cube.hpp>
#include <zconf.h>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "glm/gtx/norm.hpp"

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

                auto *cubeModel = new Component::Object();
                auto *cube1 = new Component::Cube(cubeModel);
                auto *cube2 = new Component::Cube(cubeModel);
                cube1->setPosition(glm::vec3(-3.0f, -2.0f, 0.0f));
                cube2->setPosition(glm::vec3(3.0f, -2.0f, 0.0f));

                cube1->setVelocity(glm::vec3(0.0f, 0.0f, -20.0f));
                cube2->setVelocity(glm::vec3(0.0f, 0.0f, 10.0f));

                cube1->setMass(20.0f);
                cube2->setMass(10.0f);

                auto *vertexArray = new VertexArray();
                auto *vertexBuffer = new VertexBuffer((*cubeModel).getGlVertex().data(), (unsigned int)(*cubeModel).getGlVertex().size()*sizeof(float));

                auto *vertexBufferLayout = new VertexBufferLayout();
                (*vertexBufferLayout).pushFloat(3);
                (*vertexBufferLayout).pushFloat(2);
                (*vertexArray).addBuffer(*vertexBuffer, *vertexBufferLayout);
                auto *indexBuffer = new IndexBuffer((*cubeModel).getGlIndices().data(), 36);

                Texture *texture = new Texture("./res/texture/container.jpg");

                (*timer).start();
                while (isRunning) {
                    // @todo move to input handler
                    if (glfwGetKey((*window).getGlWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                        isRunning = false;
                    }
                    usleep(100000);

                    (*inputHandler).handleInput();

                    float dist = glm::l2Norm(cube1->getPosition(), cube2->getPosition());

                    float F = (cube1->getMass()*cube2->getMass())/pow(dist,2);

                    glm::vec3 F1 = (cube2->getPosition()-cube1->getPosition()) / dist * F;
                    glm::vec3 F2 = (cube1->getPosition()-cube2->getPosition()) / dist * F;

                    glm::vec3 newCube1Velocity = (F1+cube1->getVelocity());
                    glm::vec3 newCube2Velocity = (F2+cube2->getVelocity());

                    double deltaTime = (*timer).elapsed().count();

                    cube1->setPosition(cube1->getPosition()+newCube1Velocity*(float)deltaTime);
                    cube2->setPosition(cube2->getPosition()+newCube2Velocity*(float)deltaTime);

                    cube1->setVelocity(newCube1Velocity);
                    cube2->setVelocity(newCube2Velocity);

                    (*renderer).clear();
                    (*renderer).draw(window, camera, vertexArray, indexBuffer, cube1);
                    (*renderer).draw(window, camera, vertexArray, indexBuffer, cube2);

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