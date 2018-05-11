#pragma once


namespace Framework {
    class IndexBuffer {
        public:
            IndexBuffer(const unsigned int *data, unsigned int count);
            ~IndexBuffer();

            void bind() const;
            void unbind() const;
        private:
            unsigned int glIndexBufferId;
            unsigned int count;
    };
}