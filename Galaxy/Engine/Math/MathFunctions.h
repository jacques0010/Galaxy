#pragma once
#include <math.h>

namespace Engine {
	namespace Math {

#define PI 3.1415926535
		inline float toRadians(float angle)
		{
			return ((float) PI  * angle) / 180;
		}
	}
}