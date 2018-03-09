#include <glew.h>
#include "Engine\window\Window.h"
#include "Engine\Math\Vectors\Vector.h"
#include "Engine\Math\Mat4f.h"
#include "Engine\Shaders\Shader.h"
#include "Engine\OGLBuffers\OGLBuffers.h"
#include <iostream>
using namespace Engine;
int main()
{
	Engine::Window* window = Engine::Window::createWindow(1280, 720, "test");
	Graphics::Shader shader("res/Shaders/BasicVert.sdr", "res/Shaders/BasicFrag.sdr");
	shader.bind();
	/*float positions[] = {
		0.5f,   0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f,
	   -0.5f,   0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f,
	   -0.5f,  -0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 1.0f,
		0.5f,  -0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 1.0f,
	};*/
	float positions[] = {
		//front
		-1.0, -1.0,	1.0, 1.0f, 1.0f, 1.0f, 1.0f,
		 1.0, -1.0,	1.0, 1.0f, 1.0f, 1.0f, 1.0f,
		 1.0,  1.0,	1.0, 1.0f, 1.0f, 1.0f, 1.0f,
		-1.0,  1.0,	1.0, 1.0f, 1.0f, 1.0f, 1.0f,
		// back		 
		-1.0, -1.0, -1.0, 1.0f, 1.0f, 1.0f, 1.0f,
		 1.0, -1.0, -1.0, 1.0f, 1.0f, 1.0f, 1.0f,
		 1.0,  1.0, -1.0, 1.0f, 1.0f, 1.0f, 1.0f,
		-1.0,  1.0, -1.0, 1.0f, 1.0f, 1.3f, 1.0f,
	};
/*
	unsigned int indecies[] = {
		0, 1, 2,
		2, 3, 0

	};*/

	unsigned int indecies[] = {
		0, 1, 2,
		2, 3, 0,
		// top
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// bottom
		4, 0, 3,
		3, 7, 4,
		// left
		4, 5, 1,
		1, 0, 4,
		// right
		3, 2, 6,
		6, 7, 3,


	};

	
	Math::Mat4f rotation = Math::Mat4f::rotate({ 0, 1, 0 }, .2);
	Math::Mat4f rotation1 = Math::Mat4f::rotate({ 0, 0, 1}, .2);
	Math::Mat4f projection = Math::Mat4f::Perspective(((float)16/9), 45, 10, .1);
	Math::Mat4f transform = Math::Mat4f::Identity();
	
	transform *= Math::Mat4f::translate({0, 0, -5});
	//transform *= rotation1;

	Graphics::VertexBufferLayout layout;
	layout.pushFloats(3);
	layout.pushFloats(4);
	Graphics::VertexArray va;
	Engine::Graphics::Buffer buffer(positions, sizeof(positions));
	buffer.bind();
	Engine::Graphics::IndexBuffer indexbuffer(indecies, 36);
	indexbuffer.bind();
	va.addBuffer(buffer, layout);
	glfwSwapInterval(1);
	glEnable(GL_DEPTH_TEST);
	
	while (!glfwWindowShouldClose(window->m_Windowptr))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		transform *= rotation;
		transform *= rotation1;
		
		shader.setUniformMat4("m_Projection", projection);
		shader.setUniformMat4("m_Transform", transform);
		//std::cout << glGetError() << std::endl;
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
		
		glfwSwapBuffers(window->m_Windowptr);
		glfwPollEvents();
	}
}	

