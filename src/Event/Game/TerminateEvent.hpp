#pragma once

#include "Event/Event.hpp"

#include <string>

namespace Event { namespace Game {
    class TerminateEvent: public Event {
        public:
            static std::string NAME;
    };
}}