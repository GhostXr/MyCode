#pragma once
#include <Windows.h>
#include <tchar.h>

class CELLWinApp
{
public:
	CELLWinApp(HINSTANCE hinstance, LPWSTR lpwstr):_hInst(hinstance)
	{
		//ע�ᴰ����
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
		//��������
		_hwnd = CreateWindow(_T("CELLWinApp"), _T("CELLWinApp"), WS_OVERLAPPEDWINDOW, 0, 0, width, height, 0, 0, _hInst, this);


		//���´���
		if (_hwnd == 0) 
		{
			return 0;
		}
		UpdateWindow(_hwnd);
		
		//��ʾ����
		ShowWindow(_hwnd, SW_SHOW);

		//��Ϣѭ��
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

