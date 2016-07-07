#include "Mouse.h"

namespace core{

	Mouse::Mouse(){
		m_Device = InputAPI::createDevice(GUID_SysMouse);
	}


	Mouse::~Mouse(){
	}

}
