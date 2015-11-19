
#include "TriangleSample.h"
#include "GLSlayer/RenderContextInit.h"
#include "Common/Utils.h"

using namespace std;
using namespace gls;
using namespace math3d;

#pragma pack(push, 1)
struct Vertex
{
	vec3f position;
	vec4f color;
};
#pragma pack(pop)


TriangleSample::TriangleSample()
	: _renderContext(nullptr)
	, _vertexShader(nullptr)
	, _fragmentShader(nullptr)
	, _vertexBuffer(nullptr)
	, _vertShaderUniforms(nullptr)
	, _vertFormat(nullptr)
{

}

TriangleSample::~TriangleSample()
{

}

#if defined (_WIN32)
bool TriangleSample::Init(HWND hwnd, HINSTANCE hinstance)
#elif defined (__linux__)
bool TriangleSample::Init(Display* display, Window window, const gls::FramebufferFormat& fbufFormat)
#endif
{
#if defined (_WIN32)
	FramebufferFormat fbufFormat;
	fbufFormat.colorBits = 32;
	fbufFormat.colorBufferType = gls::COLOR_BUFFER_TYPE_RGBA;
	fbufFormat.depthBits = 0;
	fbufFormat.stencilBits = 0;
	fbufFormat.doubleBuffer = true;
	fbufFormat.multisampleSamples = 0;
	fbufFormat.sRGB = false;
	fbufFormat.swapMethod = gls::SWAP_EXCHANGE;

	_renderContext = gls::CreateRenderContext(330, hinstance, hwnd, &fbufFormat, false, &_console);
#elif defined (__linux__)
	_renderContext = gls::CreateRenderContext(330, display, window, &fbufFormat, false, &_console);
#endif

	if(!_renderContext)
		return false;

	_renderContext->SetCurrentContext();
	_renderContext->CullFace(gls::FACE_BACK);
	_renderContext->FrontFace(gls::ORIENT_CCW);
	_renderContext->EnableFaceCulling(true);
	_renderContext->SwapInterval(1);
	_renderContext->EnableDepthTest(false);
	_renderContext->EnableDebugOutput(true, true);
	_renderContext->EnableDebugMessages(gls::DEBUG_SOURCE_ALL, gls::DEBUG_TYPE_ALL, gls::DEBUG_SEVERITY_ALL, true);

	// Create resources

	bool success;
	string source = LoadShaderSource("Shaders/Triangle/Simple.vert");
	if(source.empty())
	{
		_console.PrintLn("Failed to load vertex shader from file: Shaders/Triangle/Simple.vert");
		Deinit();
		return false;
	}
	const char* vs_sources[] = { source.c_str() };
	_vertexShader = _renderContext->CreateVertexShader(1, vs_sources, success);
	if(!success)
	{
		_console.PrintLn("Failed to compile vertex shader: Shaders/Triangle/Simple.vert\n%s", _vertexShader->GetInfoLog());
		Deinit();
		return false;
	}

	source = LoadShaderSource("Shaders/Triangle/Simple.frag");
	if(source.empty())
	{
		_console.PrintLn("Failed to load fragment shader from file: Shaders/Triangle/Simple.frag");
		Deinit();
		return false;
	}
	const char* fs_sources[] = { source.c_str() };
	_fragmentShader = _renderContext->CreateFragmentShader(1, fs_sources, success);
	if(!success)
	{
		_console.PrintLn("Failed to compile fragment shader: Shaders/Triangle/Simple.frag\n%s", _fragmentShader->GetInfoLog());
		Deinit();
		return false;
	}

	Vertex vertices[] = {
		{ vec3f(-1.0f, 1.0f, 0.0f), vec4f(1.0f, 0.0f, 0.0f, 1.0f), },
		{ vec3f(-1.0f, -1.0f, 0.0f), vec4f(0.0f, 1.0f, 0.0f, 1.0f), },
		{ vec3f(1.0f, 0.0f, 0.0f), vec4f(0.0f, 0.0f, 1.0f, 1.0f), },
	};
	_vertexBuffer = _renderContext->CreateBuffer(gls::VERTEX_BUFFER, sizeof(vertices), vertices, 0);

	_vertShaderUniforms = _renderContext->CreateBuffer(gls::UNIFORM_BUFFER, sizeof(mat4f), nullptr, BUFFER_DYNAMIC_STORAGE_BIT);

	VertexAttribDesc vert_desc[] = {
		{ 0, 0, 3, gls::TYPE_FLOAT, false, false, 0, 0 },
		{ 0, 1, 4, gls::TYPE_FLOAT, false, false, 12, 0 },
	};
	_vertFormat = _renderContext->CreateVertexFormat(2, vert_desc);

	return true;
}

void TriangleSample::Deinit()
{
	if(_renderContext)
	{
		_renderContext->DestroyShader(_vertexShader);
		_vertexShader = nullptr;
		_renderContext->DestroyShader(_fragmentShader);
		_fragmentShader = nullptr;
		_renderContext->DestroyBuffer(_vertexBuffer);
		_vertexBuffer = nullptr;
		_renderContext->DestroyBuffer(_vertShaderUniforms);
		_vertShaderUniforms = nullptr;
		_renderContext->DestroyVertexFormat(_vertFormat);
		_vertFormat = nullptr;

		gls::DestroyRenderContext(_renderContext);
		_renderContext = nullptr;
	}
}

void TriangleSample::Render(int frame_time)
{
	if(!_renderContext)
		return;

	_renderContext->ClearColorBuffer(nullptr, 0, vec4f(0.0f, 0.0f, 0.0f, 0.0f));
	_renderContext->VertexSource(0, _vertexBuffer, sizeof(Vertex), 0);
	_renderContext->ActiveVertexFormat(_vertFormat);
	_renderContext->SetVertexShader(_vertexShader);
	_renderContext->SetFragmentShader(_fragmentShader);
	_vertShaderUniforms->BufferSubData(0, sizeof(mat4f), _projMat);
	_renderContext->SetUniformBuffer(0, _vertShaderUniforms);
	_renderContext->Draw(gls::PRIM_TRIANGLES, 0, 3);
	_renderContext->SwapBuffers();
}

void TriangleSample::OnResize(int width, int height)
{
	if(!_renderContext)
		return;

	_projMat.ortho(-2.0f, 2.0f, -2.0f, 2.0f, 1.0f, -1.0f);
	_renderContext->Viewport(0, 0, width, height);
}
