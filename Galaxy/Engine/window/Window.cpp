#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "Window.h"

namespace Engine {

	Window::Window()
		: m_Windowptr(nullptr)
	{
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Windowptr);
	}
	Window* Window::createDefaultWindow(const char* title)
	{
		return Window::createWindow(800, 600, title);
	}
	Window* Window::createWindow(int width, int height, const char* title)
	{
		Window* window = new Window;
		if (!glfwInit())
		{
			std::cout << "glfw did not init" << std::endl;
			return nullptr;
		}

		window->m_Windowptr = glfwCreateWindow(width, height, title, NULL, NULL);
		glfwMakeContextCurrent(window->m_Windowptr);

		
		if (glewInit() != GLEW_OK)
		{
			std::cout << "GLEW not ok" << std::endl;
			return nullptr;
		}
		return window;
	}

}