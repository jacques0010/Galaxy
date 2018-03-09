#include"Quaternion.h"

namespace Engine{
	namespace Math {
		Quaternion::Quaternion(float i, float j, float k, float l)
			:m_Vector({ i, j, k }), m_Scalar(l)
		{}

		//Quaternion& multiply(const Quaternion& input)
		//{
		////	pq =  (pS qV + qS pV + pV x qV) (pS qS - pV * qV)  
		////	m_Vector.m_x
		//
		//}
	}
}