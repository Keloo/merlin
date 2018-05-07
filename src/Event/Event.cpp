#pragma once

#include "Event/EventInterface.hpp"

namespace Event {
    class Event: public EventInterface {
        public:
            Event(): propagationStopped(false) {};
            void stopPropagation() {
                propagationStopped = true;
            }
            bool isPropagationStopped() {
                return propagationStopped;
            }
        private:
            bool propagationStopped;
    };
}