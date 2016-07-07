#pragma once
#include <d3d11.h>
#include "Window.h"
#include "../math/float4.h"

namespace core{

	enum Topology{
		POINTLIST		= D3D11_PRIMITIVE_TOPOLOGY_POINTLIST,
		LINELIST		= D3D11_PRIMITIVE_TOPOLOGY_LINELIST,
		LINESTRIP		= D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP,
		TRIANGLELIST	= D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
		TRIANGLESTRIP	= D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST
	};

	class RenderingAPI{
	private:
		static D3D_DRIVER_TYPE			m_DriverType;
		static D3D_FEATURE_LEVEL		m_FeatureLevel;
		static ID3D11Device*			m_Device;
		static ID3D11DeviceContext*		m_Context;
		static IDXGISwapChain*			m_SwapChain;
		static ID3D11RenderTargetView*	m_RenderTargetView;

	public:
		static void init(int width, int height);
		static void setViewport(int width, int height);
		static void setPrimitiveTopology(Topology t);
		static inline ID3D11DeviceContext* getContext() { return m_Context; }
		static inline ID3D11Device* getDevice() { return m_Device; }
		static inline void clearRenderTargetView(math::float4 color) { FLOAT a[] = { color.x, color.y, color.z, color.w };  m_Context->ClearRenderTargetView(m_RenderTargetView, a); }
		static inline void present() { m_SwapChain->Present(0, 0); }
		static inline void draw(int numVertices, int startingIndex = 0) { m_Context->Draw(numVertices, startingIndex); }
		static inline void drawIndexed(int numIndices, int startingIndex = 0, int baseVertex = 0) { m_Context->DrawIndexed(numIndices, startingIndex, baseVertex); }
	private:
		static void initRenderTargetView();
	};

}