#pragma once

#include <vector>
#include <string>
#include <map>
#include <set>
#include "Event/EventListener.hpp"
#include "Event/Event.hpp"

namespace Event {
    class EventDispatcher {
        public:
            EventDispatcher();
            ~EventDispatcher();
            void dispatch(std::string eventName, Event *event);
            void addListener(std::vector<std::string> eventNames, EventListener *eventListener);
            void addListener(std::string eventName, EventListener *eventListener);
            void removeListener(EventListener *eventListener);
            std::vector<EventListener*> getListeners(std::string eventName);
            static EventDispatcher* getInstance();
        private:
            static EventDispatcher* instance;
            std::map<std::string, std::set<EventListener*>> eventListeners;
    };
}