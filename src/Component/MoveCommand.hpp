#pragma once

#include <Component/Camera/FPSCamera.hpp>
#include "Component/Command.hpp"
#include "Timer.hpp"

namespace Component {
    class MoveCommand: public Component::Command {
    public:
        explicit MoveCommand(Camera::FPSCamera *camera, Timer *timer, Camera::Direction);
        ~MoveCommand() override;
        void execute() override;
        void execute(double, double) override;
    private:
        Camera::Direction direction;
        Camera::FPSCamera *camera;
        Timer *timer;
    };
}