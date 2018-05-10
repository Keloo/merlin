#pragma once

#include <string>

#include "Event/Event.hpp"

namespace Event { namespace Game {
    class TerminateEvent: public Event {
        public:
            static std::string NAME;
    };
}}