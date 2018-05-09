#pragma once

#include <string>

namespace Framework {
    class Window {
        private: 
            std::string title;
        public: 
            Window(std::string);
            ~Window();
    };
}