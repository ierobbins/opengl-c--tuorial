#include "texture.h"
#include "stb_image.h"
#include <cassert.h>
#include <iostream>

Texture::Texture(const std::string& fileName){
    unsigned inst width, height, numComponents;
    unsigned char* imageData = stbi_load(fileName.c_str(), &width, &height, &numComponents, 4);

    if(imageData == NULL)
        std::cerr << "Texture loading failed for texture: " << fileName << std::endl;

    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2d(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

    stbi_image_free(imageData);
}

void Texture::Bind(unsigned int unit){
    assert(unit >= 0 && unit <= 31);

    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, m_texture);
}

Texture::~Texture(){
    glDeleteTextures(1, &m_texture);
}