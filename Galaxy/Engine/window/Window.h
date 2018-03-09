#pragma once
#include <glfw3.h>
namespace Engine {
	class Window {
	public:
		GLFWwindow* m_Windowptr;
	private:
		Window();
		~Window();
	public:
		static Window* createWindow(int width, int height, const char* title);
		static Window* createDefaultWindow(const char* title);
		//bool setWindowSize();

	};
}