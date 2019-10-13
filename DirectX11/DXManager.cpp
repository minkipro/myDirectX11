#include "DXManager.h"
#include "myDefined.h"
DXManager::DXManager()
{
	m_swapChain = nullptr;
	m_device = nullptr;
	m_deviceContext = nullptr;
	m_renderTargetView = nullptr;
	m_depthStencilBuffer = nullptr;
	m_depthStencilState = nullptr;
	m_depthStencilView = nullptr;
	m_rasterState = nullptr;
	m_alphaEnableBlendingState = nullptr;
	m_alphaDisabledBlendingState = nullptr;
	m_depthDisabledStencilState = nullptr;
}

DXManager::~DXManager()
{
	if (m_swapChain)
	{
		m_swapChain->SetFullscreenState(false, NULL);
	}

	
	SAFE_RELEASE(m_alphaEnableBlendingState);
	SAFE_RELEASE(m_alphaDisabledBlendingState);
	SAFE_RELEASE(m_depthDisabledStencilState);
	SAFE_RELEASE(m_rasterState);
	SAFE_RELEASE(m_depthStencilView);
	SAFE_RELEASE(m_depthStencilState);
	SAFE_RELEASE(m_depthStencilBuffer);
	SAFE_RELEASE(m_renderTargetView);
	SAFE_RELEASE(m_deviceContext);
	SAFE_RELEASE(m_device);
	SAFE_RELEASE(m_swapChain);
}

bool DXManager::Initialize(int screenWidth, int screenHeight, bool vsync, HWND hwnd, bool fullscreen)
{
	HRESULT result;
	IDXGIFactory* factory;
	IDXGIAdapter* adapter;
	IDXGIOutput* adapterOutput;
	unsigned int numModes, i, numerator, denominator, stringLength;
	DXGI_MODE_DESC* displayModeList;
	DXGI_ADAPTER_DESC adapterDesc;
	int error;
	ID3D11Texture2D* backBufferPtr;

	m_vsync_enabled = vsync; 

	result = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);
	if (FAILED(result))
	{
		return false;
	}

	result = factory->EnumAdapters(0, &adapter);
	if (FAILED(result))
	{
		return false;
	}

	

	return true;
}

void DXManager::BeginScene(float r, float g, float b, float a)
{
}

void DXManager::EndScene()
{
}

void DXManager::EnableAlphaBlending(bool enable)
{
}

void DXManager::EnableZBuffer(bool enable)
{
}

ID3D11Device* DXManager::GetDevice()
{
	return nullptr;
}

ID3D11DeviceContext* DXManager::GetDeviceContext()
{
	return nullptr;
}

bool DXManager::InitializeSwapChain(HWND hwnd, bool fullscreen, int screenWidth, int screenHeight, unsigned int numerator, unsigned int denominator)
{
	return false;
}

bool DXManager::InitializeDepthBuffer(int screenWidth, int screenHeight)
{
	return false;
}

bool DXManager::InitializeDepthStencilBuffer()
{
	return false;
}

bool DXManager::InitializeStencilView()
{
	return false;
}

bool DXManager::InitializeResterizerState()
{
	return false;
}

bool DXManager::InitializeViewport(int screenWidth, int screenHeight)
{
	return false;
}

bool DXManager::InitializeAlphaBlending()
{
	return false;
}

bool DXManager::InitializeZBuffer()
{
	return false;
}
