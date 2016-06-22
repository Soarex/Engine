#pragma once
#include <d3d11.h>
#include "Window.h"

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
private:
	static void InitRenderTargetView();
};

