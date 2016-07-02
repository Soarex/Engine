#include "VertexBuffer.h"

using namespace core;

namespace graphic
{

	VertexBuffer::VertexBuffer(UINT size, D3D11_USAGE usage, UINT access, UINT stride, void* data) : m_Stride(stride)
	{
		D3D11_BUFFER_DESC d;
		d.ByteWidth = size;
		d.Usage = usage;
		d.StructureByteStride = 0;
		d.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		d.MiscFlags = 0;
		d.CPUAccessFlags = access;

		HRESULT res;
		if (data != nullptr)
		{
			D3D11_SUBRESOURCE_DATA a;
			a.pSysMem = data;
			res = RenderingAPI::GetDevice()->CreateBuffer(&d, &a, &m_VertexBuffer);
		}
		else
			res = RenderingAPI::GetDevice()->CreateBuffer(&d, NULL, &m_VertexBuffer);


		if (FAILED(res))
		{
			Window::MessageBoxOk("Error", "Error during vertex buffer creation");
			exit(1);
		}

	}


	VertexBuffer::~VertexBuffer()
	{
		m_VertexBuffer->Release();
	}

	void VertexBuffer::Bind()
	{
		UINT offset = 0;
		RenderingAPI::GetContext()->IASetVertexBuffers(0, 1, &m_VertexBuffer, &m_Stride, &offset);
	}

	void VertexBuffer::Unmap()
	{
		RenderingAPI::GetContext()->Unmap(m_VertexBuffer, 0);
	}

}