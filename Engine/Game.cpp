#include "Game.h"


using namespace core;
using namespace graphic;
using namespace math;


Game::Game(std::string name) : m_Name(name) {

}


Game::~Game() {

}

void Game::start() {
	Window::init(m_Name);
	while (!Window::closed()) {
		Window::update();
		run();
	}
}

void Game::run() {
	Shader sh;
	sh.bind();
	Renderer2D re;
	Sprite s(float3(0.0f, 0.0f, 1.0f), float2(0.5f, 0.5f), new Texture(L"textures\\tex1.dds"));
	Sprite s1(float3(0.5f, 0.5f, 1.0f), float2(0.5f, 0.5f), new Texture(L"textures\\tex2.dds"));
	re.begin();
	re.submit(s);
	re.submit(s1);
	re.end();
	re.render();

	Sleep(16);
}