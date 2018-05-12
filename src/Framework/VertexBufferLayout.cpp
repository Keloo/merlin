#include "Framework/VertexBufferLayout.hpp"
#include "Framework/VertexBufferElement.hpp"

#include "glad/glad.h"

namespace Framework {
    VertexBufferLayout::VertexBufferLayout(): stride(0), elements({}) {};
    VertexBufferLayout::~VertexBufferLayout(){};

    void VertexBufferLayout::pushFloat(unsigned int count) {
        elements.push_back({ GL_FLOAT, count, GL_FALSE });
        stride += count * VertexBufferElement::getSizeByType(GL_FLOAT);
    }

    std::vector<VertexBufferElement> VertexBufferLayout::getElements() const {
        return elements;
    }

    unsigned int VertexBufferLayout::getStride() const {
        return stride;
    }
}