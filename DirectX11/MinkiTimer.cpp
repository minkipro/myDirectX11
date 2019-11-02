#include "MinkiTimer.h"

MinkiTimer::MinkiTimer()
{
	last = steady_clock::now();
}

float MinkiTimer::Mark()
{
	const time_point<steady_clock> old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float MinkiTimer::Peek() const
{
	return duration<float>(steady_clock::now() - last).count();
}
