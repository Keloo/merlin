#include <Component/Camera/Camera.hpp>
#include <Event/EventDispatcher.hpp>
#include <Event/Game/TerminateEvent.hpp>
#include "Component/MoveCommand.hpp"
#include "Framework/GLDebug.hpp"
#include "Framework/InputHandler.hpp"
#include "Framework/Window.hpp"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

namespace Framework {

    InputHandler::InputHandler(Framework::Window *window, Component::Camera::FPSCamera *camera, Component::Timer *timer) {
        buttonW = new Component::MoveCommand(camera, timer, Component::Camera::Direction::FORWARD);
        buttonS = new Component::MoveCommand(camera, timer, Component::Camera::Direction::BACKWARD);
        buttonA = new Component::MoveCommand(camera, timer, Component::Camera::Direction::LEFT);
        buttonD = new Component::MoveCommand(camera, timer, Component::Camera::Direction::RIGHT);
    };

    InputHandler::~InputHandler() = default;

    void InputHandler::handleInput() {
        if (glfwGetKey((*window).getGlWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose((*window).getGlWindow(), true);
        }
        if (glfwGetKey((*window).getGlWindow(), GLFW_KEY_W) == GLFW_PRESS) {
            buttonW->execute();
        }
        if (glfwGetKey((*window).getGlWindow(), GLFW_KEY_S) == GLFW_PRESS) {
            buttonS->execute();
        }
        if (glfwGetKey((*window).getGlWindow(), GLFW_KEY_A) == GLFW_PRESS) {
            buttonA->execute();
        }
        if (glfwGetKey((*window).getGlWindow(), GLFW_KEY_D) == GLFW_PRESS) {
            buttonD->execute();
        }
    }
}