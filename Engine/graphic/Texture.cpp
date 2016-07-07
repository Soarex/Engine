#include "Texture.h"

using namespace std;
using namespace core;
using namespace DirectX;

namespace graphic {

	Texture::Texture(wstring pathname) {
		ID3D11Resource* tex;
		CreateDDSTextureFromFile(RenderingAPI::getDevice(), pathname.c_str(), &tex, &m_ResourceView);
		m_Texture = (ID3D11Texture2D*)tex;
	}

	Texture::~Texture() {
		m_ResourceView->Release();
		m_Texture->Release();
	}

	void Texture::bind(UINT slot) {
		RenderingAPI::getContext()->PSSetShaderResources(slot, 1, &m_ResourceView);
	}

}