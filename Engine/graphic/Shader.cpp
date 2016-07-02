#include "Shader.h"

using namespace core;

namespace graphic
{	
	D3D11_INPUT_ELEMENT_DESC defaultLayout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 28, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "SLOT", 0, DXGI_FORMAT_R32_SINT, 0, 36, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	Shader::Shader()
	{
		HRESULT res = D3DReadFileToBlob(L"defaultVertexShader.cso", &m_VertexShaderBlob);

		if (FAILED(res))
		{
			Window::MessageBoxOk("Error", "Error during vertex shader loading");
			exit(1);
		}

		res = D3DReadFileToBlob(L"defaultPixelShader.cso", &m_PixelShaderBlob);

		if (FAILED(res))
		{
			Window::MessageBoxOk("Error", "Error during pixel shader loading");
			exit(1);
		}

		res = RenderingAPI::GetDevice()->CreateVertexShader(m_VertexShaderBlob->GetBufferPointer(), m_VertexShaderBlob->GetBufferSize(), nullptr, &m_VertexShader);
		if (FAILED(res))
		{
			Window::MessageBoxOk("Error", "Error during vertex shader creation");
			exit(1);
		}

		res = RenderingAPI::GetDevice()->CreatePixelShader(m_PixelShaderBlob->GetBufferPointer(), m_PixelShaderBlob->GetBufferSize(), nullptr, &m_PixelShader);
		if (FAILED(res))
		{
			Window::MessageBoxOk("Error", "Error during vertex shader creation");
			exit(1);
		}


		SetLayout(defaultLayout, ARRAYSIZE(defaultLayout));
	}

	Shader::~Shader()
	{
		m_Layout->Release();
		m_VertexShader->Release();
		m_VertexShaderBlob->Release();
		m_PixelShader->Release();
		m_PixelShaderBlob->Release();
	}


	void Shader::SetLayout(D3D11_INPUT_ELEMENT_DESC layout[], UINT elementCount)
	{
		if (m_Layout)
			m_Layout->Release();

		HRESULT res = RenderingAPI::GetDevice()->CreateInputLayout(layout, elementCount, m_VertexShaderBlob->GetBufferPointer(), m_VertexShaderBlob->GetBufferSize(), &m_Layout);

		if (FAILED(res))
		{
			Window::MessageBoxOk("Error", "Error during input layout creation");
			exit(1);
		}
	}

	void Shader::Bind()
	{
		RenderingAPI::GetContext()->IASetInputLayout(m_Layout);
		RenderingAPI::GetContext()->VSSetShader(m_VertexShader, NULL, 0);
		RenderingAPI::GetContext()->PSSetShader(m_PixelShader, NULL, 0);
	}

}