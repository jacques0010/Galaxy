#include "Buffer.h"

namespace Engine {
	namespace Graphics {
		Buffer::Buffer(float* data, unsigned int size)
		{
			glGenBuffers(1 , &m_Buffer);
			bind();
			glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
		}

		Buffer::~Buffer()
		{
			glDeleteBuffers(1, &m_Buffer);
		}

		void Buffer::bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);
		}
		
		void Buffer::unbind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
}