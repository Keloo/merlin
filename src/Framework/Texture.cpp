#include "Texture.hpp"
#include "Framework/GLDebug.hpp"
#include "Component/Exception.hpp"
#include "stb_image/stb_image.h"

//@todo refactor this (parametrize more)
namespace Framework {
    Texture::Texture(std::string path) {
        stbi_set_flip_vertically_on_load(true);
        data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
        if (!data) {
            throw Component::Exception("can not open texture file " + path);
        }
        GLCall(glGenTextures(1, &glTextureId));
        bind();
        setParameterInt(GL_TEXTURE_WRAP_S, GL_REPEAT);
        setParameterInt(GL_TEXTURE_WRAP_T, GL_REPEAT);
        setParameterInt(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        setParameterInt(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
    }
    Texture::~Texture() = default;

    unsigned int Texture::getGlTextureId() const {
        return glTextureId;
    }

    void Texture::setGlTextureId(unsigned int glTextureId) {
        Texture::glTextureId = glTextureId;
    }

    void Texture::bind() const {
        GLCall(glBindTexture(GL_TEXTURE_2D, glTextureId));
    };

    void Texture::unbind() const {

    };

    void Texture::setParameterInt(unsigned int name, int value) const {
        GLCall(glTexParameteri(GL_TEXTURE_2D, name, value));
    }

    void Texture::setParameterFloat(unsigned int name, float value) const {
        GLCall(glTexParameterf(GL_TEXTURE_2D, name, value));
    }
}