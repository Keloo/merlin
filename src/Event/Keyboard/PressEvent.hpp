#pragma once

#include "Event/Event.hpp"

#include <string>

namespace Event { namespace Keyboard {
    class PressEvent: public Event {
        public:
            static std::string NAME;
            unsigned int key;
    };
}}