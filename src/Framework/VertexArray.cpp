#include "Framework/GLDebug.hpp"
#include "Framework/VertexArray.hpp"

namespace Framework {
    VertexArray::VertexArray(){};
    VertexArray::~VertexArray(){};

    void VertexArray::addBuffer(const VertexBuffer &buffer, const VertexBufferLayout &layout) {
        buffer.bind();
        const std::vector<VertexBufferElement> &elements = layout.getElements();
        unsigned int offset = 0;
        for (unsigned int i=0; i<elements.size(); i++) {
            const VertexBufferElement &element = elements[i];
            GLCall(glEnableVertexAttribArray(i));
            GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void *)offset));
            offset += element.count * VertexBufferElement::getSizeByType(element.type);
        }
    }
}