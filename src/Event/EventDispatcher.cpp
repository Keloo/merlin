#include "Event/EventDispatcherInterface.hpp"
#include "Event/EventInterface.hpp"
#include "Event/EventListenerInterface.hpp"
#include "Event/Event.cpp"
#include "Event/EventListener.cpp"

#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

namespace Event {
    class EventDispatcher: public EventDispatcherInterface {
        public:
            void dispatch(std::string eventName, EventInterface *eventInterface) {
                Event *event = static_cast<Event*>(eventInterface);
                if ((*event).isPropagationStopped()) {
                    return;
                }
                for (auto listener: eventListeners[eventName]) {
                    (*listener).onEvent(event);
                }
            }
            void addListener(std::vector<std::string> eventNames, EventListenerInterface *eventListener) {
                for (auto eventName: eventNames) {
                    addListener(eventName, eventListener);
                }
            }
            void addListener(std::string eventName, EventListenerInterface *eventListenerInterface) {
                EventListener *eventListener = static_cast<EventListener*>(eventListenerInterface);
                eventListeners[eventName].insert(eventListener);
                (*eventListener).addListenEvent(eventName);                
            }
            
            void removeListener(EventListenerInterface *eventListenerInterface) {
                EventListener *eventListener = static_cast<EventListener*>(eventListenerInterface);
                for (std::string eventName: (*eventListener).getListenEvents()) {
                    eventListeners[eventName].erase(eventListener);
                }
            }
            std::vector<EventListenerInterface*> getListeners(std::string eventName) {
                std::vector<EventListenerInterface*> returnList;
                for (auto listener: eventListeners[eventName]) {
                    returnList.push_back(listener);
                }
                return returnList;
            }
            static EventDispatcher* const getInstance() {
                if (instance == nullptr) {
                    instance = new EventDispatcher();
                }

                return instance;
            }
        private:
            std::map<std::string, std::set<EventListenerInterface*>> eventListeners;
            static EventDispatcher *instance;
    };
}

Event::EventDispatcher* Event::EventDispatcher::instance = nullptr;