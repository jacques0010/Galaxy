#pragma once
#include <glew.h>
namespace Engine {
	namespace Graphics {
		class IndexBuffer {
		private:
			unsigned int m_IndexBuffer;
			unsigned int m_Count;
		public:
			IndexBuffer(unsigned int* data, unsigned int count);
			~IndexBuffer();
			void bind() const;
			void unbind() const;


		};
	}
}