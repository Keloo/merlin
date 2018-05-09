#pragma once

namespace Event {
    class Event {
        public:
            Event();
            ~Event();
            void stopPropagation();
            bool isPropagationStopped();
        private:
            bool propagationStopped;
    };
}