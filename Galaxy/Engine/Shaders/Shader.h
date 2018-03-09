#pragma once
#include <glew.h>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include "..\Math\MathLib.h"
#include "..\FileUtils\FileUtils.h"

namespace Engine {
	namespace Graphics {
		class Shader {
		private:
			unsigned int m_ProgramID;
			std::unordered_map<const char*, int> locationCache;
		public:
			Shader(const std::string& vertexShader, const std::string& fragShader);
			~Shader();

			void setUniform1i(const char* name, const int& value);
			void setUniform1f(const char* name, const float& value);
			void setUniform2f(const char* name, const Math::Vec2f& value);
			void setUniform3f(const char* name, const Math::Vec3f& value);
			void setUniform4f(const char* name, const Math::Vec4f& value);
			void setUniformMat4(const char* name, Math::Mat4f value);

			void bind();
			void unbind();

			inline unsigned int getShaderID() { return m_ProgramID; }

		private:
			unsigned int compileSource(const std::string& shaderSource, GLenum type);
		};
	}
}