#pragma once
#include <unordered_map>
#include "MinkiWin.h"
class WindowsMessageMap
{
public:
	WindowsMessageMap() noexcept;
	std::string operator()(DWORD msg, WPARAM wp, LPARAM lp) const noexcept;

private:
	std::unordered_map<DWORD, std::string> map;
};

