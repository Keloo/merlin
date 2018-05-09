#pragma once

namespace Framework {
    class Game {
        public:
            Game();
            ~Game();
            void run();
        private:
            void init();
            void initGlad();
            bool isRunning = true;
    };
}