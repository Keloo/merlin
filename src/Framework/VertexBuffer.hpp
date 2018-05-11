#pragma once

namespace Framework {
    class VertexBuffer {
        public:
            VertexBuffer();
            ~VertexBuffer();
        
            void bind();
            void unbind();
        private:
            unsigned int glVertexBufferId;
    };
}