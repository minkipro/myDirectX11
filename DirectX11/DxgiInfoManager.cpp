#include "DxgiInfoManager.h"
#include "Window.h"
#include "Graphics.h"
#include <memory>
#include <dxgidebug.h>
#include "GraphicsThrowMacros.h"
#include "WindowsThrowMacros.h"

#pragma comment(lib, "dxguid.lib")


#define GFX_THROW_NOINFO(hrcall) if( FAILED( hr = (hrcall) ) ) throw Graphics::HrException( __LINE__,__FILE__,hr )

DxgiInfoManager::DxgiInfoManager()
{
	typedef HRESULT (WINAPI* DXGIGetDebugInterface)(REFIID, void**);

	const auto hModDxgiDebug = LoadLibraryEx("dxgidebug.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
	if (hModDxgiDebug == nullptr)
	{
		throw MKWND_LAST_EXCEPT();
	}

	// get address of DXGIGetDebugInterface in dll
	const auto DxgiGetDebugInterface = reinterpret_cast<DXGIGetDebugInterface>(
		reinterpret_cast<void*>(GetProcAddress(hModDxgiDebug, "DXGIGetDebugInterface"))
		);
	if (DxgiGetDebugInterface == nullptr)
	{
		throw MKWND_LAST_EXCEPT();
	}

	HRESULT hr;
	GFX_THROW_NOINFO(DxgiGetDebugInterface(__uuidof(IDXGIInfoQueue), &pDxgiInfoQueue));
}

void DxgiInfoManager::Set() noexcept
{
	next = pDxgiInfoQueue->GetNumStoredMessages(DXGI_DEBUG_ALL);
}

std::vector<std::string> DxgiInfoManager::GetMessages() const
{
	std::vector<std::string> messages;
	/*const auto end = pDxgiInfoQueue->GetNumStoredMessages(DXGI_DEBUG_ALL);
	for (auto i = next; i < end; i++)
	{
		HRESULT hr;
		SIZE_T MessageLength = 0;
		GFX_THROW_NOINFO(pDxgiInfoQueue->GetMessageA(DXGI_DEBUG_ALL, i, nullptr, &MessageLength));
		auto bytes = std::make_unique<byte[]>(MessageLength);
		auto pMessage = reinterpret_cast<DXGI_INFO_QUEUE_MESSAGE*>(bytes.get());
		GFX_THROW_NOINFO(pDxgiInfoQueue->GetMessageA(DXGI_DEBUG_ALL, i, pMessage, &MessageLength));
		messages.emplace_back(pMessage->pDescription);
	}*/
	return messages;
}
