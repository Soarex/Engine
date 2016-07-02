#include "Sprite.h"

using namespace math;

namespace graphic
{

	Sprite::Sprite(float3 position, float2 size, float4 color) : position(position), size(size), color(color), texture(nullptr)
	{
	}

	Sprite::Sprite(float3 position, float2 size, Texture* texture) : position(position), size(size), texture(texture)
	{
		uvs[0] = float2(0.0f, 1.0f);
		uvs[1] = float2(1.0f, 1.0f);
		uvs[2] = float2(1.0f, 0.0f);
		uvs[3] = float2(0.0f, 0.0f);
	}

	Sprite::~Sprite()
	{
	}

	/*
	void Sprite::SetUVs(float2 uvs[])
	{
		this->uvs[0] = uvs[0];
		this->uvs[1] = uvs[1];
		this->uvs[2] = uvs[2];
		this->uvs[3] = uvs[3];
	}
	*/
}