#include "IndexBuffer.h"

using namespace core;

namespace graphic {

	IndexBuffer::IndexBuffer(UINT size, UINT* data) {
		D3D11_BUFFER_DESC d;
		d.Usage = D3D11_USAGE_IMMUTABLE;
		d.ByteWidth = size;
		d.BindFlags = D3D11_BIND_INDEX_BUFFER;
		d.CPUAccessFlags = 0;
		d.MiscFlags = 0;
		d.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA initData;
		initData.pSysMem = data;

		HRESULT res = RenderingAPI::getDevice()->CreateBuffer(&d, &initData, &m_IndexBuffer);

		if (FAILED(res)) {
			Window::messageBoxOk("Error", "Error during index buffer creation");
			exit(1);
		}
	}


	IndexBuffer::~IndexBuffer() {
		m_IndexBuffer->Release();
	}

	void IndexBuffer::bind() {
		RenderingAPI::getContext()->IASetIndexBuffer(m_IndexBuffer, DXGI_FORMAT_R32_UINT, 0);
	}

}