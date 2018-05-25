#include "Event/EventListener.hpp"

#include <string>
#include <vector>
#include <set>

namespace Event {
    EventListener::EventListener() = default;
    EventListener::~EventListener() = default;
    
    void EventListener::addListenEvent(std::string eventName) {
        listenEvents.insert(eventName);
    }

    void EventListener::removeListenEvent(std::string eventName) {
        listenEvents.erase(eventName);
    }

    std::vector<std::string> EventListener::getListenEvents() {
        std::vector<std::string> returnList;
        for (auto const & event: listenEvents) {
            returnList.push_back(event);
        }
        return returnList;
    }
}