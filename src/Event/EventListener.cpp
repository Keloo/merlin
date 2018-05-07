#pragma once

#include "Event/EventListenerInterface.hpp"

#include <string>
#include <vector>
#include <set>

namespace Event {
    class EventListener: public EventListenerInterface {
        public: 
            void addListenEvent(std::string eventName) {
                listenEvents.insert(eventName);
            }
            void removeListenEvent(std::string eventName) {
                listenEvents.erase(eventName);
            }
            std::vector<std::string> getListenEvents() {
                std::vector<std::string> returnList;
                for (auto event: listenEvents) {
                    returnList.push_back(event);
                }
                return returnList;
            }
        private:
            std::set<std::string> listenEvents;
    };
}