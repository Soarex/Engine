#pragma once
#include <d3d11.h>
#include "Window.h"
#include "../math/float4.h"

namespace core
{
	enum Topology
	{
		POINTLIST		= D3D11_PRIMITIVE_TOPOLOGY_POINTLIST,
		LINELIST		= D3D11_PRIMITIVE_TOPOLOGY_LINELIST,
		LINESTRIP		= D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP,
		TRIANGLELIST	= D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
		TRIANGLESTRIP	= D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST
	};

	class RenderingAPI
	{
	private:
		static D3D_DRIVER_TYPE			m_DriverType;
		static D3D_FEATURE_LEVEL		m_FeatureLevel;
		static ID3D11Device*			m_Device;
		static ID3D11DeviceContext*		m_Context;
		static IDXGISwapChain*			m_SwapChain;
		static ID3D11RenderTargetView*	m_RenderTargetView;

	public:
		static void Init(int width, int height);
		static void SetViewport(int width, int height);
		static void SetPrimitiveTopology(Topology t);
		static inline ID3D11DeviceContext* GetContext() { return m_Context; }
		static inline ID3D11Device* GetDevice() { return m_Device; }
		static inline void ClearRenderTargetView(math::float4 color) { FLOAT a[] = { color.x, color.y, color.z, color.w };  m_Context->ClearRenderTargetView(m_RenderTargetView, a); }
		static inline void Present() { m_SwapChain->Present(0, 0); }
		static inline void Draw(int numVertices, int startingIndex = 0) { m_Context->Draw(numVertices, startingIndex); }
		static inline void DrawIndexed(int numIndices, int startingIndex = 0, int baseVertex = 0) { m_Context->DrawIndexed(numIndices, startingIndex, baseVertex); }
	private:
		static void InitRenderTargetView();
	};

}