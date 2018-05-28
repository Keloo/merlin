#include "Timer.hpp"

namespace Component {
    Timer::Timer() = default;
    Timer::~Timer() = default;

    void Timer::start() {
        startTime = std::chrono::system_clock::now();
    }

    void Timer::reset() {
        start();
    }

    void Timer::stop() {
        // @TODO don't know why I need this :D
    }

    std::chrono::duration<double> Timer::elapsed() {
        return std::chrono::system_clock::now()-startTime;
    }
}