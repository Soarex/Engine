#pragma once
#include "../math/math.h"
#include "../core/core.h"
#include "VertexBuffer.h"
#include "Sprite.h"
#include "IndexBuffer.h"

namespace graphic
{

	#define RENDERER_MAX_SPRITES	40000
	#define RENDERER_SPRITE_SIZE	sizeof(VertexData) * 4
	#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
	#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6
	#define RENDERER_MAX_TEXTURES	32 - 1

	struct VertexData
	{
		math::float3 position;
		math::float4 color;
	};


	class Renderer2D
	{
	private:
		VertexBuffer m_VertexBuffer;
		IndexBuffer* m_IndexBuffer;
		VertexData* m_BufferPointer;
		UINT m_IndexCount;
	public:
		Renderer2D();
		~Renderer2D();

		void Begin();
		void Submit(Sprite& s);
		void End();
		void Render();
	};

}