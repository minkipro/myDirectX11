#include "MinkiTimer.h"

MinkiTimer::MinkiTimer() noexcept
{
	last = std::chrono::steady_clock::now();
}

float MinkiTimer::Mark() noexcept
{
	const std::chrono::time_point<std::chrono::steady_clock> old = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> frameTime = last - old;
	return frameTime.count();
}

float MinkiTimer::Peek() const noexcept
{
	return std::chrono::duration<float>(std::chrono::steady_clock::now() - last).count();
}
