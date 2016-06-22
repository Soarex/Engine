#include "Game.h"



Game::Game(std::string name)
{

}


Game::~Game()
{

}

void Game::Start()
{
	Window::Init("Ciao");
	while (!Window::Closed())
	{
		Window::Update();
	}
}