#pragma once
#include "Window.h"
#include "MinkiTimer.h"
class App
{
public:
	App();
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	MinkiTimer timer;
};

