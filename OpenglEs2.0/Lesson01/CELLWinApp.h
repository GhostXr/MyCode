#pragma once
#include <Windows.h>
#include <tchar.h>

class CELLWinApp
{
public:
	CELLWinApp(HINSTANCE hinstance, LPWSTR lpwstr):_hInst(hinstance)
	{
		//注册窗口类
		WNDCLASSEX wndclass;
		memset(&wndclass, 0, sizeof(wndclass));
		//wndclass.cbSize = sizeof(wndclass);
		wndclass.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC;
		wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wndclass.hCursor = LoadCursor(_hInst, IDC_ARROW);

		wndclass.lpszClassName = _T("CELLWinApp");
		wndclass.lpfnWndProc = wndproc;
		wndclass.hIcon = 0;
		wndclass.lpszMenuName = 0;
		
		RegisterClassEx(&wndclass);
	}

	~CELLWinApp(void)
	{
		UnregisterClass(_T("CELLWinApp"), _hInst);
	}

public:
	static LRESULT CALLBACK wndproc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		CELLWinApp* pThis = (CELLWinApp*)GetWindowLong(hwnd, GWL_USERDATA);
		if (pThis)
		{
			return pThis->onEvent(hwnd, msg, wParam, lParam);
		}
		if (WM_CREATE == msg)
		{
			CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
			SetWindowLong(hwnd, GWL_USERDATA, (DWORD_PTR)pCreate->lpCreateParams);
		}
	}
public:
	int onEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{ 
		switch (msg)
		{
		case WM_CREATE:
			break;
		case WM_CLOSE:
		case WM_DESTROY:
			{
				PostQuitMessage(0);
			}
			break;
		case WM_MOUSEMOVE:
			break;
		case WM_LBUTTONDOWN:
			break;
		case WM_LBUTTONUP:
			break;
		case WM_RBUTTONDOWN:
			break;
		case WM_RBUTTONUP:
			break;
		case WM_KEYDOWN:
			{
				switch(wParam)
				{
				case VK_LEFT:
					break;
				default:
					break;
				}
			}
		case WM_KEYUP:
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
		}
		return S_OK;
	}

	int main(int width, int height)
	{
		//创建窗口
		_hwnd = CreateWindow(_T("CELLWinApp"), _T("CELLWinApp"), WS_OVERLAPPEDWINDOW, 0, 0, width, height, 0, 0, _hInst, this);


		//更新窗口
		if (_hwnd == 0) 
		{
			return 0;
		}
		UpdateWindow(_hwnd);
		
		//显示窗口
		ShowWindow(_hwnd, SW_SHOW);

		//消息循环
		MSG msg = {0};
		while(msg.message != WM_QUIT)
		{
			if (msg.message == WM_DESTROY || msg.message == WM_CLOSE)
			{
				break;
			}
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				Sleep(1);
			}
		}
		
		return 0;
	}
protected:
	HWND _hwnd;
	HINSTANCE _hInst;
};

