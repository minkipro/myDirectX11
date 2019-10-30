#pragma once
#include <exception>
#include <string>
using namespace std;
class MinkiException : public exception
{
public:
	MinkiException(int line, const char* file) noexcept;
	const char* what() const noexcept override;
	virtual const char* GetType() const noexcept;
	int GetLine() const noexcept;
	const string& GetFile() const noexcept;
	string GetOriginString() const noexcept;
private:
	int _line;
	string _file;
protected:
	mutable string whatBuffer;
};

