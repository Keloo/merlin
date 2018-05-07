#pragma once

#include <vector>
#include <string>
#include "Event/EventListenerInterface.hpp"

namespace Event {
    class EventDispatcherInterface {
        public:
            void dispatch(std::string eventName, EventInterface *eventInterface);
            void addListener(std::vector<std::string> eventNames, EventListenerInterface *eventListenerInterface);
            void addListener(std::string eventName);
            void removeListener(EventListenerInterface *eventListenerInterface);
            std::vector<EventListenerInterface*> getListeners(std::string eventName);
    };
}