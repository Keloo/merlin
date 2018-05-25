#include "Event/EventDispatcher.hpp"
#include "Event/Event.hpp"
#include "Event/EventListener.hpp"

#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

namespace Event {
    EventDispatcher::EventDispatcher() = default;

    void EventDispatcher::dispatch(std::string eventName, Event *event) {
        if ((*event).isPropagationStopped()) {
            return;
        }
        for (auto listener: eventListeners[eventName]) {
            (*listener).onEvent(event);
        }
    }
    
    void EventDispatcher::addListener(std::vector<std::string> eventNames, EventListener *eventListener) {
        for (auto const & eventName: eventNames) {
            addListener(eventName, eventListener);
        }
    }
    
    void EventDispatcher::addListener(std::string eventName, EventListener *eventListener) {
        eventListeners[eventName].insert(eventListener);
        (*eventListener).addListenEvent(eventName);                
    }
    
    void EventDispatcher::removeListener(EventListener *eventListener) {
        for (std::string const & eventName: (*eventListener).getListenEvents()) {
            eventListeners[eventName].erase(eventListener);
        }
    }

    std::vector<EventListener*> EventDispatcher::getListeners(std::string eventName) {
        std::vector<EventListener*> returnList;
        for (auto listener: eventListeners[eventName]) {
            returnList.push_back(listener);
        }
        return returnList;
    }

    EventDispatcher& EventDispatcher::getInstance() {
        static EventDispatcher instance; // singleton trick (initialized only once, destroyed correctly)

        return instance;
    }
}