#pragma once
#include <glew.h>
#include <vector>
#include "Buffer.h"
#include "VertexBufferLayout.h"
namespace Engine {
	namespace Graphics {
		class VertexArray
		{
		private:
			unsigned int m_RendererID;
		public:
			VertexArray();
			~VertexArray();


			void addBuffer(Buffer& buffer, VertexBufferLayout layout);

			void bind();
			void unbind();
		};
	}
}
