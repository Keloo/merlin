#pragma once

#include <glad/glad.h>
#include <string>

namespace Framework {
    class Texture {
    public:
        Texture(std::string path);
        ~Texture();

        void bind() const;
        void unbind() const;

        unsigned int getGlTextureId() const;
        void setGlTextureId(unsigned int glTextureId);

        void setParameterInt(unsigned int name, int value) const;
        void setParameterFloat(unsigned int name, float value) const;
    private:
        unsigned int glTextureId;
        int width;
        int height;
        int nrChannels;
        unsigned char* data;
    };
}