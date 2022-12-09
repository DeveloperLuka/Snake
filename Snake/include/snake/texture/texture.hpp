#include <string>
#include <GL/glew.h>

class texture
{
public:
	texture(GLenum textureTarget, const std::string& fileName);
	
	bool load();

	void bind(GLenum textureUnit);

private:
	std::string m_FileName;
	GLenum m_TextureTarget;
	GLuint m_TextureObj;
};