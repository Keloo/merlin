#pragma once

namespace Framework {
    class Game {
        public:
            Game();
            ~Game();
            void run();
        private:
            void init();
            
            bool isRunning = true;
    };
}