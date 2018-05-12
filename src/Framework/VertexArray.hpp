#pragma once

#include "Framework/VertexBuffer.hpp"
#include "Framework/VertexBufferLayout.hpp"

namespace Framework {
    class VertexArray {
        public:
            VertexArray();
            ~VertexArray();

            void bind() const;
            void unbind() const;
            void addBuffer(const VertexBuffer &buffer, const VertexBufferLayout &layout);
        private:
            unsigned int glVertexArrayId;
    };
}