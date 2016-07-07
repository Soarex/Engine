#pragma once
#include "InputAPI.h"

namespace core{
	class Keyboard{
	private:
		LPDIRECTINPUTDEVICE8 m_Device;
	public:
		Keyboard();
		~Keyboard();
	};
}