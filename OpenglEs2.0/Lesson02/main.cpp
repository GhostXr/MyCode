#include <tchar.h>
#include <Windows.h>

#include "CELLWinApp.h"

int CALLBACK _tWinMain(HINSTANCE hinstance, HINSTANCE hPrevInst, LPTSTR lpCmdline, int nShowCmd)
{
	CELLWinApp app(hinstance, lpCmdline);

	app.main(500, 500);
	return 0;
}