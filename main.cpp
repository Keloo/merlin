#include <iostream>
#include "Event/Event.cpp"
#include "Event/EventDispatcher.cpp"
#include "Event/EventListener.cpp"

class MessageEvent : public Event::Event {
    public:
        static const std::string NAME;
        void setMessage(std::string _message) {
            message = _message;
        }
        std::string getMessage() {
            return message;
        }
    private:
        std::string message;
};

const std::string MessageEvent::NAME = "message";

class Console : public Event::EventListener {
    public:
        Console(){};
        void onEvent(Event::Event *event) {
            MessageEvent *messageEvent = static_cast<MessageEvent*>(event);
            std::cout << (*messageEvent).getMessage();
        }
};

int main() {
    Event::EventDispatcher *eventDispatcher = Event::EventDispatcher::getInstance();

    MessageEvent *messageEvent = new MessageEvent();
    (*messageEvent).setMessage("hello world");

    Console *console = new Console();
    (*eventDispatcher).addListener("message", console);

    (*eventDispatcher).dispatch(MessageEvent::NAME, messageEvent);

    (*eventDispatcher).removeListener(console);
    (*eventDispatcher).dispatch(MessageEvent::NAME, messageEvent);

    return 0;
}