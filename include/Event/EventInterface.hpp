#pragma once

namespace Event {
    class EventInterface {
        public:
            void stopPropagation();
            bool isPropagationStopped();
        private:
            bool propagationStopped;
    };
}