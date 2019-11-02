#pragma once
#include <chrono>
using namespace std;
using namespace chrono;

class MinkiTimer
{
public:
	MinkiTimer();
	float Mark();
	float Peek() const;
private:
	steady_clock::time_point last;
};

