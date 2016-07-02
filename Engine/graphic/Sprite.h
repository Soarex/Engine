#pragma once
#include "../math/math.h"


namespace graphic
{

	struct Sprite
	{
		math::float3 position;
		math::float2 size;
		math::float4 color;

		Sprite(math::float3 position, math::float2 size, math::float4 color);
		~Sprite();
	};

}