#pragma once

#include "Framework/Window.hpp"

namespace Framework {
    class Input {
        public:
            Input();
            ~Input();

            void handleKeyboard(Framework::Window*);
    };
}