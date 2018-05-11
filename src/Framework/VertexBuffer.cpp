#include "Framework/VertexBuffer.hpp"
// #include "Framework/GLDebug.hpp"

#include "glad/glad.h"

namespace Framework {
    VertexBuffer::VertexBuffer(){
        glGenBuffers(1, &glVertexBufferId);
    };
    VertexBuffer::~VertexBuffer(){};

    void VertexBuffer::bind() {

    }

    void VertexBuffer::unbind() {

    }
}