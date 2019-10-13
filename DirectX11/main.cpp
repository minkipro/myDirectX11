#include "FrameWork.h"

void main()
{
	FrameWork* frameWork = new FrameWork();
	
	if (frameWork->Initialize())
	{
		frameWork->Run();
	}

	delete frameWork;

	return;
}