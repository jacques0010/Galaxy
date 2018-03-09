#pragma once
#include "Vec3f.h"

namespace Engine {
	namespace Math {
		class Quaternion
		{
		public:
			Vec3f m_Vector;
			float m_Scalar;
		public:
			
			Quaternion(float i, float j, float k, float l);

			Quaternion& multiply(const Quaternion& input);
			Quaternion& operator*=(const Quaternion& other);
			friend Quaternion operator*(const Quaternion& left, const Quaternion& right);

		};
	}
}