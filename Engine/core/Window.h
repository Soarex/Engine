#pragma once
#include <Windows.h>
#include <string>
#include "RenderingAPI.h"

namespace core
{

	class Window
	{
	private:
		static std::string		 m_WindowName;
		static HWND				 m_WindowHandler;
		static HINSTANCE		 m_ApplicationInstance;
		static HDC				 m_DeviceContextHandler;
		static HGLRC			 m_GLRenderContextHandler;
		static MSG	  			 m_Message;

		static int m_Width, m_Height;
		static bool m_Closed;
	public:
		static void Init(std::string windowName, int width = 800, int height = 600);
		static void Update();
		static bool Closed();
		static void MessageBoxOk(std::string name, std::string content);
		static inline int GetWidth() { return m_Width; }
		static inline int GetHeight() { return m_Height; }
		static inline HWND GetWindowHandler() { return m_WindowHandler; }
	};

}