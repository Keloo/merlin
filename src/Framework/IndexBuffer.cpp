#include "Framework/IndexBuffer.hpp"
#include "Framework/GLDebug.hpp"

#include "glad/glad.h"

namespace Framework {
    IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count): count(count) {
        GLCall(glGenBuffers(1, &glIndexBufferId));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glIndexBufferId));
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
    };

    IndexBuffer::~IndexBuffer() {
        GLCall(glDeleteBuffers(1, &glIndexBufferId));
    };

    void IndexBuffer::bind() const {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glIndexBufferId));
    }

    void IndexBuffer::unbind() const {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }
}