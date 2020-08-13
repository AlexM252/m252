#include "VAO.h"



GL::VAO::VAO()
{
	glGenVertexArrays(1, &mVao);
	bind();
}
void GL::VAO::bind()
{
	glBindVertexArray(mVao);
}
void GL::VAO::addVertexBufferObject(const std::vector<float>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffer.size(), 1, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffer.push_back(vbo);


}
void GL::VAO::addVertexBufferObject(const std::vector<glm::vec2>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec2), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffer.size(), 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffer.push_back(vbo);


}
void GL::VAO::addVertexBufferObject(const std::vector<glm::vec3>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec3), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffer.size(), 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffer.push_back(vbo);


}
void GL::VAO::addVertexBufferObject(const std::vector<glm::vec4>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec4), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffer.size(), 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffer.push_back(vbo);


}
void GL::VAO::draw(GLuint count)
{
	for (size_t i = 0; i < mBuffer.size(); ++i)
	{
		glEnableVertexAttribArray(i);
	}
	bind();
	glDrawArrays(GL_TRIANGLES, 0, count);

	for (size_t i = 0; i < mBuffer.size(); ++i)
	{
		glDisableVertexAttribArray(i);
	}
}
GL::VAO::~VAO()
{
	glDeleteBuffers(mBuffer.size(), mBuffer.data());
	glDeleteVertexArrays(1, &mVao);
}