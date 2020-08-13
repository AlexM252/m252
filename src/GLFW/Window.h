#pragma once
#include <GLFW/glfw3.h>
#include <string>

class Window
{
private:
	GLFWwindow* window_252;
public:
	Window(const std::string &stringname, int width, int height);
	void setContextCurrent();
	void loop();
	~Window();

};
