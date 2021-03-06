#include "Renderer2D.h"

using namespace core;
using namespace math;

namespace graphic {

	Renderer2D::Renderer2D() : m_VertexBuffer(RENDERER_BUFFER_SIZE, D3D11_USAGE_DYNAMIC, D3D11_CPU_ACCESS_WRITE, sizeof(VertexData)) {
		m_IndexCount = 0;

		UINT* indices = new UINT[RENDERER_INDICES_SIZE];
		int offset = 0;
		for (int i = 0; i < RENDERER_INDICES_SIZE; i += 6) {
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
		RenderingAPI::setPrimitiveTopology(TRIANGLELIST);
	}


	Renderer2D::~Renderer2D() {
		delete m_IndexBuffer;
	}

	void Renderer2D::begin() {
		m_BufferPointer = m_VertexBuffer.map<VertexData*>();
	}

	void Renderer2D::submit(Sprite& s) {
		float3& position = s.position;
		float2& size = s.size;
		int slot;

		if (s.texture != nullptr)
			slot = submitTexture(s.texture);
		else
			slot = -1;

		m_BufferPointer->position = float3(position.x, (position.y + size.y), position.z);
		m_BufferPointer->color = s.color;
		m_BufferPointer->uv = float2(0.0f, 1.0f);
		m_BufferPointer->textureSlot = slot;
		m_BufferPointer++;

		m_BufferPointer->position = float3((position.x + size.x), (position.y + size.y), position.z);
		m_BufferPointer->color = s.color;
		m_BufferPointer->uv = float2(1.0f, 1.0f);
		m_BufferPointer->textureSlot = slot;
		m_BufferPointer++;

		m_BufferPointer->position = float3(position.x + size.x, position.y, position.z);
		m_BufferPointer->color = s.color;
		m_BufferPointer->uv = float2(1.0f, 0.0f);
		m_BufferPointer->textureSlot = slot;
		m_BufferPointer++;

		m_BufferPointer->position = position;
		m_BufferPointer->color = s.color;
		m_BufferPointer->uv = float2(0.0f, 0.0f);
		m_BufferPointer->textureSlot = slot;
		m_BufferPointer++;

		m_IndexCount += 6;
	}

	int Renderer2D::submitTexture(Texture* texture) {
		int result = 0;
		bool found = false;
		for (int i = 0; i < m_Textures.size(); i++) {
			if (m_Textures[i] == texture) {
				result = i;
				found = true;
				break;
			}
		}

		if (!found) {
			if (m_Textures.size() >= RENDERER_MAX_TEXTURES) {
				end();
				render();
				begin();
			}
			m_Textures.push_back(texture);
			result = m_Textures.size() - 1;
		}
		return result;
	}

	void Renderer2D::end() {
		m_VertexBuffer.unmap();
	}

	void Renderer2D::render() {
		m_VertexBuffer.bind();
		m_IndexBuffer->bind();

		for (int i = 0; i < m_Textures.size(); i++)
			m_Textures[i]->bind(i);

		RenderingAPI::clearRenderTargetView(float4(1.0f, 1.0f, 1.0f, 1.0f));
		RenderingAPI::drawIndexed(m_IndexCount);
		RenderingAPI::present();

		m_IndexCount = 0;
	}

}