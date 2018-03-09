#include "Mat4f.h"

namespace Engine {
	namespace Math {
		
		Mat4f Mat4f::Identity()
		{
			Mat4f result;
			result.m_Matrix[0 + 0 * 4] = 1;
			result.m_Matrix[1 + 1 * 4] = 1;
			result.m_Matrix[2 + 2 * 4] = 1;
			result.m_Matrix[3 + 3 * 4] = 1;
			return result;
		}

		Mat4f Mat4f::translate(const Vec3f& vector)
		{
			Mat4f result = Identity();
			result.m_Matrix[0 + 3 * 4] = vector.m_X;
			result.m_Matrix[1 + 3 * 4] = vector.m_Y;
			result.m_Matrix[2 + 3 * 4] = vector.m_Z;
			return result;
		}

		Mat4f Mat4f::rotate(const Vec3f& axis, const float& angle)
		{
			Mat4f result = Identity();
			float radians = toRadians(angle);
			float cosResult = std::cos(radians);
			float sinResult = std::sin(radians);
			float cosInv = 1.0f - cosResult;

			float x = axis.m_X;
			float y = axis.m_Y;
			float z = axis.m_Z;

			//first column
			result.m_Matrix[0 + 0 * 4] = x * cosInv + cosResult;
			result.m_Matrix[1 + 0 * 4] = sinResult * z;
			result.m_Matrix[2 + 0 * 4] = -sinResult * y;
			//second column
			result.m_Matrix[0 + 1 * 4] = -sinResult * z;
			result.m_Matrix[1 + 1 * 4] = y * cosInv + cosResult;
			result.m_Matrix[2 + 1 * 4] = sinResult * x;
			//third column
			result.m_Matrix[0 + 2 * 4] = sinResult * y;
			result.m_Matrix[1 + 2 * 4] = -sinResult * x;
			result.m_Matrix[2 + 2 * 4] = z * cosInv + cosResult;	

			return result;
		}

		Mat4f& Mat4f::multiply(const Mat4f& matrix)
		{
			Mat4f result;
			for (int column = 0; column < MAT4F_DIMINSION; column++)
			{
				for (int row = 0; row < MAT4F_DIMINSION; row++)
				{
					for (int element = 0; element < MAT4F_DIMINSION; element++)
					{
						result.m_Matrix[column + row * MAT4F_DIMINSION] +=
							m_Matrix[column + element * MAT4F_DIMINSION] * matrix.m_Matrix[element + row * MAT4F_DIMINSION];
					}
				}
			}

			m_Matrix.swap(result.m_Matrix);
			return *this;
		} 


		Mat4f& Mat4f::operator*=(const Mat4f& matrix)
		{
			return multiply(matrix);
		}
		Mat4f operator*(Mat4f& left, const Mat4f& right)
		{
			//todo: fix ... it currently modifies left
			return left.multiply(right);
		}

		Mat4f Mat4f::Orthographic(float right, float left, float top, float bottom, float far, float near)
		{
			Mat4f result;

			result.m_Matrix[0 + 0 * 4] = 2 / (right - left);
			result.m_Matrix[1 + 1 * 4] = 2 / (top - bottom);
			result.m_Matrix[2 + 2 * 4] = 2 / (near  -  far);
			result.m_Matrix[0 + 3 * 4] = -(right + left) / (right - left);
			result.m_Matrix[1 + 3 * 4] = -(top + bottom) / (top - bottom);
			result.m_Matrix[2 + 3 * 4] = -(far + near)	 /	 (near - far);
			result.m_Matrix[3 + 3 * 4] = 1;

			return result;
		}
		Mat4f Mat4f::Perspective(float aspectRatio, float fov, float far, float near)
		{
			Mat4f result;
			float normalizedFOV = toRadians(fov);
			float tanResult = std::tan(normalizedFOV / 2);

			result.m_Matrix[0 + 0 * 4] = (1 / (tanResult)) /aspectRatio;
			result.m_Matrix[1 + 1 * 4] = 1 / tanResult;
			result.m_Matrix[2 + 2 * 4] =  (far + near) / (near -far);
			result.m_Matrix[3 + 2 * 4] = -1;
			result.m_Matrix[2 + 3 * 4] = (2 * far * near) / (near - far);
			
			return result;

		}

	}
}