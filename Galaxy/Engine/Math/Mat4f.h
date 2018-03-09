#pragma once
#include <iostream>
#include <array>
#include "Vectors\Vector.h"
#include "MathFunctions.h"

#define MAT4F_DIMINSION 4

namespace Engine {
	namespace Math {
		class Mat4f {
		public:
			enum Axis {
				X = 0, Y = 1, Z = 2
			};
		private:
			std::array<float, (4 * 4)> m_Matrix = { 0.0f, 0.0f, 0.0f, 0.0f,
													0.0f, 0.0f, 0.0f, 0.0f,
													0.0f, 0.0f, 0.0f, 0.0f,
													0.0f, 0.0f, 0.0f, 0.0f };

		private:
			inline Mat4f() { m_Matrix.fill(0); }

		public:
			//~Mat4f();

			static Mat4f Identity();
			static Mat4f translate(const Vec3f& vector);

			static Mat4f rotate(const Vec3f& axis, const float& angle);
			
			Mat4f& multiply(const Mat4f& matrix);
			Mat4f& operator*=(const Mat4f& matrix);
			Mat4f& operator=(const Mat4f& matrix);

			friend Mat4f operator*(Mat4f& left, const Mat4f& right);

			static Mat4f Orthographic(float right, float left, float top, float bottom, float far, float near);
			static Mat4f Perspective(float aspectRatio, float fov, float far, float near);

			inline float* getMatrixAsArray() { return m_Matrix.data(); }
		};
	}
}