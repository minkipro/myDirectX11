#include "Engine.h"
#include "myDefined.h"
Engine* Engine::m_instance = nullptr;

Engine::Engine()
{
	m_graphics = nullptr;
}

Engine::~Engine()
{
	SAFE_DELETE(m_graphics);
}

bool Engine::InitializeGraphics(HWND hwnd)
{
	m_graphics = new Graphics();
	return m_graphics->InitializeDX(hwnd);
}

bool Engine::Initialize(HINSTANCE hinstance, HWND hwnd)
{
	m_graphics->Initialize();

	return true;
}

void Engine::Run()
{
	Update();
	Render();
}

void Engine::Update()
{
}

void Engine::Render()
{
	m_graphics->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	m_graphics->EndScene();
}

Graphics* Engine::GetGraphics()
{
	return m_graphics;
}

Engine* Engine::GetEngine()
{
	if (m_instance == nullptr)
	{
		m_instance = new Engine;
	}

	return m_instance;
}

void Engine::Release()
{
	SAFE_DELETE(m_instance);
}