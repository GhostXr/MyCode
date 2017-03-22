#include "WinSoft3d.h"
#include <Windows.h>

int APIENTRY _tWinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hinstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	WinSoft3d *app = new WinSoft3d(hinstance);
	app->main(800, 800);

	return 0;
};