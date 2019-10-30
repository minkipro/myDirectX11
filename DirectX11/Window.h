#pragma once
#include "MinkiWin.h"
#include "MinkiException.h"


class Window
{
public:
	class Exception : public MinkiException
	{
	public:
		Exception(int line, const char* file, HRESULT hr);
		const char* what() const noexcept override;
		virtual const char* GetType() const noexcept;
		static string TranslateErrorCode(HRESULT hr) noexcept;
		HRESULT GetErrorCode() const noexcept;
		string GetErrorString() const noexcept;
	private:
		HRESULT _hr;
	};
private:
	class WindowClass
	{
	public:
		static const char* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass( const WindowClass& ) = delete;
		WindowClass& operator=( const WindowClass& ) = delete;
		static constexpr const char* wndClassName = "Chili Direct3D Engine Window";
		static WindowClass wndClass;
		HINSTANCE hInst;
	};
public:
	Window( int width,int height,const char* name );
	~Window();
	Window( const Window& ) = delete;
	Window& operator=( const Window& ) = delete;
private:
	static LRESULT CALLBACK HandleMsgSetup( HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam ) noexcept;
	static LRESULT CALLBACK HandleMsgThunk( HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam ) noexcept;
	LRESULT HandleMsg( HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam ) noexcept;
private:
	int width;
	int height;
	HWND hWnd;
};

#define MKWND_EXCEPT(hr) Window::Exception( __LINE__, __FILE__, hr)
#define MKWND_LAST_EXCEPT() Window::Exception( __LINE__, __FILE__, GetLastError())