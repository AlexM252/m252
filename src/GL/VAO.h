#pragma once
#include <gl.h>
#include <vector>
#include "glm/glm.hpp"

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
		void addVertexBufferObject(const std::vector<glm::vec2>& data);
		void addVertexBufferObject(const std::vector<glm::vec3>& data);
		void addVertexBufferObject(const std::vector<glm::vec4>& data);
		void draw(GLuint cont);
		~VAO();
	};
}


