#include "Shader.h"
#include "myDefined.h"

Shader::Shader(ID3D11Device* device, HWND hwnd, LPCSTR shaderFileName, LPCSTR vertexFuncName, LPCSTR pixelFuncName)
{
	m_vertexShader = nullptr;
	m_pixelShader = nullptr;
	m_layout = nullptr;
	m_matrixBuffer = nullptr;
	m_initialized = Initialize(device, hwnd, shaderFileName, vertexFuncName, pixelFuncName);
}

Shader::~Shader()
{
	SAFE_RELEASE(m_layout);
	SAFE_RELEASE(m_pixelShader);
	SAFE_RELEASE(m_vertexShader);
	SAFE_ARRAY_DELETE(m_name);
}

bool Shader::Initialize(ID3D11Device* device, HWND hwnd, LPCSTR shaderFileName, LPCSTR vertexFuncName, LPCSTR pixelFuncName)
{
	m_name = new char[strlen(shaderFileName) + 1];
	memcpy(m_name, shaderFileName, strlen(shaderFileName) + 1);
	char vsFileName[100];
	strcpy_s(vsFileName, shaderFileName);
	strcat_s(vsFileName, ".vs");
	vsFileName[strlen(shaderFileName) + 4] = '\0';

	char psFileName[100];
	strcpy_s(psFileName, shaderFileName);
	strcat_s(psFileName, ".ps");
	psFileName[strlen(shaderFileName) + 4] = '\0';

	return InitializeShader(device, hwnd, vsFileName, psFileName, vertexFuncName, pixelFuncName);
}

void Shader::Begin(ID3D11DeviceContext* deviceContext, int indexCount)
{
	deviceContext->IASetInputLayout(m_layout);

	deviceContext->VSSetShader(m_vertexShader, NULL, 0);
	deviceContext->PSSetShader(m_pixelShader, NULL, 0);
	deviceContext->DrawIndexed(indexCount, 0, 0);
}

void Shader::End(ID3D11DeviceContext* deviceContext)
{
	deviceContext->IASetInputLayout(NULL);
	deviceContext->VSSetShader(NULL, NULL, 0);
	deviceContext->PSSetShader(NULL, NULL, 0);
}

bool Shader::InitializeShader(ID3D11Device* device, HWND hwnd, LPCSTR vsFileName, LPCSTR psFileName, LPCSTR vertexFuncName, LPCSTR pixelFuncName)
{
	HRESULT result;

	ID3D10Blob* errorMessage = nullptr;
	ID3D10Blob* vertexShaderBuffer;
	ID3D10Blob* pixelShaderBuffer;
	D3D11_INPUT_ELEMENT_DESC polygonLayout[2];
	unsigned int numElements;
	D3D11_BUFFER_DESC matrixBufferDesc;

	result = D3DX11CompileFromFile(vsFileName, NULL, NULL, vertexFuncName, "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, NULL,
									&vertexShaderBuffer, &errorMessage, NULL);
	if (FAILED(result))
	{
		if (errorMessage)
		{
			OutputShaderErrorMessage(errorMessage, hwnd, vsFileName);
		}
		else
		{
			MessageBox(hwnd, vsFileName, "Error in shader File", MB_OK);
		}

		return false;
	}

	result = D3DX11CompileFromFile(psFileName, NULL, NULL, pixelFuncName, "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, NULL,
									&pixelShaderBuffer, &errorMessage, NULL);
	if (FAILED(result))
	{
		if (errorMessage)
		{
			OutputShaderErrorMessage(errorMessage, hwnd, psFileName);
		}
		else
		{
			MessageBox(hwnd, psFileName, "Error in shader File", MB_OK);
		}

		return false;
	}

	result = device->CreateVertexShader(vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), NULL, &m_vertexShader);
	if (FAILED(result))
	{
		return false;
	}

	result = device->CreatePixelShader(pixelShaderBuffer->GetBufferPointer(), pixelShaderBuffer->GetBufferSize(), NULL, &m_pixelShader);
	if (FAILED(result))
	{
		return false;
	}

	polygonLayout[0] = { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 };
	polygonLayout[1] = { "TEXCORRD", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA , 0};
	
	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);

	result = device->CreateInputLayout(polygonLayout, numElements, vertexShaderBuffer->GetBufferPointer(),
										vertexShaderBuffer->GetBufferSize(), &m_layout);

	if (FAILED(result))
	{
		return false;
	}

	SAFE_RELEASE(vertexShaderBuffer);
	SAFE_RELEASE(pixelShaderBuffer);

	matrixBufferDesc = {sizeof(matrixBufferDesc), D3D11_USAGE_DYNAMIC, D3D11_BIND_CONSTANT_BUFFER, D3D11_CPU_ACCESS_WRITE, 0, 0};
	result = device->CreateBuffer(&matrixBufferDesc, NULL, &m_matrixBuffer);
	if (FAILED(result))
	{
		return false;
	}
	return true;
}

bool Shader::SetShaderParameters(ID3D11DeviceContext* deviceContext, ID3D11ShaderResourceView* texture)
{
	return false;
}

bool Shader::SetShaderParameters(ID3D11DeviceContext* deviceContext, D3DXMATRIX worldMatirx, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix)
{
	return false;
}

char* Shader::GetName()
{
	return nullptr;
}

bool Shader::IsInitialized()
{
	return false;
}





void Shader::OutputShaderErrorMessage(ID3D10Blob* errorMessage, HWND hwnd, LPCSTR shaderFileName)
{
}
