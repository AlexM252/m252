#include <gl.h>

#include "Window.h"
#include <stdexcept>
#include "GL/VAO.h"
#include "GL/Programm.h"
#include <GLFW/glfw3.h>


Window::Window(const std::string& stringname, int width, int height)
{
	window_252 = glfwCreateWindow(width, height, stringname.c_str(), nullptr, nullptr);
	if (!window_252)
	{
		throw std::runtime_error("Error win252");
	}
	setContextCurrent();
	glewExperimental = true; //получение доступа к экспериментальным функциям

	if (glewInit() != GLEW_OK)
	{
		throw std::runtime_error("Error GLEW");
	}
}
void Window::setContextCurrent()
{
	glfwMakeContextCurrent(window_252); //привязываемся к потоку - почитать про нее

}
void Window::loop()
{
	
	GL::VAO vao;
	vao.addVertexBufferObject({0, 0, 0, 1.0f, 0, 0, 0, 1.0f,  0});//{0, 0.5f, 0, -0.5f, -0.5f, 0, 0.5f, -0.5f, 0}
/**/
	GL::Programm first("first");
	first.bindAttribute(0, "position");
	first.link();
	first.use();

	while (!glfwWindowShouldClose(window_252))
	{
		glClearColor(1., 1., 0., 1.); //установка цвета R-G-B-alfa от нуля до 1
		glClear(GL_COLOR_BUFFER_BIT); //очистка цветового буфера
		vao.draw(3);
		glfwSwapBuffers(window_252); //замена экрана, без него просто белый экран
		glfwPollEvents();
	}
}


Window::~Window()
{
	glfwDestroyWindow(window_252);
}