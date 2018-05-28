#pragma once

#include "Component/Command.hpp"
#include "Component/Camera/FPSCamera.hpp"
#include "Component/Timer.hpp"

namespace Component {
    class CursorMoveCommand : public Command {
    public:
        explicit CursorMoveCommand(Camera::FPSCamera *camera, Timer *timer);
        ~CursorMoveCommand() override;
        void execute(double offsetX, double offsetY) override;

    private:
        Camera::FPSCamera *camera;
        Timer *timer;
    };
}