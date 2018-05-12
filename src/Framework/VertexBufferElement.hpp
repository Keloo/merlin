#pragma once

namespace Framework {
    struct VertexBufferElement {
        unsigned int type;
        unsigned int count;
        unsigned char normalized;
        static unsigned int getSizeByType(unsigned int type);
    };
}