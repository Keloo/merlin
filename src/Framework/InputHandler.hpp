#pragma once

#include <Component/Timer.hpp>
#include <Component/Command.hpp>
#include <Component/Camera/Camera.hpp>
#include <Component/Camera/FPSCamera.hpp>

#include "Framework/Window.hpp"

namespace Framework {
    class InputHandler {
    public:
        InputHandler(Framework::Window *window, Component::Camera::FPSCamera*, Component::Timer*);
        ~InputHandler();

        void handleInput();
    private:
        Framework::Window *window;

        Component::Command *buttonW;
        Component::Command *buttonS;
        Component::Command *buttonA;
        Component::Command *buttonD;
        Component::Command *cursor;
    };
}