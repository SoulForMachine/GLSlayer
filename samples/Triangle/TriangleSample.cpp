
#include "TriangleSample.h"
#include "GLSlayer/RenderContextInit.h"
#include "Common/Utils.h"

using namespace math3d;

#pragma pack(push, 1)
struct Vertex
{
	vec3f position;
	vec4f color;
};
#pragma pack(pop)


TriangleSample::~TriangleSample()
{
	Deinit();
}

bool TriangleSample::Init(gls::CreateContextInfo& info)
{
	info.version = 330;
	info.debugContext = false;
	info.logger = &_console;

	_renderContext = gls::CreateRenderContext(info);

	if(!_renderContext)
		return false;

	_renderContext->SetCurrentContext();
	_renderContext->CullFace(gls::PolygonFace::Back);
	_renderContext->FrontFace(gls::VertexWinding::Counterclockwise);
	_renderContext->EnableFaceCulling(true);
	_renderContext->SwapInterval(1);
	_renderContext->EnableDepthTest(false);
	_renderContext->EnableDebugOutput(true, true);
	_renderContext->EnableDebugMessages(gls::DebugMessageSource::All, gls::DebugMessageType::All, gls::DebugMessageSeverity::All, true);

	// Create resources

	bool success;
	std::string source = LoadShaderSource("Shaders/Triangle/Simple.vert");
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
	_vertexBuffer = _renderContext->CreateBuffer(sizeof(vertices), vertices, 0);

	_vertShaderUniforms = _renderContext->CreateBuffer(sizeof(mat4f), nullptr, gls::BUFFER_DYNAMIC_STORAGE_BIT);

	gls::VertexAttribDesc vert_desc[] = {
		{ 0, 0, 3, gls::DataType::Float, false, false, offsetof(Vertex, position) },
		{ 0, 1, 4, gls::DataType::Float, false, false, offsetof(Vertex, color) },
	};
	_vertFormat = _renderContext->CreateVertexFormat(vert_desc, CountOf(vert_desc));

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

void TriangleSample::GetFramebufferFormat(gls::FramebufferFormat& fbufFormat)
{
	fbufFormat.colorBits = 32;
	fbufFormat.colorBufferType = gls::ColorBufferType::RGBA;
	fbufFormat.depthBits = 0;
	fbufFormat.stencilBits = 0;
	fbufFormat.doubleBuffer = true;
	fbufFormat.multisampleSamples = 0;
	fbufFormat.sRGB = false;
	fbufFormat.swapMethod = gls::SwapMethod::Exchange;
}

void TriangleSample::Render(float frame_time)
{
	if(!_renderContext)
		return;

	_renderContext->ClearColorBuffer(nullptr, 0, vec4f(0.0f, 0.0f, 0.0f, 0.0f));
	_renderContext->VertexSource(0, _vertexBuffer, sizeof(Vertex), 0, 0);
	_renderContext->ActiveVertexFormat(_vertFormat);
	_renderContext->SetVertexShader(_vertexShader);
	_renderContext->SetFragmentShader(_fragmentShader);
	_vertShaderUniforms->BufferSubData(0, sizeof(mat4f), _projMat);
	_renderContext->SetUniformBuffer(0, _vertShaderUniforms);
	_renderContext->Draw(gls::PrimitiveType::Triangles, 0, 3);
	_renderContext->SwapBuffers();
}

void TriangleSample::OnResize(int width, int height)
{
	if(!_renderContext)
		return;

	_projMat.ortho(-2.0f, 2.0f, -2.0f, 2.0f, 1.0f, -1.0f);
	_renderContext->Viewport(0, 0, width, height);
}
