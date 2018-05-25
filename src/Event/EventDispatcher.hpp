#pragma once

#include "Event/EventListener.hpp"
#include "Event/Event.hpp"

#include <vector>
#include <string>
#include <map>
#include <set>

namespace Event {
    class EventDispatcher {
        public:
            void dispatch(std::string eventName, Event *event);
            void addListener(std::vector<std::string> eventNames, EventListener *eventListener);
            void addListener(std::string eventName, EventListener *eventListener);
            void removeListener(EventListener *eventListener);
            std::vector<EventListener*> getListeners(std::string eventName);
            static EventDispatcher& getInstance();
        private:
            std::map<std::string, std::set<EventListener*>> eventListeners;

            EventDispatcher(); // singleton hide
            EventDispatcher(EventDispatcher const &); // singleton hide
            void operator=(EventDispatcher const &); // singleton hide
    };
}