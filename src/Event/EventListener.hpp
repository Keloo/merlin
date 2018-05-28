#pragma once

#include "Event/Event.hpp"

#include <vector>
#include <string>
#include <set>

namespace Event {
    class EventListener {
        public:
            EventListener();
            virtual ~EventListener();
            void addListenEvent(std::string eventName);
            void removeListenEvent(std::string eventName);

        virtual std::vector<std::string> getListenEvents();
            virtual void onEvent(Event *event) = 0;
        private:
            std::set<std::string> listenEvents;
    };
}