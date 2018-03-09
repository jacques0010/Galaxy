#pragma once
#include <iostream>

namespace Engine {
	namespace Math {
		struct Vec3f
		{
		public:
			float m_X, m_Y, m_Z;
		public:
			Vec3f(float x, float y, float z);

			Vec3f& add(const Vec3f& vector);
			Vec3f& operator+=(const Vec3f& vector);
			friend Vec3f operator+(const Vec3f left, const Vec3f right);

			Vec3f& subtract(const Vec3f& vector);
			Vec3f& operator-=(const Vec3f& vector);
			friend Vec3f operator-(const Vec3f left, const Vec3f right);

			Vec3f& scale(const float& scalar);

			Vec3f crossProduct(const Vec3f& input);

			float dotProduct(const Vec3f& input);

			friend std::ostream& operator<<(std::ostream& stream, const Vec3f vector);
		};
	}
}