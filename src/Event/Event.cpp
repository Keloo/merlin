#include "Event/Event.hpp"

namespace Event {
    Event::Event(): propagationStopped(false) {};
    Event::~Event() = default;

    void Event::stopPropagation() {
        propagationStopped = true;
    }
    
    bool Event::isPropagationStopped() {
        return propagationStopped;
    }
}