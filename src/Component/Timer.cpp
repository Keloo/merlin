#include "Timer.hpp"

namespace Component {
    Timer::Timer(){};
    Timer::~Timer(){};

    void Timer::start() {
        startTime = std::chrono::system_clock::now();
    }

    void Timer::stop() {
        // @TODO don't know why I need this :D
    }

    std::chrono::duration<double> Timer::elapsed() {
        return std::chrono::system_clock::now()-startTime;
    }
}