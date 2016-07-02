#pragma once
#include "core/core.h"
#include "graphic/graphic.h"
#include <string>

class Game
{
protected:
	std::string m_Name;
public:
	Game(std::string name);
	~Game();
	void Start();
	void Run();
};

