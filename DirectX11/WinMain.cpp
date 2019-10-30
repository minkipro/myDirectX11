#include "MinkiWin.h"
#include "Window.h"

int CALLBACK WinMain(	_In_		HINSTANCE	hInstance,
						_In_opt_	HINSTANCE	hPrevInstance,
						_In_		LPSTR		lpCmdLine,
						_In_		int			nCmdShow)
{
	try
	{
		Window wnd(800, 300, "Donkey Fart Box");
		Window wnd2(200, 650, "Donkey Fart Box2");

		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (gResult == -1)
		{
			return -1;
		}
		return msg.wParam;
	}
	catch (const MinkiException & e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const exception & e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
}