#pragma once

#include "Component/Command.hpp"
#include "Component/Camera/FPSCamera.hpp"
#include "Component/Timer.hpp"

namespace Component {
    class CursorMoveCommand : public Command {
    public:
        explicit CursorMoveCommand(Camera::FPSCamera *camera, Timer *timer);
        ~CursorMoveCommand() override;
        void execute() override;
        double getOffsetX() const;
        void setOffsetX(double offsetX);
        double getOffsetY() const;
        void setOffsetY(double offsetY);

        double getLastOffsetX() const;

        void setLastOffsetX(double lastOffsetX);

        double getLastOffsetY() const;

        void setLastOffsetY(double lastOffsetY);

        bool isIsSetLastOffset() const;

        void setIsSetLastOffset(bool isSetLastOffset);

    private:
        Camera::FPSCamera *camera;
        Timer *timer;
        double offsetX;
        double offsetY;
        double lastOffsetX;
        double lastOffsetY;
        bool isSetLastOffset;
    };
}