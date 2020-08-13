#pragma once
#include <gl.h>
#include <vector>

namespace GL
{
	class VAO
	{
	private:
		GLuint mVao;
		std::vector<GLuint> mBuffer;
	public:
		VAO();
		VAO(const VAO&) = delete;
		void bind();
		void addVertexBufferObject(const std::vector<float>& data);
		void draw(GLuint cont);
		~VAO();
	};
}


