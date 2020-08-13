#include <iostream>

#include <GLFW/glfw3.h>
#include "GLFW/GLFW.h"
#include "GLFW/Window.h"

int main()
{
	try
	{
		GLFW glfw;
		Window m("m_252", 500, 500);
		m.loop();
	}
	catch (std::runtime_error e)
	{
		std::cout << "Exception" << e.what() << std::endl;
		return -1;
	}
		return 0;
}