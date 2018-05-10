#pragma once

#include <chrono>
#include <ctime>

namespace Component {
    class Timer {
        public:
            Timer();
            ~Timer();
            void start();
            std::chrono::duration<double> elapsed();
            void stop();
        private:
            std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds> startTime;
    };
}