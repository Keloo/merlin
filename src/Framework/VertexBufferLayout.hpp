#pragma once

#include "Framework/VertexBufferElement.hpp"

#include <vector>

namespace Framework {
    class VertexBufferLayout {
        public:
            void pushFloat(unsigned int count);
            void pushByte(unsigned int count);
            void pushUnsignedInt(unsigned int count);
            std::vector<VertexBufferElement> getElements() const;
            unsigned int getStride() const;
        private:
            std::vector<VertexBufferElement> elements;
            unsigned int stride;
    };
}