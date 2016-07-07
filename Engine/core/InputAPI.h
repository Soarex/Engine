#pragma once
#include <dinput.h>
#include "Window.h"

namespace core{
	class InputAPI{
	private:
		static LPDIRECTINPUT8 m_Input;
	public:
		static void init();
		static LPDIRECTINPUTDEVICE8 createDevice(GUID type);
	};
}