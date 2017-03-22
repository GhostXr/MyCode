#pragma once
#include <Windows.h>
#include <tchar.h>

class CELLWinApp
{
public:
	CELLWinApp(HINSTANCE hinstance, LPWSTR lpwstr):_hInst(hinstance)
	{
		//注册窗口类
		WNDCLASS wndclass;
		memset(&wndclass, 0, sizeof(wndclass));
		//wndclass.cbSize = sizeof(wndclass);
		wndclass.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC;
		wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wndclass.hCursor = LoadCursor(_hInst, IDC_ARROW);
		 
		wndclass.lpszClassName = _T("CELLWinApp");
		wndclass.lpfnWndProc = wndproc;
		wndclass.hIcon = 0;
		wndclass.lpszMenuName = 0;
		
		RegisterClass(&wndclass);
	}

	~CELLWinApp(void)
	{
		UnregisterClass(_T("CELLWinApp"), _hInst);
	}

	static LRESULT CALLBACK wndproc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_CREATE:
			break;
		case WM_DESTROY:
		case WM_CLOSE:
			PostQuitMessage(0);
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
		while(GetMessage(&msg, 0, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		
		return 0;
	}
protected:
	HWND _hwnd;
	HINSTANCE _hInst;
};

