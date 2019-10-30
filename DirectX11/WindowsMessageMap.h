#pragma once
#include <unordered_map>
#include <Windows.h>
using namespace std;
class WindowsMessageMap
{
public:
	WindowsMessageMap() noexcept;
	string operator()(DWORD msg, WPARAM wp, LPARAM lp) const noexcept;

private:
	unordered_map<DWORD, string> map;
};

