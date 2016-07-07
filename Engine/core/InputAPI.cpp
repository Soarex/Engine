#include "InputAPI.h"

namespace core{
	LPDIRECTINPUT8 InputAPI::m_Input;

	void InputAPI::init(){
		HRESULT res = DirectInput8Create(Window::getApplicationInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)m_Input, NULL);

		if (FAILED(res)){
			Window::messageBoxOk("Error", "Error during InputAPI init");
			exit(1);
		}
	}

	LPDIRECTINPUTDEVICE8 InputAPI::createDevice(GUID type){
		LPDIRECTINPUTDEVICE8 temp;
		HRESULT res = m_Input->CreateDevice(type, &temp, NULL);

		if (FAILED(res)){
			Window::messageBoxOk("Error", "Error during input device creation");
			exit(1);
		}

		return temp;
	}
}