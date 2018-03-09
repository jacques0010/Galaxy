#include "Vec2f.h"



namespace Engine {
	namespace Math {
		Vec2f::Vec2f(float x, float y)
			: m_X(x), m_Y(y)
		{
		}

		Vec2f& Vec2f::add(const Vec2f& vector)
		{
			m_X += vector.m_X;
			m_Y += vector.m_Y;
			return *this;
		}
		Vec2f& Vec2f::operator+=(const Vec2f& vector)
		{
			return add(vector);
		}
		Vec2f operator+(const Vec2f left, const Vec2f right)
		{
			return Vec2f(left.m_X + right.m_X, left.m_Y + right.m_Y);
		}

		Vec2f& Vec2f::subtract(const Vec2f& vector)
		{
			m_X -= vector.m_X;
			m_Y -= vector.m_Y;
			return *this;
		}
		Vec2f& Vec2f::operator-=(const Vec2f& vector)
		{
			return subtract(vector);
		}
		Vec2f operator-(const Vec2f left, const Vec2f right)
		{
			return Vec2f(left.m_X - right.m_X, left.m_Y - right.m_Y);
		}

		Vec2f& Vec2f::scale(const float scalar)
		{
			m_X *= scalar;
			m_Y *= scalar;
			return *this;
		}

		std::ostream& operator<<(std::ostream& stream, Vec2f vector)
		{
			stream << "Vec2f (X: " << vector.m_X << " Y: " << vector.m_Y << " )";
			return stream;
		}
	}
}