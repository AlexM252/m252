#include <GLFW/glfw3.h>
#include "GLFW.h"
#include <stdexcept>

GLFW::GLFW()
{
	if (!glfwInit())
	{
		throw std::runtime_error("Error glfwInit");
	}
}

GLFW::~GLFW()
{
	glfwTerminate();
}