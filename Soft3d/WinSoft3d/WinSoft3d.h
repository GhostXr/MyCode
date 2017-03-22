#pragma once

#include <tchar.h>
#include <Windows.h>

#include "CELLMath.hpp"

using namespace std;

/*/static float3 g_cubeVertices[] = 
{
	float3(-1.0f, -1.0f, 1.0f),
	float3( 1.0f, -1.0f, 1.0f),
	float3( 1.0f,  1.0f, 1.0f),
	float3(-1.0f,  1.0f, 1.0f),

	float3(-1.0f, -1.0f, -1.0f),
	float3(-1.0f,  1.0f, -1.0f),
	float3( 1.0f,  1.0f, -1.0f),
	float3( 1.0f, -1.0f, -1.0f),
		
	float3(-1.0f,  1.0f, -1.0f),
	float3(-1.0f,  1.0f,  1.0f),
	float3( 1.0f,  1.0f,  1.0f),
	float3( 1.0f,  1.0f, -1.0f),
		
	float3(-1.0f, -1.0f, -1.0f),
	float3( 1.0f, -1.0f, -1.0f),
	float3( 1.0f, -1.0f,  1.0f),
	float3(-1.0f, -1.0f,  1.0f),
		
	float3( 1.0f, -1.0f, -1.0f),
	float3( 1.0f,  1.0f, -1.0f),
	float3( 1.0f,  1.0f,  1.0f),
	float3( 1.0f, -1.0f,  1.0f),
		
	float3(-1.0f, -1.0f, -1.0f),
	float3(-1.0f, -1.0f,  1.0f),
	float3(-1.0f,  1.0f,  1.0f),
	float3(-1.0f,  1.0f, -1.0f)
};/*/

class WinSoft3d
{
public:
	//实例句柄
	HINSTANCE _hInstance;
	//窗口句柄
	HWND _hWnd;
	//窗口高度
	int _width;
	//窗口宽度
	int _height;

public:
	WinSoft3d(HINSTANCE hInstance):_hInstance(hInstance)
	{
		WNDCLASSEX winClass;
		winClass.lpszClassName		= _T("WinSoft3d");
		winClass.cbSize				= sizeof(winClass);
		winClass.style				= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		winClass.lpfnWndProc		= wndProc;
		winClass.hInstance			= hInstance;
		winClass.hIcon				= 0;
		winClass.hIconSm			= 0;
		winClass.hCursor			= LoadCursor(hInstance, IDC_ARROW);
		winClass.hbrBackground		= (HBRUSH)GetStockObject(BLACK_BRUSH);
		winClass.lpszMenuName		= NULL;
		winClass.cbClsExtra			= 0;
		winClass.cbWndExtra			= 0;

		RegisterClassEx(&winClass);
	}
	virtual ~WinSoft3d()
	{
		UnregisterClass(_T("WinSoft3d"), _hInstance);
	}
protected:
	static LRESULT CALLBACK wndProc(HWND _hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		WinSoft3d* pThis = (WinSoft3d*)GetWindowLong(_hWnd, GWL_USERDATA);
		if (pThis)
		{
			return pThis->onEvent(_hWnd, message, wParam, lParam);
		}
		if (WM_CREATE == message)
		{
			CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
			SetWindowLong(_hWnd, GWL_USERDATA, (DWORD_PTR)pCreate->lpCreateParams);
		}
		return DefWindowProc(_hWnd, message, wParam, lParam);
	}
	virtual LRESULT onEvent(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch(message)
		{
		case WM_CLOSE:
		case WM_DESTROY:
			{
				::PostQuitMessage(0);
			}
		case WM_MOUSEMOVE:
			break;
		case WM_LBUTTONUP:
			break;
		case WM_LBUTTONDOWN:
			break;
		case WM_RBUTTONUP:
			break;
		case WM_RBUTTONDOWN:
			break;
		case WM_KEYDOWN:
			switch (wParam)
			{
			case VK_LEFT:
				break;
			default:
				break;
			}
			break;
		case WM_KEYUP:
		default:
			return DefWindowProc(hwnd, message, wParam, lParam);
		}
		return S_OK;
	}

public:
	int main(int width, int height)
	{
		_hWnd = CreateWindowEx(NULL, _T("WinSoft3d"), _T("WinSoft3d"), WS_OVERLAPPEDWINDOW, 
			CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, _hInstance, this);

		if(_hWnd == 0)
		{
			return -1;
		}
		ShowWindow(_hWnd, SW_SHOW);

		MSG message = {0};
		while(message.message != NULL)
		{
			if (message.message == WM_DESTROY || message.message == WM_CLOSE)
			{
				break;
			}

			if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
			else
			{
				Sleep(1);
			}
		}
		return 0;
	}
};

