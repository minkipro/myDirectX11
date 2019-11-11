#pragma once
#include "Window.h"
#include "MinkiTimer.h"
class App
{
public:
	App();
	int Go();
	~App();
private:
	void DoFrame();
private:
	Window wnd;
	MinkiTimer timer;
	std::vector<std::unique_ptr<class Box>> boxes;
};

