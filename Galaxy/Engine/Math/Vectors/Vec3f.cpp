#include "Vec3f.h"

namespace Engine {
	namespace Math {
		Vec3f::Vec3f(float x, float y, float z)
			: m_X(x), m_Y(y), m_Z(z)
		{
		}

		Vec3f& Vec3f::add(const Vec3f& vector)
		{
			m_X += vector.m_X;
			m_Y += vector.m_Y;
			m_Z += vector.m_Z;
			return *this;
		}
		Vec3f& Vec3f::operator+=(const Vec3f& vector)
		{
			return add(vector);
		}
		Vec3f operator+(const Vec3f left, const Vec3f right)
		{
			return Vec3f(left.m_X + right.m_X, left.m_Y + right.m_Y, left.m_Z + right.m_Z);
		}

		Vec3f& Vec3f::subtract(const Vec3f& vector)
		{
			m_X -= vector.m_X;
			m_Y -= vector.m_Y;
			m_Z -= vector.m_Z;
			return *this;
		}
		Vec3f& Vec3f::operator-=(const Vec3f& vector)
		{
			return subtract(vector);
		}
		Vec3f operator-(const Vec3f left, const Vec3f right)
		{
			return Vec3f(left.m_X - right.m_X, left.m_Y - right.m_Y, left.m_Z - right.m_Z);
		}
		Vec3f& Vec3f::scale(const float& scalar)
		{
			m_X *= scalar;
			m_Y *= scalar;
			m_Z *= scalar;
			return *this;
		}
		Vec3f Vec3f::crossProduct(const Vec3f& input)
		{
			return { m_Y * input.m_Z - m_Z * input.m_Y,
					 m_X * input.m_Z - m_Z * input.m_Z,
					 m_X * input.m_Y - m_Y * input.m_X };
		}

		float Vec3f::dotProduct(const Vec3f& input)
		{
			return  m_X * input.m_X + m_Y * input.m_Y + m_Z * input.m_Z;
		}

		std::ostream& operator<<(std::ostream& stream, Vec3f vector)
		{
			stream << "Vec3f (X: " << vector.m_X << " Y: " << vector.m_Y << " Z: " << vector.m_Z << " )";
			return stream;
		}
	}
}