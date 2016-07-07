#pragma once
#include <string>
#include <sstream>
#include <d3d11.h>
#include <D3Dcompiler.h>
#include "../core/core.h"

namespace graphic {

	class Shader {
	private:
		ID3DBlob*			 m_VertexShaderBlob;
		ID3DBlob*			 m_PixelShaderBlob;
		ID3D11InputLayout*	 m_Layout;

		ID3D11VertexShader*	 m_VertexShader;
		ID3D11PixelShader*	 m_PixelShader;
	public:
		Shader();
		~Shader();

		void setLayout(D3D11_INPUT_ELEMENT_DESC layout[], UINT elementCount);
		void bind();
	};

}