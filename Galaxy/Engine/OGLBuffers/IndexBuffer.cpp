#include "IndexBuffer.h"

namespace Engine {
	namespace Graphics {
		IndexBuffer::IndexBuffer(unsigned int* data, unsigned int count)
		{
			glGenBuffers(1, &m_IndexBuffer);
			bind();
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
		}

		IndexBuffer::~IndexBuffer()
		{
			glDeleteBuffers(1, &m_IndexBuffer);
		}

		void IndexBuffer::bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
		}

		void IndexBuffer::unbind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}
}