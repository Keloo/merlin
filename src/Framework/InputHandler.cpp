#include <Component/Camera/Camera.hpp>
#include <Event/EventDispatcher.hpp>
#include <Event/Game/TerminateEvent.hpp>
#include "Component/MoveCommand.hpp"
#include "Framework/GLDebug.hpp"
#include "Framework/InputHandler.hpp"
#include "Framework/Window.hpp"
#include "Event/Mouse/CursorPosition.hpp"
#include "Component/CursorMoveCommand.hpp"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

namespace Framework {

    InputHandler::InputHandler(Framework::Window *window, Component::Camera::FPSCamera *camera, Component::Timer *timer) {
        buttonW = new Component::MoveCommand(camera, timer, Component::Camera::Direction::FORWARD);
        buttonS = new Component::MoveCommand(camera, timer, Component::Camera::Direction::BACKWARD);
        buttonA = new Component::MoveCommand(camera, timer, Component::Camera::Direction::LEFT);
        buttonD = new Component::MoveCommand(camera, timer, Component::Camera::Direction::RIGHT);
        cursor = new Component::CursorMoveCommand(camera, timer);
        InputHandler::window = window;
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

    void InputHandler::onEvent(Event::Event * _event) {
        auto event = dynamic_cast<Event::Mouse::CursorPosition*>(_event);
        auto cursorCommand = dynamic_cast<Component::CursorMoveCommand*>(cursor);
        (*cursorCommand).setOffsetX((*event).getOffsetX());
        (*cursorCommand).setOffsetY((*event).getOffsetY());

        cursorCommand->execute();
    }

    std::vector<std::string> InputHandler::getListenEvents() {
        return {
            Event::Mouse::CursorPosition::NAME,
        };
    }
}