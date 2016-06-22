#include "Window.h"

LRESULT CALLBACK windowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

EXTERN_C IMAGE_DOS_HEADER __ImageBase;
bool* close;

std::string		  Window::m_WindowName;
HWND			  Window::m_WindowHandler;
HINSTANCE		  Window::m_ApplicationInstance;
HDC				  Window::m_DeviceContextHandler;
HGLRC			  Window::m_GLRenderContextHandler;
MSG	  			  Window::m_Message;

int  Window::m_Width, Window::m_Height;
bool Window::m_Closed;

void Window::Init(std::string windowName, int width, int height)
{
	m_WindowName = windowName;
	m_Width = width;
	m_Height = height;

	close = &m_Closed;
	m_Closed = false;

	m_ApplicationInstance = (HINSTANCE)&__ImageBase;
	WNDCLASSEX windowClass;
	ZeroMemory(&windowClass, sizeof(windowClass));

	windowClass.cbClsExtra = NULL;
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.cbWndExtra = NULL;
	windowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hIcon = NULL;
	windowClass.hIconSm = NULL;
	windowClass.hInstance = m_ApplicationInstance;
	windowClass.lpfnWndProc = (WNDPROC)windowProcedure;
	windowClass.lpszClassName = "Window Class";
	windowClass.lpszMenuName = NULL;
	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

	if (!RegisterClassEx(&windowClass))
	{
		MessageBox(m_WindowHandler, "Error during window creation", "Error", MB_OK);
		exit(1);
	}

	m_WindowHandler = CreateWindowEx(
		NULL,
		windowClass.lpszClassName,
		m_WindowName.c_str(),
		WS_OVERLAPPEDWINDOW,
		200, //posX
		200, //posY
		width,
		height,
		NULL,
		NULL,
		m_ApplicationInstance,
		NULL
	);

	if (!m_WindowHandler)
	{
		MessageBox(m_WindowHandler, "Error during window creation", "Error", MB_OK);
		exit(1);
	}

	ShowWindow(m_WindowHandler, 1);
	RenderingAPI::Init(width, height);
}

void Window::Update()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);

	TranslateMessage(&msg);
	DispatchMessage(&msg);
}

bool Window::Closed()
{
	return m_Closed;
}

LRESULT CALLBACK windowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
	
	}
	break;

	case WM_DESTROY:
	{
		*close = true;
		PostQuitMessage(0);
		return 0;
	}
	break;

	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}