#include "VertexArray.h"

namespace Engine {
	namespace Graphics {
		VertexArray::VertexArray()
		{
			glGenVertexArrays(1, &m_RendererID);
			bind();

		}

		VertexArray::~VertexArray()
		{
			glDeleteVertexArrays(1, &m_RendererID);
		}

		void VertexArray::addBuffer(Buffer& buffer, VertexBufferLayout layout)
		{
			bind();
			std::vector<BufferElement> elements = layout.getElements();
			unsigned int elementPtr = 0;
			for (int i = 0; i < elements.size(); i++)
			{
				glEnableVertexAttribArray(i);
				glVertexAttribPointer(i, elements[i].m_Count, elements[i].m_Type, elements[i].m_Normalized,
					layout.getStride() , (void*)elementPtr);
				elementPtr += elements[i].m_Size;
			}
		}

		void VertexArray::bind()
		{
			glBindVertexArray(m_RendererID);
		}
		
		void VertexArray::unbind()
		{
			glBindVertexArray(0);
		}
	}
}