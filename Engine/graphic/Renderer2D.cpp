#include "Renderer2D.h"

using namespace core;
using namespace math;

namespace graphic
{

	Renderer2D::Renderer2D() : m_VertexBuffer(RENDERER_BUFFER_SIZE, D3D11_USAGE_DYNAMIC, D3D11_CPU_ACCESS_WRITE, sizeof(VertexData))
	{
		m_IndexCount = 0;

		UINT* indices = new UINT[RENDERER_INDICES_SIZE];
		int offset = 0;
		for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6)
		{
			indices[i] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;

			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;

			offset += 4;
		}

		m_IndexBuffer = new IndexBuffer(RENDERER_INDICES_SIZE * sizeof(UINT), indices);
		delete indices;
		RenderingAPI::SetPrimitiveTopology(TRIANGLELIST);
	}


	Renderer2D::~Renderer2D()
	{
		delete m_IndexBuffer;
	}

	void Renderer2D::Begin()
	{
		m_BufferPointer = m_VertexBuffer.Map<VertexData*>();
	}

	void Renderer2D::Submit(Sprite& s)
	{
		float3& position = s.position;
		float2& size = s.size;

		m_BufferPointer->position = float3(position.x, (position.y + size.y), position.z);
		m_BufferPointer->color = s.color;
		m_BufferPointer++;

		m_BufferPointer->position = float3((position.x + size.x), (position.y + size.y), position.z);
		m_BufferPointer->color = s.color;
		m_BufferPointer++;

		m_BufferPointer->position = float3(position.x + size.x, position.y, position.z);
		m_BufferPointer->color = s.color;
		m_BufferPointer++;

		m_BufferPointer->position = position;
		m_BufferPointer->color = s.color;
		m_BufferPointer++;

		m_IndexCount += 6;
	}

	void Renderer2D::End()
	{
		m_VertexBuffer.Unmap();
	}

	void Renderer2D::Render()
	{
		m_VertexBuffer.Bind();
		m_IndexBuffer->Bind();

		RenderingAPI::ClearRenderTargetView(float4(1.0f, 1.0f, 1.0f, 1.0f));
		RenderingAPI::DrawIndexed(m_IndexCount);
		RenderingAPI::Present();

		m_IndexCount = 0;
	}

}