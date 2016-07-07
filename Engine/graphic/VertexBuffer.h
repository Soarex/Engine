#pragma once
#include <d3d11.h>
#include "../core/core.h"

namespace graphic {

	class VertexBuffer {
	private:
		ID3D11Buffer*	 m_VertexBuffer;
		UINT			 m_Stride;
	public:
		VertexBuffer(UINT size, D3D11_USAGE usage, UINT access, UINT stride, void* data = nullptr);
		~VertexBuffer();
		void bind();

		template <class t>
		t map() {
			D3D11_MAPPED_SUBRESOURCE sa;
			RenderingAPI::getContext()->Map(m_VertexBuffer, 0, D3D11_MAP_WRITE_NO_OVERWRITE, 0, &sa);
			return (t)sa.pData;
		}

		void unmap();
	};

}