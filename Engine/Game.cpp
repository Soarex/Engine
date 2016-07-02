#include "Game.h"


using namespace core;
using namespace graphic;
using namespace math;


Game::Game(std::string name) : m_Name(name)
{

}


Game::~Game()
{

}

void Game::Start()
{
	Window::Init(m_Name);
	while (!Window::Closed())
	{
		Window::Update();
		Run();
	}
}

void Game::Run()
{
	Shader sh;
	sh.Bind();
	Renderer2D re;
	Sprite s(float3(0.0f, 0.0f, 1.0f), float2(0.5f, 0.5f), new Texture(L"textures\\tex1.dds"));
	Sprite s1(float3(0.5f, 0.5f, 1.0f), float2(0.5f, 0.5f), new Texture(L"textures\\tex2.dds"));
	re.Begin();
	re.Submit(s);
	re.Submit(s1);
	re.End();
	re.Render();

	Sleep(16);
}