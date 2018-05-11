#include "Framework/VertexBuffer.hpp"
#include "Framework/GLDebug.hpp"

#include "glad/glad.h"

namespace Framework {
    VertexBuffer::VertexBuffer(const void *data, unsigned int size){
        GLCall(glGenBuffers(1, &glVertexBufferId));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, glVertexBufferId));
        GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
    };

    VertexBuffer::~VertexBuffer(){
        GLCall(glDeleteBuffers(1, &glVertexBufferId));
    };

    void VertexBuffer::bind() const {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, glVertexBufferId));
    }

    void VertexBuffer::unbind() const {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    }
}