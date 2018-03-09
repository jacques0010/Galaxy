#pragma once
#include <glew.h>

namespace Engine {
	namespace Graphics {
		class Buffer {
		private:
			unsigned int m_Buffer;
		public:
			Buffer(float* data, unsigned int size);
			~Buffer();
			void bind() const;
			void unbind() const;


		};
	} 
}