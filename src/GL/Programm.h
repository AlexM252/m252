#pragma once
#include <gl.h>
#include <string>

namespace GL
{
class Programm
{
private:
	GLuint mProgramm;

	GLuint mVertexShader;
	GLuint mFragmentShader;

	GLuint loadShader(const std::string& path, GLenum shader_type);
public:
	Programm(const std::string &name);
	~Programm();

	void link();
	void bindAttribute(GLuint index, const std::string& name);
	void use();
};
}


