#pragma once

#include "Event/Event.hpp"

#include <string>

namespace Event { namespace Mouse {
    class CursorPosition: public Event {
    public:
        CursorPosition(double, double);
        static std::string NAME;
        double getOffsetX() const;
        void setOffsetX(double offsetX);
        double getOffsetY() const;
        void setOffsetY(double offsetY);
    private:
        double offsetX;
        double offsetY;
    };
}}