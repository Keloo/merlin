#include "CursorPosition.hpp"

#include <string>

namespace Event {namespace Mouse {
    std::string CursorPosition::NAME = "mouse.cursor_position";

    CursorPosition::CursorPosition(double offsetX, double offsetY) {
        CursorPosition::offsetX = offsetX;
        CursorPosition::offsetY = offsetY;
    }

    double CursorPosition::getOffsetX() const {
        return offsetX;
    }

    void CursorPosition::setOffsetX(double offsetX) {
        CursorPosition::offsetX = offsetX;
    }

    double CursorPosition::getOffsetY() const {
        return offsetY;
    }

    void CursorPosition::setOffsetY(double offsetY) {
        CursorPosition::offsetY = offsetY;
    }
}}