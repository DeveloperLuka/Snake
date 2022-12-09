#include <snake/texture/texture.hpp>
#include <stb/stb_image.h>

texture::texture(GLenum textureTarget, const std::string& fileName)
{
	m_TextureTarget = textureTarget;
	m_FileName = fileName;
}

bool texture::load()
{
	stbi_set_flip_vertically_on_load(1);
	int width = 0, height = 0, bpp = 0;
	unsigned char* image_data = stbi_load(m_FileName.c_str(), &width, &height, &bpp, 0);

	if (!image_data)
	{
		return false;
	}

	glGenTextures(1, &m_TextureObj);
	glBindTexture(m_TextureTarget, m_TextureObj);
	if (m_TextureTarget == GL_TEXTURE_2D)
	{
		glTexImage2D(m_TextureTarget, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
	}
	else
	{
		return false;
	}
	
	glTexParameterf(m_TextureTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(m_TextureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(m_TextureTarget, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(m_TextureTarget, GL_TEXTURE_WRAP_T, GL_CLAMP);
	
	glBindTexture(m_TextureTarget, 0);
	
	stbi_image_free(image_data);

	return true;
}

void texture::bind(GLenum textureUnit)
{
	glActiveTexture(textureUnit);
	glBindTexture(m_TextureTarget, m_TextureObj);
}
