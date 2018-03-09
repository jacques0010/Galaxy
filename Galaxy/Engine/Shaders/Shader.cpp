#include "Shader.h"

namespace Engine {
	namespace Graphics {
		Shader::Shader(const std::string& vertexShader, const std::string& fragShader)
		{
			std::string vertShaderSource = Util::loadAsString(vertexShader);
			std::string fragShaderSource = Util::loadAsString(fragShader);

			unsigned int vertShaderC = compileSource(vertShaderSource, GL_VERTEX_SHADER);
			unsigned int fragShaderC = compileSource(fragShaderSource, GL_FRAGMENT_SHADER);

			m_ProgramID = glCreateProgram();

			glAttachShader(m_ProgramID, vertShaderC);
			glAttachShader(m_ProgramID, fragShaderC);

			glLinkProgram(m_ProgramID);

			glDeleteShader(vertShaderC);
			glDeleteShader(fragShaderC);
		}

		Shader::~Shader()
		{
			glDeleteProgram(m_ProgramID);
		}

		void Shader::bind()
		{
			glUseProgram(m_ProgramID);
		}

		void Shader::unbind()
		{
			glUseProgram(0);
		}

		void Shader::setUniform1i(const char* name, const int& value)
		{
			if (locationCache.find(name) == locationCache.end())
			{
				int location = glGetUniformLocation(m_ProgramID, name);
				locationCache[name] = location;
			}

			glUniform1i(locationCache.at(name), value);
		}
		void Shader::setUniform1f(const char* name, const float& value)
		{
			if (locationCache.find(name) == locationCache.end())
			{
				int location = glGetUniformLocation(m_ProgramID, name);
				locationCache[name] = location;
			}

			glUniform1f(locationCache.at(name), value);

		}
		void Shader::setUniform2f(const char* name, const Math::Vec2f& value)
		{
			if (locationCache.find(name) == locationCache.end())
			{
				int location = glGetUniformLocation(m_ProgramID, name);
				locationCache[name] = location;
			}


			glUniform2f(locationCache.at(name), value.m_X, value.m_Y);

		}
		void Shader::setUniform3f(const char* name, const Math::Vec3f& value)
		{
			if (locationCache.find(name) == locationCache.end())
			{
				int location = glGetUniformLocation(m_ProgramID, name);
				locationCache[name] = location;
			}


			glUniform3f(locationCache.at(name), value.m_X, value.m_Y, value.m_Z);
		}
		void Shader::setUniform4f(const char* name, const Math::Vec4f& value)
		{
			if (locationCache.find(name) == locationCache.end())
			{
				int location = glGetUniformLocation(m_ProgramID, name);
				locationCache[name] = location;
			}


			glUniform4f(locationCache.at(name), value.m_X, value.m_Y, value.m_Z, value.m_W);
		}
		void Shader::setUniformMat4(const char* name, Math::Mat4f value)
		{
			if (locationCache.find(name) == locationCache.end())
			{
				int location = glGetUniformLocation(m_ProgramID, name);
				locationCache[name] = location;

			}

				//std::cout << glGetError() << std::endl;

			glUniformMatrix4fv((locationCache.at(name)), 1 ,GL_FALSE, value.getMatrixAsArray());
		}

		unsigned int Shader::compileSource(const std::string& shaderSource, GLenum type)
		{
			unsigned int shader = glCreateShader(type);
			const char* source = shaderSource.c_str();
			glShaderSource(shader, 1, &source, NULL);
			glCompileShader(shader);

			int compileStatus;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
			if (compileStatus != GL_TRUE)
			{
				std::string shaderType;
				switch (type)
				{
				case GL_VERTEX_SHADER:
					shaderType = "Vertex";
					break;
				case GL_FRAGMENT_SHADER:
					shaderType = "Fragment";
					break;
				default:
					shaderType = "[Unknown]";
					break;
				};
				std::cout << shaderType << " shader failed to compile" << std::endl;

				int logLength = 0;
				char message[1024];
				glGetShaderInfoLog(shader, 1024, &logLength, message);

				std::cout << message << std::endl;
				return 0;
			}
			return shader;
		}
	}
}