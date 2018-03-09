#include "VertexBufferLayout.h"

namespace Engine {
	namespace Graphics{	
		
		void VertexBufferLayout::pushFloats(const unsigned int count)
		{
			elements.push_back({ GL_FLOAT, GL_FALSE, count, count * sizeof(GLfloat) });
			m_Stride += count * sizeof(GLfloat);
		}
		void VertexBufferLayout::pushUnsignedInts(const unsigned int count)
		{
			elements.push_back({ GL_UNSIGNED_INT, GL_FALSE, count, count * sizeof(GLuint) });
			m_Stride += count * sizeof(GLuint);
		}
		void VertexBufferLayout::pushChars(const unsigned int count)
		{
			elements.push_back({ GL_UNSIGNED_BYTE, GL_TRUE, count, count * sizeof(GLubyte) });
			m_Stride += count * sizeof(GLubyte);
		}

//		std::vector<BufferElement>& VertexBufferLayout::getElements(){ return elements; }

	}
}