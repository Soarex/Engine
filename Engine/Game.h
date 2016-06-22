#pragma once
#include "Window.h"
#include "RenderingAPI.h"
#include <string>

class Game
{
protected:

public:
	Game(std::string name);
	~Game();
	void Start();
};

