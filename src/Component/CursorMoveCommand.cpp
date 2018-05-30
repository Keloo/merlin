#include "Component/CursorMoveCommand.hpp"
#include "Component/Camera/FPSCamera.hpp"
#include "Component/Timer.hpp"
#include <iostream>

namespace Component {
    CursorMoveCommand::CursorMoveCommand(Camera::FPSCamera *camera, Timer *timer):
            camera(camera),
            timer(timer),
            isSetLastOffset(false) {}
    CursorMoveCommand::~CursorMoveCommand() = default;

    void CursorMoveCommand::execute() {
        if (!isIsSetLastOffset()) {
            setIsSetLastOffset(true);
            lastOffsetX = offsetX;
            lastOffsetY = offsetY;
        }

        double newOffsetX = offsetX - lastOffsetX;
        double newOffsetY = lastOffsetY - offsetY;

        setLastOffsetX(offsetX);
        setLastOffsetY(offsetY);

        offsetX =  newOffsetX * camera->getMouseSensitivity();
        offsetY = newOffsetY * camera->getMouseSensitivity();

        camera->setYaw(camera->getYaw() + offsetX);
        camera->setPitch(camera->getPitch() + offsetY);

        // some controls I don't know :D (@todo)
        if (camera->getPitch() > 89.0f)
            camera->setPitch(89.0f);
        if (camera->getPitch() < -89.0f)
            camera->setPitch(-89.0f);

        camera->updateCameraVectors();
    }

    double CursorMoveCommand::getOffsetX() const {
        return offsetX;
    }

    void CursorMoveCommand::setOffsetX(double offsetX) {
        CursorMoveCommand::offsetX = offsetX;
    }

    double CursorMoveCommand::getOffsetY() const {
        return offsetY;
    }

    void CursorMoveCommand::setOffsetY(double offsetY) {
        CursorMoveCommand::offsetY = offsetY;
    }

    double CursorMoveCommand::getLastOffsetX() const {
        return lastOffsetX;
    }

    void CursorMoveCommand::setLastOffsetX(double lastOffsetX) {
        CursorMoveCommand::lastOffsetX = lastOffsetX;
    }

    double CursorMoveCommand::getLastOffsetY() const {
        return lastOffsetY;
    }

    void CursorMoveCommand::setLastOffsetY(double lastOffsetY) {
        CursorMoveCommand::lastOffsetY = lastOffsetY;
    }

    bool CursorMoveCommand::isIsSetLastOffset() const {
        return isSetLastOffset;
    }

    void CursorMoveCommand::setIsSetLastOffset(bool isSetLastOffset) {
        CursorMoveCommand::isSetLastOffset = isSetLastOffset;
    }
}