#include "Component/Exception.hpp"

#include "Framework/VertexBufferElement.hpp"

#include "glad/glad.h"

namespace Framework {
    unsigned int VertexBufferElement::getSizeByType(unsigned int type) {
        switch (type) {
            case GL_FLOAT:          return 4; 
            case GL_UNSIGNED_INT:   return 4; 
            case GL_UNSIGNED_BYTE:  return 1; 
        };
        
        throw new Component::Exception("Invalid type in VertexBufferElement");
        return 0;
    }
}