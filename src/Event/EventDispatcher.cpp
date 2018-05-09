#include "Event/EventDispatcher.hpp"
#include "Event/Event.hpp"
#include "Event/EventListener.hpp"
// #include "Event/Event.cpp"
// #include "Event/EventListener.cpp"

#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

namespace Event {
    EventDispatcher* EventDispatcher::instance = nullptr;
    
    EventDispatcher::EventDispatcher(){};
    EventDispatcher::~EventDispatcher(){};
    

    void EventDispatcher::dispatch(std::string eventName, Event *event) {
        if ((*event).isPropagationStopped()) {
            return;
        }
        for (auto listener: eventListeners[eventName]) {
            (*listener).onEvent(event);
        }
    }
    
    void EventDispatcher::addListener(std::vector<std::string> eventNames, EventListener *eventListener) {
        for (auto eventName: eventNames) {
            addListener(eventName, eventListener);
        }
    }
    
    void EventDispatcher::addListener(std::string eventName, EventListener *eventListener) {
        eventListeners[eventName].insert(eventListener);
        (*eventListener).addListenEvent(eventName);                
    }
    
    void EventDispatcher::removeListener(EventListener *eventListener) {
        for (std::string eventName: (*eventListener).getListenEvents()) {
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
    EventDispatcher* EventDispatcher::getInstance() {
        if (instance == nullptr) {
            instance = new EventDispatcher();
        }

        return instance;
    }
}