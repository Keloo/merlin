#pragma once

#include "Event/EventInterface.hpp"

#include <vector>
#include <string>

namespace Event {
    class EventListenerInterface {
        public:
            void addListenEvent(std::string eventName);
            void removeListenEvent(std::string eventName);
            std::vector<std::string> getListenEvents();
            virtual void onEvent(EventInterface *eventInterface)=0;
    };
}