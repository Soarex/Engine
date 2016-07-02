#pragma once
#include <d3d11.h>
#include <string>
#include "..\core\RenderingAPI.h"
#include "..\dependecies\DDSTextureLoader\DDSTextureLoader.h"

namespace graphic
{
	class Texture
	{
	private:
		ID3D11ShaderResourceView*	 m_ResourceView;
		ID3D11Texture2D*			 m_Texture;
	public:
		Texture(std::wstring pathname);
		~Texture();
		void Bind(UINT slot);
	};
}
