#pragma once
#include <iostream>

namespace Engine {
	namespace Math {
		struct Vec2f
		{
		public:
			float m_X, m_Y;
		public:
			Vec2f(float x, float y);

			Vec2f& add(const Vec2f& vector);
			Vec2f& operator+=(const Vec2f& vector);
			friend Vec2f operator+(const Vec2f left, const Vec2f right);
			
			Vec2f& subtract(const Vec2f& vector);
			Vec2f& operator-=(const Vec2f& vector);
			friend Vec2f operator-(const Vec2f left, const Vec2f right);

			Vec2f& scale(const float scalar);

			friend std::ostream& operator<<(std::ostream& stream, const Vec2f vector);
		};
	}
}