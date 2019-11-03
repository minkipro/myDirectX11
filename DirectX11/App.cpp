#include "App.h"
#include <sstream>
#include <iomanip>

App::App()
	:wnd(800, 600, "The Donkey Fart Box")
{
}

int App::Go()
{
	while (true)
	{
	
		if (const auto ecode = Window::ProcessMessages())
		{
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	wnd.Gfx().EndFrame();
}
