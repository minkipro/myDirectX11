#pragma once

#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN

#define SAFE_RELEASE(p) {if(p){(p)->Release(); (p)=NULL;}}
#define SAFE_DELETE(p) { if (p) { delete (p); (p)=NULL; } }
#define SAFE_ARRAY_DELETE(p) { if (p) { delete[] (p); (p)=NULL; } }

#include <windows.h>
//
//#include <d3d11.h>
//#include <d3dx11.h>
//#include <D3DX10math.h>
//#include <d3dcompiler.h>
