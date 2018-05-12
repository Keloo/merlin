#include "Framework/GLDebug.hpp"
#include "Framework/VertexArray.hpp"

namespace Framework {
    VertexArray::VertexArray(){
        GLCall(glGenVertexArrays(1, &glVertexArrayId));
        bind();
    };
    VertexArray::~VertexArray(){
        GLCall(glDeleteVertexArrays(1, &glVertexArrayId));        
    };

    void VertexArray::bind() const {
        GLCall(glBindVertexArray(glVertexArrayId));
    }

    void VertexArray::unbind() const {
        GLCall(glBindVertexArray(0));        
    }

    void VertexArray::addBuffer(const VertexBuffer &buffer, const VertexBufferLayout &layout) {
        bind();
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