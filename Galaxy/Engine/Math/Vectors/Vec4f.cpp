#include "Vec4f.h"

namespace Engine {
	namespace Math {
		Vec4f::Vec4f(float x, float y, float z, float w)
			: m_X(x), m_Y(y), m_Z(z), m_W(w)
		{}

		Vec4f::Vec4f()
			:m_X(0), m_Y(0), m_Z(0), m_W(0)
		{}

		Vec4f& Vec4f::add(const Vec4f& vector)
		{
			m_X += vector.m_X;
			m_Y += vector.m_Y;
			m_Z += vector.m_Z;
			m_W += vector.m_W;
			return *this;
		}
		Vec4f& Vec4f::operator+=(const Vec4f& vector)
		{
			return add(vector);
		}
		Vec4f operator+(const Vec4f left, const Vec4f right)
		{
			return Vec4f(left.m_X + right.m_X, left.m_Y + right.m_Y, left.m_Z + right.m_Z, left.m_W + right.m_W);
		}

		Vec4f& Vec4f::subtract(const Vec4f& vector)
		{
			m_X -= vector.m_X;
			m_Y -= vector.m_Y;
			m_Z -= vector.m_Z;
			m_W -= vector.m_W;
			return *this;
		}
		Vec4f& Vec4f::operator-=(const Vec4f& vector)
		{
			return subtract(vector);
		}
		Vec4f operator-(const Vec4f left, const Vec4f right)
		{
			return Vec4f(left.m_X - right.m_X, left.m_Y - right.m_Y, left.m_Z - right.m_Z, left.m_W - right.m_W);
		}

		Vec4f& Vec4f::scale(const float scalar)
		{
			m_X *= scalar;
			m_Y *= scalar;
			m_Z *= scalar;
			m_W *= scalar;
			return *this;
		}

		std::ostream& operator<<(std::ostream& stream, Vec4f vector)
		{
			stream << "Vec4f (X: " << vector.m_X << " Y: " << vector.m_Y << " Z: " << vector.m_Z << " W: " << vector.m_W << " )";
			return stream;
		}
	}
}