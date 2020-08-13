#include "Programm.h"
#include <fstream>
#include <iostream>
#include <iterator>


GL::Programm::Programm(const std::string& name)
{
	mProgramm = glCreateProgram();

	mVertexShader = loadShader("res/glsl/" + name + ".vert", GL_VERTEX_SHADER);
	mFragmentShader = loadShader("res/glsl/" + name + ".frag", GL_FRAGMENT_SHADER);
}

GL::Programm::~Programm()
{
	glDetachShader(mProgramm, mVertexShader);
	glDetachShader(mProgramm, mFragmentShader);
	glDeleteShader(mVertexShader);
	glDeleteShader(mFragmentShader);
	glDeleteProgram(mProgramm);
}

void GL::Programm::link()
{
	glAttachShader(mProgramm, mVertexShader);
	glAttachShader(mProgramm, mFragmentShader);

	glLinkProgram(mProgramm);
}

void GL::Programm::bindAttribute(GLuint index, const std::string& name)
{
	glBindAttribLocation(mProgramm, index, name.c_str());
}

void GL::Programm::use()
{
	glUseProgram(mProgramm);
}


GLuint GL::Programm::loadShader(const std::string& path, GLenum shader_type)
{
	GLuint shader = glCreateShader(shader_type);

	std::ifstream fis(path);

	std::string shaderCode = { std::istreambuf_iterator<char>(fis), std::istreambuf_iterator<char>()  };

	const char* c = shaderCode.c_str();

	glShaderSource(shader, 1, &c, nullptr);


	//получение результата
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	char buff[0x1000];
	GLsizei len;
	glGetShaderInfoLog(shader, sizeof(buff), &len, buff);
	if (len > 0)
	{
		std::cout << " error " << path << ":" << std::endl << buff;
	}

	return shader;
}