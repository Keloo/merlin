#include "Component/CursorMoveCommand.hpp"
#include "Component/Camera/FPSCamera.hpp"
#include "Component/Timer.hpp"
#include <iostream>

namespace Component {
    CursorMoveCommand::CursorMoveCommand(Camera::FPSCamera *camera, Timer *timer): camera(camera), timer(timer) {}
    CursorMoveCommand::~CursorMoveCommand() = default;

    void CursorMoveCommand::execute(double offsetX, double offsetY) {
        std::cout << offsetX << ' ' << offsetY << std::endl;
    }
}