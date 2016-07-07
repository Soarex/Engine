#pragma once
#include "Texture.h"
#include "..\math\math.h"

namespace graphic {

	struct Sprite {
		math::float3	position;
		math::float2	size;
		math::float4	color;
		Texture*		texture;
		math::float2	uvs[4];

		Sprite(math::float3 position, math::float2 size, math::float4 color);
		Sprite(math::float3 position, math::float2 size, Texture* texture);
		~Sprite();
		//void SetUVs(float2 uvs[]);
	};

}