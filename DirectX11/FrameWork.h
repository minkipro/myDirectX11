#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

class FrameWork
{
public:
	FrameWork();
	~FrameWork();

	bool Initialize();
	void Run();

private:
	bool CreateDXWindow(const char* windowTitle, int x, int y, int width, int height);

	const char* m_applicationName;
	HINSTANCE m_hInstance;
};

