#include <Component/Camera/Camera.hpp>
#include <Component/Exception.hpp>
#include "MoveCommand.hpp"
#include "Timer.hpp"

#include <iostream>
#include <iomanip>
#include <Component/Camera/FPSCamera.hpp>

namespace Component {
    MoveCommand::MoveCommand(Camera::FPSCamera *camera, Timer *timer, Camera::Direction direction):
        direction(direction),
        camera(camera),
        timer(timer)
    {}

    MoveCommand::~MoveCommand() = default;

    void MoveCommand::execute() {
        double deltaTime = (*timer).elapsed().count();
        double cameraSpeed = (*camera).getMovementSpeed()*deltaTime;
        glm::vec3 cameraPosition = (*camera).getPosition();

        switch (direction) {
            case Camera::Direction::FORWARD:
                cameraPosition += (float)cameraSpeed * (*camera).getFrontVector();
                break;
            case Camera::Direction::BACKWARD:
                cameraPosition -= (float)cameraSpeed * (*camera).getFrontVector();
                break;
            case Camera::Direction::LEFT:
                cameraPosition -= (float)cameraSpeed * (*camera).getRightVector();
                break;
            case Camera::Direction::RIGHT:
                cameraPosition += (float)cameraSpeed * (*camera).getRightVector();
                break;
            default:
                throw Exception("invalid camera direction");
        }

        (*camera).setPosition(cameraPosition);
        (*camera).updateCameraVectors();
    }
}