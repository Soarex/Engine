#include "RenderingAPI.h"
#include <stdio.h>

using namespace math;

namespace core
{
	D3D_FEATURE_LEVEL featureLevels[] = {
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};

	D3D_DRIVER_TYPE			RenderingAPI::m_DriverType;
	D3D_FEATURE_LEVEL		RenderingAPI::m_FeatureLevel;
	ID3D11Device*			RenderingAPI::m_Device;
	ID3D11DeviceContext*	RenderingAPI::m_Context;
	IDXGISwapChain*			RenderingAPI::m_SwapChain;
	ID3D11RenderTargetView*	RenderingAPI::m_RenderTargetView;

	void RenderingAPI::initRenderTargetView() {
		ID3D11Texture2D* backBuffer;
		HRESULT res = m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);

		if (FAILED(res)){
			MessageBox(Window::getWindowHandler(), "Error during render target view creation", "Error", MB_OK);
			exit(1);
		}

		res = m_Device->CreateRenderTargetView(backBuffer, NULL, &m_RenderTargetView);

		if (FAILED(res)){
			MessageBox(Window::getWindowHandler(), "Error during render target view creation", "Error", MB_OK);
			exit(1);
		}

		backBuffer->Release();

		m_Context->OMSetRenderTargets(1, &m_RenderTargetView, NULL);

	}

	void RenderingAPI::init(int width, int height) {
		DXGI_SWAP_CHAIN_DESC sd;
		ZeroMemory(&sd, sizeof(sd));
		sd.BufferCount = 1;
		sd.BufferDesc.Width = width;
		sd.BufferDesc.Height = height;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.OutputWindow = Window::getWindowHandler();
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.Windowed = TRUE;

		HRESULT res = D3D11CreateDeviceAndSwapChain(
			NULL,
			D3D_DRIVER_TYPE_HARDWARE,
			NULL,
			0,
			featureLevels,
			ARRAYSIZE(featureLevels),
			D3D11_SDK_VERSION,
			&sd,
			&m_SwapChain,
			&m_Device,
			&m_FeatureLevel,
			&m_Context
		);

		if (FAILED(res)) {
			MessageBox(Window::getWindowHandler(), "Error during swap chain creation", "Error", MB_OK);
			exit(1);
		}


		initRenderTargetView();
		setViewport(width, height);

		float ClearColor[4] = { 0.0f, 0.125f, 0.6f, 1.0f };
		m_Context->ClearRenderTargetView(m_RenderTargetView, ClearColor);

		m_SwapChain->Present(0, 0);
	}

	void RenderingAPI::setViewport(int width, int height) {
		D3D11_VIEWPORT vp;
		vp.Width = (FLOAT)width;
		vp.Height = (FLOAT)height;
		vp.MinDepth = 0.0f;
		vp.MaxDepth = 1.0f;
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		m_Context->RSSetViewports(1, &vp);
	}

	void RenderingAPI::setPrimitiveTopology(Topology t) {
		m_Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY(t));
	}
}