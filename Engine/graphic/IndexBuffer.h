#pragma once
#include <d3d11.h>
#include "../core/core.h"

namespace graphic
{

	class IndexBuffer
	{
	private:
		ID3D11Buffer* m_IndexBuffer;
	public:
		IndexBuffer(UINT size, UINT* data);
		~IndexBuffer();
		void Bind();
	};

}