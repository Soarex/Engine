#pragma once
#include "InputAPI.h"

namespace core {

	class Mouse {
	private:
		LPDIRECTINPUTDEVICE8 m_Device;
	public:
		Mouse();
		~Mouse();
	};
}