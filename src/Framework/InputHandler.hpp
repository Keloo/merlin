#pragma once

#include <Component/Timer.hpp>
#include <Component/Command.hpp>
#include <Component/Camera/Camera.hpp>
#include <Component/Camera/FPSCamera.hpp>

#include "Framework/Window.hpp"

namespace Framework {
    class InputHandler: public Event::EventListener {
    public:
        InputHandler(Framework::Window *window, Component::Camera::FPSCamera*, Component::Timer*);
        ~InputHandler();
        void onEvent(Event::Event *event) override;
        void handleInput();
        std::vector<std::string> getListenEvents() override;
    private:
        Framework::Window *window;

        Component::Command *buttonW;
        Component::Command *buttonS;
        Component::Command *buttonA;
        Component::Command *buttonD;
        Component::Command *cursor;
    };
}