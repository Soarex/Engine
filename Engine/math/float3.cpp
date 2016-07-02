#include "float3.h"

namespace math
{

	float3::float3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	float3::float3(float x, float y, float z) : x(x), y(y), z(z)
	{
	}


	float3::~float3()
	{
	}

}