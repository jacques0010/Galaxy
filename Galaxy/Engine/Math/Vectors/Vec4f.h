#pragma once
#include <iostream>

namespace Engine {
	namespace Math {
		struct Vec4f
		{
		public:
			float m_X, m_Y, m_Z, m_W;
		public:
			Vec4f();
			Vec4f(float x, float y, float z, float w);

			Vec4f& add(const Vec4f& vector);
			Vec4f& operator+=(const Vec4f& vector);
			friend Vec4f operator+(const Vec4f left, const Vec4f right);

			Vec4f& subtract(const Vec4f& vector);
			Vec4f& operator-=(const Vec4f& vector);
			friend Vec4f operator-(const Vec4f left, const Vec4f right);

			Vec4f& scale(const float scalar);


			friend std::ostream& operator<<(std::ostream& stream, const Vec4f vector);
		};
	}
}