#include "Keyboard.h"

namespace core{

	Keyboard::Keyboard(){
		m_Device = InputAPI::createDevice(GUID_SysKeyboard);
	}


	Keyboard::~Keyboard(){
	}

}