#pragma once
#include <glew.h>
#include <vector>
namespace Engine {
	namespace Graphics {
		struct BufferElement {
			unsigned int m_Type;
			unsigned int m_Normalized;
			unsigned int m_Count;
			unsigned int m_Size;
		};

		class VertexBufferLayout {
		private:
			std::vector<BufferElement> elements;
			unsigned int m_Stride = 0;
		public:

			void pushFloats(const unsigned int count);
			void pushUnsignedInts(const unsigned int count);
			void pushChars(const unsigned int count);

			inline std::vector<BufferElement>& getElements() { return elements; };
			inline unsigned int getStride() { return m_Stride; }
		};
	}
}