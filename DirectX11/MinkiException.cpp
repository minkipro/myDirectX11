#include "MinkiException.h"
#include <sstream>

MinkiException::MinkiException(int line, const char* file) noexcept
	:
	_line(line),
	_file(file)
{
}

const char* MinkiException::what() const noexcept
{
	ostringstream oss;
	oss << GetType() << endl;
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* MinkiException::GetType() const noexcept
{
	return "Minki Exception";
}

int MinkiException::GetLine() const noexcept
{
	return _line;
}

const string& MinkiException::GetFile() const noexcept
{
	return _file;
}

string MinkiException::GetOriginString() const noexcept
{
	ostringstream oss;
	oss << "[File] " << _file << endl
		<< "[Line] " << _line;
	return oss.str();
}
