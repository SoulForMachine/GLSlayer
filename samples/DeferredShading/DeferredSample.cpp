
#include "DeferredSample.h"
#include <cassert>
#include <string>
#include <ctime>
#include "GLSlayer/RenderContextInit.h"
#include "Common/ObjLoader.h"
#include "Common/Utils.h"

using namespace std;
using namespace gls;
using namespace math3d;


const int MAX_LIGHTS = 64;


#pragma pack(push, 1)
struct SSRectVertex
{
	vec2f position;
	vec2f uv;
};

struct GBufferTransformData
{
	mat4f wvpMatrix;
	mat4f worldMatrix;
};

struct GBufferFragData
{
	vec4f color;
};

struct VSScreenSpaceData
{
	vec4f viewport;
};
#pragma pack(pop)


DeferredSample::DeferredSample()
{
	_renderContext = nullptr;
	_gbuffer = nullptr;
	_texDiffuse = nullptr;
	_texNormal = nullptr;
	_texPosition = nullptr;
	_depthBuffer = nullptr;
	_sceneBuffer = nullptr;
	_texSceneColor = nullptr;
	_lightMatrixTex = nullptr;
	_lightMatrixBuf = nullptr;
	_lightInfoTex = nullptr;
	_lightInfoBuf = nullptr;
	_vertShaderGbuffer = nullptr;
	_fragShaderGBuffer = nullptr;
	_vertShaderScreenSpace = nullptr;
	_fragShaderSimpleTex = nullptr;
	_vertShaderLight = nullptr;
	_fragShaderLight = nullptr;
	_vertexFormat = nullptr;
	_vertFmtScreenRect = nullptr;
	_vertFmtSphere = nullptr;
	_vertexBuffer = nullptr;
	_indexBuffer = nullptr;
	_ubufVertShaderGBuffer = nullptr;
	_ubufFragShaderGBuffer = nullptr;
	_ubufVertShaderSSpace = nullptr;
	_ubufFragShaderLighting = nullptr;
	_rectVertBuf = nullptr;
	_sphereVertBuf = nullptr;
	_sphereIndexBuf = nullptr;
	_samplerGBuffer = nullptr;
	_samplerLight = nullptr;
	_query = nullptr;
	_frameTime = 0.0f;
	_rotX = 0.0f;
	_rotY = 0.0f;
	_showGBuffer = false;
	_swapInterval = 1;
}

bool DeferredSample::Init(CreateContextInfo& info)
{
	info.version = 330;
	info.debugContext = false;
	info.logger = &_console;

	_renderContext = CreateRenderContext(info);

	if(!_renderContext)
		return false;

	_renderContext->SetCurrentContext();
	_renderContext->CullFace(FACE_BACK);
	_renderContext->FrontFace(ORIENT_CCW);
	_renderContext->EnableFaceCulling(true);
	_renderContext->SwapInterval(_swapInterval);
	_renderContext->EnableDebugOutput(true, true);
	_renderContext->EnableDebugMessages(DEBUG_SOURCE_ALL, DEBUG_TYPE_ALL, DEBUG_SEVERITY_ALL, true);

	// create shaders

	string source = LoadShaderSource("Shaders/DeferredShading/GBuffer.vert");
	if(source.empty())
	{
		_console.PrintLn("Failed to load vertex shader from file: Shaders/DeferredShading/GBuffer.vert");
		Deinit();
		return false;
	}
	const char* sources[] = { source.c_str() };
	bool success;
	_vertShaderGbuffer = _renderContext->CreateVertexShader(1, sources, success);
	if(_vertShaderGbuffer->GetInfoLogLength() > 1)
	{
		_console.PrintLn("Failed to compile vertex shader: Shaders/DeferredShading/GBuffer.vert\n%s", _vertShaderGbuffer->GetInfoLog());
	}

	if(!success)
	{
		Deinit();
		return false;
	}

	source = LoadShaderSource("Shaders/DeferredShading/GBuffer.frag");
	if(source.empty())
	{
		_console.PrintLn("Failed to load fragment shader from file: Shaders/DeferredShading/GBuffer.frag");
		Deinit();
		return false;
	}
	sources[0] = source.c_str();
	_fragShaderGBuffer = _renderContext->CreateFragmentShader(1, sources, success);
	if(_fragShaderGBuffer->GetInfoLogLength() > 1)
	{
		_console.PrintLn("Failed to compile fragment shader: Shaders/DeferredShading/GBuffer.frag\n%s", _fragShaderGBuffer->GetInfoLog());
	}

	if(!success)
	{
		Deinit();
		return false;
	}

	source = LoadShaderSource("Shaders/DeferredShading/ScreenSpace.vert");
	if(source.empty())
	{
		_console.PrintLn("Failed to load vertex shader from file: Shaders/DeferredShading/ScreenSpace.vert");
		Deinit();
		return false;
	}
	sources[0] = source.c_str();
	_vertShaderScreenSpace = _renderContext->CreateVertexShader(1, sources, success);
	if(_vertShaderScreenSpace->GetInfoLogLength() > 1)
	{
		_console.PrintLn("Failed to compile vertex shader: Shaders/DeferredShading/ScreenSpace.vert\n%s", _vertShaderScreenSpace->GetInfoLog());
	}

	if(!success)
	{
		Deinit();
		return false;
	}

	source = LoadShaderSource("Shaders/DeferredShading/SimpleTexture.frag");
	if(source.empty())
	{
		_console.PrintLn("Failed to load fragment shader from file: Shaders/DeferredShading/SimpleTexture.frag");
		Deinit();
		return false;
	}
	sources[0] = source.c_str();
	_fragShaderSimpleTex = _renderContext->CreateFragmentShader(1, sources, success);
	if(_fragShaderSimpleTex->GetInfoLogLength() > 1)
	{
		_console.PrintLn("Failed to compile fragment shader: Shaders/DeferredShading/SimpleTexture.frag\n%s", _fragShaderSimpleTex->GetInfoLog());
	}

	if(!success)
	{
		Deinit();
		return false;
	}

	// lighting sphere shaders

	source = LoadShaderSource("Shaders/DeferredShading/Lighting.vert");
	if(source.empty())
	{
		_console.PrintLn("Failed to load vertex shader from file: Shaders/DeferredShading/Lighting.vert");
		Deinit();
		return false;
	}
	sources[0] = source.c_str();
	_vertShaderLight = _renderContext->CreateVertexShader(1, sources, success);
	if(_vertShaderLight->GetInfoLogLength() > 1)
	{
		_console.PrintLn("Failed to compile vertex shader: Shaders/DeferredShading/Lighting.vert\n%s", _vertShaderLight->GetInfoLog());
	}

	if(!success)
	{
		Deinit();
		return false;
	}

	source = LoadShaderSource("Shaders/DeferredShading/Lighting.frag");
	if(source.empty())
	{
		_console.PrintLn("Failed to load fragment shader from file: Shaders/DeferredShading/Lighting.frag");
		Deinit();
		return false;
	}
	sources[0] = source.c_str();
	_fragShaderLight= _renderContext->CreateFragmentShader(1, sources, success);
	if(_fragShaderLight->GetInfoLogLength() > 1)
	{
		_console.PrintLn("Failed to compile fragment shader: Shaders/DeferredShading/Lighting.frag\n%s", _fragShaderLight->GetInfoLog());
	}

	if(!success)
	{
		Deinit();
		return false;
	}

	// model vertex and index buffers

	ObjLoader ldr;
	if(!ldr.Load("Models/skull.obj"))
	{
		Deinit();
		_console.PrintLn("Error: failed to load 3D model.");
		return false;
	}

	_vertexBuffer = _renderContext->CreateBuffer(ldr.GetVertexCount() * 2 * 3 * 4, ldr.GetVertices(), 0);

	_indexBuffer = _renderContext->CreateBuffer(ldr.GetIndexCount() * 2, ldr.GetIndices(), 0);

	_skullIndexCount = ldr.GetIndexCount();
	ldr.GetBounds(_modelBoundsMin, _modelBoundsMax);
	ldr.Unload();

	// Lights

	_lightBoundsMin = _modelBoundsMin - (_modelBoundsMax - _modelBoundsMin) * 0.3f;
	_lightBoundsMax = _modelBoundsMax + (_modelBoundsMax - _modelBoundsMin) * 0.3f;
	CreateRandomLights(MAX_LIGHTS, _lightBoundsMin, _lightBoundsMax);

	_lightMatrixBuf = _renderContext->CreateBuffer(MAX_LIGHTS * sizeof(mat4f), 0, BUFFER_DYNAMIC_STORAGE_BIT);
	_lightMatrixTex = _renderContext->CreateTextureBuffer();
	_lightMatrixTex->TexBuffer(PIXEL_FORMAT_RGBA32F, _lightMatrixBuf);

	_lightInfoBuf = _renderContext->CreateBuffer(MAX_LIGHTS * sizeof(vec4f) * 2, 0, BUFFER_DYNAMIC_STORAGE_BIT);
	_lightInfoTex = _renderContext->CreateTextureBuffer();
	_lightInfoTex->TexBuffer(PIXEL_FORMAT_RGBA32F, _lightInfoBuf);

	CreateSphere(1.0f, 16, 16);

	// vertex formats

	VertexAttribDesc vert_desc[] =
	{
		{ 0, 0, 3, TYPE_FLOAT, false, false, 0 },
		{ 0, 1, 3, TYPE_FLOAT, false, false, 12 },
	};
	_vertexFormat = _renderContext->CreateVertexFormat(sizeof(vert_desc) / sizeof(*vert_desc), vert_desc);

	VertexAttribDesc rect_vert_desc[] =
	{
		{ 0, 0, 2, TYPE_FLOAT, false, false, 0 },
		{ 0, 1, 2, TYPE_FLOAT, false, false, 8 },
	};
	_vertFmtScreenRect = _renderContext->CreateVertexFormat(sizeof(rect_vert_desc) / sizeof(*rect_vert_desc), rect_vert_desc);

	// uniform buffers

	_ubufVertShaderGBuffer = _renderContext->CreateBuffer(sizeof(GBufferTransformData), nullptr, BUFFER_DYNAMIC_STORAGE_BIT);
	_ubufFragShaderGBuffer = _renderContext->CreateBuffer(sizeof(GBufferFragData), nullptr, BUFFER_DYNAMIC_STORAGE_BIT);

	_ubufVertShaderSSpace = _renderContext->CreateBuffer(sizeof(VSScreenSpaceData), nullptr, BUFFER_DYNAMIC_STORAGE_BIT);
	_ubufFragShaderLighting = _renderContext->CreateBuffer(sizeof(vec4f), nullptr, BUFFER_DYNAMIC_STORAGE_BIT);

	_rectVertBuf = _renderContext->CreateBuffer(2 * 2 * 6 * sizeof(SSRectVertex), nullptr, BUFFER_DYNAMIC_STORAGE_BIT);

	// samplers

	SamplerStateDesc sampler_gbuf_desc;
	sampler_gbuf_desc.addressU = TEX_ADDRESS_CLAMP_TO_EDGE;
	sampler_gbuf_desc.addressV = TEX_ADDRESS_CLAMP_TO_EDGE;
	sampler_gbuf_desc.minFilter = TEX_FILTER_LINEAR;
	sampler_gbuf_desc.magFilter = TEX_FILTER_LINEAR;

	_samplerGBuffer = _renderContext->CreateSamplerState(sampler_gbuf_desc);

	SamplerStateDesc sampler_light_desc;
	sampler_light_desc.addressU = TEX_ADDRESS_CLAMP_TO_EDGE;
	sampler_light_desc.addressV = TEX_ADDRESS_CLAMP_TO_EDGE;
	sampler_light_desc.minFilter = TEX_FILTER_NEAREST;
	sampler_light_desc.magFilter = TEX_FILTER_NEAREST;

	_samplerLight = _renderContext->CreateSamplerState(sampler_light_desc);

	_query = _renderContext->CreateQuery();

	return true;
}

void DeferredSample::Deinit()
{
	if(_renderContext)
	{
		DestroySphere();
		DestroyFramebuffers();

		_renderContext->DestroyTexture(_lightMatrixTex);
		_renderContext->DestroyBuffer(_lightMatrixBuf);
		_renderContext->DestroyTexture(_lightInfoTex);
		_renderContext->DestroyBuffer(_lightInfoBuf);
		_renderContext->DestroyShader(_vertShaderGbuffer);
		_renderContext->DestroyShader(_fragShaderGBuffer);
		_renderContext->DestroyShader(_vertShaderScreenSpace);
		_renderContext->DestroyShader(_fragShaderSimpleTex);
		_renderContext->DestroyShader(_vertShaderLight);
		_renderContext->DestroyShader(_fragShaderLight);
		_renderContext->DestroyVertexFormat(_vertexFormat);
		_renderContext->DestroyVertexFormat(_vertFmtScreenRect);
		_renderContext->DestroyBuffer(_vertexBuffer);
		_renderContext->DestroyBuffer(_indexBuffer);
		_renderContext->DestroyBuffer(_rectVertBuf);
		_renderContext->DestroyBuffer(_ubufVertShaderGBuffer);
		_renderContext->DestroyBuffer(_ubufFragShaderGBuffer);
		_renderContext->DestroyBuffer(_ubufVertShaderSSpace);
		_renderContext->DestroyBuffer(_ubufFragShaderLighting);
		_renderContext->DestroySamplerState(_samplerGBuffer);
		_renderContext->DestroySamplerState(_samplerLight);
		_renderContext->DestroyQuery(_query);

		DestroyRenderContext(_renderContext);
		_renderContext = nullptr;
	}
}

void DeferredSample::GetFramebufferFormat(gls::FramebufferFormat& fbufFormat)
{
	fbufFormat.colorBits = 32;
	fbufFormat.colorBufferType = COLOR_BUFFER_TYPE_RGBA;
	fbufFormat.depthBits = 24;
	fbufFormat.stencilBits = 0;
	fbufFormat.doubleBuffer = true;
	fbufFormat.multisampleSamples = 0;
	fbufFormat.sRGB = false;
	fbufFormat.swapMethod = SWAP_EXCHANGE;
}

void DeferredSample::CreateFramebuffers(int width, int height)
{
	DestroyFramebuffers();

	_texPosition = _renderContext->CreateTexture2D(1, PIXEL_FORMAT_RGBA32F, width, height);

	_texNormal = _renderContext->CreateTexture2D(1, PIXEL_FORMAT_RGBA16F, width, height);

	_texDiffuse = _renderContext->CreateTexture2D(1, PIXEL_FORMAT_RGBA8, width, height);

	_depthBuffer = _renderContext->CreateTexture2D(1, PIXEL_FORMAT_DEPTH24_STENCIL8, width, height);

	_gbuffer = _renderContext->CreateFramebuffer();
	_gbuffer->AttachTexture(ATTACH_BUFFER_COLOR0, _texPosition, 0);
	_gbuffer->AttachTexture(ATTACH_BUFFER_COLOR1, _texNormal, 0);
	_gbuffer->AttachTexture(ATTACH_BUFFER_COLOR2, _texDiffuse, 0);
	_gbuffer->AttachTexture(ATTACH_BUFFER_DEPTH_STENCIL, _depthBuffer, 0);
	FramebufferStatus status = _gbuffer->CheckStatus();
	assert(status == FBUF_STATUS_COMPLETE);

	ColorBuffer buffers[] = { COLOR_BUFFER_COLOR0, COLOR_BUFFER_COLOR1, COLOR_BUFFER_COLOR2 };
	_renderContext->ActiveColorBuffers(_gbuffer, 3, buffers);

	_sceneBuffer = _renderContext->CreateFramebuffer();
	_texSceneColor = _renderContext->CreateTexture2D(1, PIXEL_FORMAT_RGBA8, width, height);
	_sceneBuffer->AttachTexture(ATTACH_BUFFER_COLOR0, _texSceneColor, 0);
	_sceneBuffer->AttachTexture(ATTACH_BUFFER_DEPTH_STENCIL, _depthBuffer, 0);
	status = _sceneBuffer->CheckStatus();
	assert(status == FBUF_STATUS_COMPLETE);

	buffers[0] = COLOR_BUFFER_COLOR0;
	_renderContext->ActiveColorBuffers(_sceneBuffer, 1, buffers);
}

void DeferredSample::DestroyFramebuffers()
{
	if(_gbuffer)
	{
		_renderContext->DestroyFramebuffer(_gbuffer);
		_gbuffer = nullptr;
	}

	if(_depthBuffer)
	{
		_renderContext->DestroyTexture(_depthBuffer);
		_depthBuffer = nullptr;
	}

	if(_texPosition)
	{
		_renderContext->DestroyTexture(_texPosition);
		_texPosition = nullptr;
	}

	if(_texNormal)
	{
		_renderContext->DestroyTexture(_texNormal);
		_texNormal = nullptr;
	}

	if(_texDiffuse)
	{
		_renderContext->DestroyTexture(_texDiffuse);
		_texDiffuse = nullptr;
	}

	if(_sceneBuffer)
	{
		_renderContext->DestroyFramebuffer(_sceneBuffer);
		_sceneBuffer = nullptr;
	}

	if(_texSceneColor)
	{
		_renderContext->DestroyTexture(_texSceneColor);
		_texSceneColor = nullptr;
	}
}

void DeferredSample::RenderGeometryPass()
{
	mat4f wvp;
	math3d::mul(wvp, _worldMat, _viewProjMat);

	GBufferTransformData transf;
	transf.wvpMatrix = wvp;
	transf.worldMatrix = _worldMat;
	_ubufVertShaderGBuffer->BufferSubData(0, sizeof(GBufferTransformData), &transf);

	GBufferFragData frag_data;
	frag_data.color.set(1.0f, 1.0f, 1.0f, 1.0f);
	_ubufFragShaderGBuffer->BufferSubData(0, sizeof(GBufferFragData), &frag_data);

	_renderContext->SetUniformBuffer(0, _ubufVertShaderGBuffer);
	_renderContext->SetUniformBuffer(1, _ubufFragShaderGBuffer);
	_renderContext->SetVertexShader(_vertShaderGbuffer);
	_renderContext->SetFragmentShader(_fragShaderGBuffer);
	_renderContext->ActiveVertexFormat(_vertexFormat);
	_renderContext->VertexSource(0, _vertexBuffer, sizeof(ObjLoader::ObjVertex), 0);
	_renderContext->IndexSource(_indexBuffer, TYPE_UNSIGNED_SHORT);

	_renderContext->SetFramebuffer(_gbuffer);
	_renderContext->ClearColorBuffer(_gbuffer, 0, vec4f(-10000.0f, -10000.0f, -10000.0f, 1.0f));
	_renderContext->ClearColorBuffer(_gbuffer, 1, vec4f(0.0f, 0.0f, 0.0f, 0.0f));
	_renderContext->ClearColorBuffer(_gbuffer, 2, vec4f(0.0f, 0.0f, 0.0f, 1.0f));
	_renderContext->ClearDepthStencilBuffer(_gbuffer, 1.0f, 0);

	_renderContext->EnableDepthTest(true);

	_renderContext->DrawIndexed(PRIM_TRIANGLES, 0, 0, _skullIndexCount);

	_renderContext->EnableDepthTest(false);

	_renderContext->SetFramebuffer(0);
}

void DeferredSample::RenderLightingPass()
{
	UpdateLights();

	// update light matrix buffer
	mat4f world_mat;
	mat4f light_matrices[MAX_LIGHTS];
	for(size_t i = 0; i < _lights.size(); ++i)
	{
		world_mat.set_scale(_lights[i].radius);
		world_mat.transl_vec.rvec3 = _lights[i].position;
		mul(light_matrices[i], world_mat, _viewProjMat);
	}
	_lightMatrixBuf->BufferSubData(0, _lights.size() * sizeof(mat4f), light_matrices);

	// update light info buffer
#pragma pack(push, 1)
	struct LightInfo 
	{
		vec4f positionRadius;
		vec4f color;
	};
#pragma pack(pop)

	LightInfo light_info[MAX_LIGHTS];
	for(size_t i = 0; i < _lights.size(); ++i)
	{
		light_info[i].positionRadius.set(_lights[i].position, _lights[i].radius);
		light_info[i].color.set(_lights[i].color, 1.0f);
	}
	_lightInfoBuf->BufferSubData(0, _lights.size() * sizeof(LightInfo), light_info);

	vec4f viewport(0.0f, 00.0f, (float)_width, (float)_height);
	//_renderContext->GetViewport(viewport);
	_ubufFragShaderLighting->BufferSubData(0, sizeof(vec4f), viewport);
	_renderContext->SetUniformBuffer(0, _ubufFragShaderLighting);
	_renderContext->SetVertexShader(_vertShaderLight);
	_renderContext->SetFragmentShader(_fragShaderLight);
	_renderContext->ActiveVertexFormat(_vertFmtSphere);
	_renderContext->VertexSource(0, _sphereVertBuf, sizeof(vec3f), 0);
	_renderContext->IndexSource(_sphereIndexBuf, TYPE_UNSIGNED_SHORT);

	_renderContext->SetSamplerState(0, 0);
	_renderContext->SetSamplerState(1, 0);
	_renderContext->SetSamplerState(2, _samplerLight);
	_renderContext->SetSamplerState(3, _samplerLight);
	_renderContext->SetSamplerState(4, _samplerLight);

	_renderContext->SetSamplerTexture(0, _lightMatrixTex);
	_renderContext->SetSamplerTexture(1, _lightInfoTex);
	_renderContext->SetSamplerTexture(2, _texDiffuse);
	_renderContext->SetSamplerTexture(3, _texPosition);
	_renderContext->SetSamplerTexture(4, _texNormal);

	_renderContext->EnableBlending(true);
	_renderContext->BlendingFunc(BLEND_FUNC_ONE, BLEND_FUNC_ONE);

	_renderContext->EnableDepthTest(true);
	_renderContext->EnableDepthWrite(false);
	_renderContext->EnableDepthClamp(true);

	_renderContext->SetFramebuffer(_sceneBuffer);
	_renderContext->ClearColorBuffer(_sceneBuffer, 0, vec4f(0.0f, 0.0f, 0.0f, 0.0f));

	_query->BeginQuery(QUERY_SAMPLES_PASSED);
	_renderContext->DrawIndexedInstanced(PRIM_TRIANGLES, 0, 0, _sphereIndexCount, 0, static_cast<sizei>(_lights.size()));
	_query->EndQuery();
	uint samples = _query->GetResultUI();
	//_console.Print("samples - %d       \r", samples);

	_renderContext->SetFramebuffer(0);

	_renderContext->EnableDepthTest(false);
	_renderContext->EnableDepthWrite(true);
	_renderContext->EnableDepthClamp(false);
	_renderContext->EnableBlending(false);
}

void DeferredSample::RenderGBuffer()
{
	VSScreenSpaceData vsData;
	_renderContext->GetViewport(vsData.viewport);

	_ubufVertShaderSSpace->BufferSubData(0, sizeof(VSScreenSpaceData), &vsData);
	_renderContext->SetUniformBuffer(0, _ubufVertShaderSSpace);
	_renderContext->SetVertexShader(_vertShaderScreenSpace);
	_renderContext->SetFragmentShader(_fragShaderSimpleTex);
	_renderContext->ActiveVertexFormat(_vertFmtScreenRect);
	_renderContext->VertexSource(0, _rectVertBuf, sizeof(SSRectVertex), 0);

	float x1 = vsData.viewport.x;
	float y1 = vsData.viewport.y;
	const int rows = 2, cols = 2;
	float width = vsData.viewport.z / cols;
	float height = vsData.viewport.w / rows;
	SSRectVertex vertices[rows * cols * 6];
	for(int r = 0; r < rows; ++r)
	{
		for(int c = 0; c < cols; ++c)
		{
			int index = (r * cols + c) * 6;
			vertices[index + 0].position.set(x1 + c * width, y1 + r * height);
			vertices[index + 0].uv.set(0.0f, 0.0f);
			vertices[index + 1].position.set(x1 + c * width + width, y1 + r * height);
			vertices[index + 1].uv.set(1.0f, 0.0f);
			vertices[index + 2].position.set(x1 + c * width + width, y1 + r * height + height);
			vertices[index + 2].uv.set(1.0f, 1.0f);
			vertices[index + 3].position.set(x1 + c * width, y1 + r * height);
			vertices[index + 3].uv.set(0.0f, 0.0f);
			vertices[index + 4].position.set(x1 + c * width + width, y1 + r * height + height);
			vertices[index + 4].uv.set(1.0f, 1.0f);
			vertices[index + 5].position.set(x1 + c * width, y1 + r * height + height);
			vertices[index + 5].uv.set(0.0f, 1.0f);
		}
	}
	_rectVertBuf->BufferSubData(0, sizeof(SSRectVertex) * rows * cols * 6, vertices);

	_renderContext->SetSamplerState(0, _samplerGBuffer);

	_renderContext->ClearColorBuffer(0, 0, vec4f(0.1f, 0.3f, 0.3f, 1.0f));

	_renderContext->SetSamplerTexture(0, _texDiffuse);
	_renderContext->Draw(PRIM_TRIANGLES, 0, 6);

	_renderContext->SetSamplerTexture(0, _texPosition);
	_renderContext->Draw(PRIM_TRIANGLES, 6, 6);

	_renderContext->SetSamplerTexture(0, _texNormal);
	_renderContext->Draw(PRIM_TRIANGLES, 12, 6);

	_renderContext->SetSamplerTexture(0, _depthBuffer);
	_renderContext->Draw(PRIM_TRIANGLES, 18, 6);
}

void DeferredSample::Render(int frame_time)
{
	if(!_renderContext)
		return;

	_frameTime = frame_time * 0.001f;

	Update(frame_time);

	RenderGeometryPass();

	if(_showGBuffer)
	{
		RenderGBuffer();
	}
	else
	{
		RenderLightingPass();
		ColorBuffer buffer = COLOR_BUFFER_BACK_LEFT;
		_renderContext->ActiveColorBuffers(nullptr, 1, &buffer);
		_renderContext->BlitFramebuffer(_sceneBuffer, COLOR_BUFFER_COLOR0, 0, 0, _width, _height, nullptr, 0, 0, _width, _height, COLOR_BUFFER_BIT, TEX_FILTER_NEAREST);
	}

	_renderContext->SwapBuffers();
}

void DeferredSample::OnResize( int width, int height )
{
	if(!height)
		return;

	CreateFramebuffers(width, height);
	_renderContext->ViewportIndexed(0, 0.0, 0.0, (float)width, (float)height);
	_renderContext->ViewportIndexed(1, 0.0, 0.0, (float)width, (float)height);
	_renderContext->ViewportIndexed(2, 0.0, 0.0, (float)width, (float)height);
	_projMat.perspective(math3d::PI / 2.0f, float(width) / height, 1.0f, 1000.0f);
	_width = width;
	_height = height;
}

void DeferredSample::OnKeyDown(int key)
{
	if(key == '\t')
	{
		_showGBuffer = !_showGBuffer;
	}
	else if(key == 'V')
	{
		_swapInterval = (_swapInterval + 1) & 1;
		_renderContext->SwapInterval(_swapInterval);
	}
}

void DeferredSample::OnMouseDrag(int dx, int dy)
{
	const float MOUSE_SPEED = 0.015f;

	_rotX += dy * MOUSE_SPEED;
	_rotY += dx * MOUSE_SPEED;

	if(_rotX > 360.0f)
		_rotX -= 360.0f;

	if(_rotY > 360.0f)
		_rotY -= 360.0f;
}

void DeferredSample::CreateRandomLights(int count, const vec3f& min_pt, const vec3f& max_pt)
{
	_lights.resize(count);
	srand((unsigned int)time(0));
	for(int i = 0; i < count; ++i)
	{
		PointLight& light = _lights[i];

		light.position.x = lerp(min_pt.x, max_pt.x, float(rand()) / RAND_MAX);
		light.position.y = lerp(min_pt.y, max_pt.y, float(rand()) / RAND_MAX);
		light.position.z = lerp(min_pt.z, max_pt.z, float(rand()) / RAND_MAX);

		light.dir.x = float(rand()) / RAND_MAX;
		light.dir.y = float(rand()) / RAND_MAX;
		light.dir.z = float(rand()) / RAND_MAX;
		light.dir.normalize();

		light.color.r = float(rand()) / RAND_MAX;
		light.color.g = float(rand()) / RAND_MAX;
		light.color.b = float(rand()) / RAND_MAX;

		vec3f bounds = max_pt - min_pt;
		float min_dim = min(min(bounds.x, bounds.y), bounds.z);
		light.radius = lerp(min_dim / 4.0f, min_dim / 2.0f, float(rand()) / RAND_MAX);
	}
}

void DeferredSample::CreateSphere(float radius, int slices, int stacks)
{
	if(slices < 4)
		slices = 4;
	if(stacks < 4)
		stacks = 4;

	int vert_per_row = slices + 1;

	_sphereVertCount = vert_per_row * (stacks - 1) + 2 * slices;
	int num_tris = slices * 2 * (stacks - 1);
	_sphereIndexCount = num_tris * 3;

	_sphereVertBuf = _renderContext->CreateBuffer(_sphereVertCount * sizeof(vec3f), 0, BUFFER_MAP_WRITE_BIT);
	vec3f* vertices =  (vec3f*)_sphereVertBuf->Map(MAP_WRITE_BIT);
	_sphereIndexBuf = _renderContext->CreateBuffer(_sphereIndexCount * sizeof(ushort), 0, BUFFER_MAP_WRITE_BIT);
	ushort* indices = (ushort*)_sphereIndexBuf->Map(MAP_WRITE_BIT);

	int i;
	for(i = 1; i < stacks; ++i)
	{
		float elev = float(i) / stacks * PI;
		float sin_el = sin(elev);
		float cos_el = cos(elev);

		for(int j = 0; j <= slices; ++j)
		{
			float azimuth = float(j) / slices * TWO_PI;
			float sin_az = sin(azimuth);
			float cos_az = cos(azimuth);

			vec3f& vert = vertices[(i - 1) * vert_per_row + j] ;
			vert.set(cos_az * sin_el * radius, cos_el * radius, sin_az * sin_el * radius);
		}
	}

	int n_pole_i = vert_per_row * (stacks - 1);
	int s_pole_i = vert_per_row * (stacks - 1) + slices;

	for(i = 0; i < slices; ++i)
	{
		vec3f& vert_n = vertices[n_pole_i + i];
		vert_n.set(0, radius, 0);
	}

	for(i = 0; i < slices; ++i)
	{
		vec3f& vert_s = vertices[s_pole_i + i];
		vert_s.set(0, -radius, 0);
	}

	// calc indices
	ushort* ind = indices;
	for(i = 0; i < stacks - 2; ++i)
	{
		int first_i = i * vert_per_row;
		for(int j = 0; j < slices; ++j)
		{
			ushort v_index = first_i + j;

			ind[0] = v_index;
			ind[1] = v_index + 1;
			ind[2] = v_index + vert_per_row;

			ind[3] = v_index + 1;
			ind[4] = v_index + vert_per_row + 1;
			ind[5] = v_index + vert_per_row;

			ind += 6;
		}
	}

	for(i = 0; i < slices; ++i)
	{
		ind[0] = i;
		ind[1] = n_pole_i + i;
		ind[2] = i + 1;

		ind += 3;
	}

	int last_row_i = vert_per_row * (stacks - 2);
	for(i = 0; i < slices; ++i)
	{
		ind[0] = s_pole_i + i;
		ind[1] = last_row_i + i;
		ind[2] = ind[1] + 1;

		ind += 3;
	}

	_sphereIndexBuf->Unmap();
	_sphereVertBuf->Unmap();

	VertexAttribDesc desc[] =
	{
		{ 0, 0, 3, TYPE_FLOAT, false, false, 0 },
	};
	_vertFmtSphere = _renderContext->CreateVertexFormat(sizeof(desc) / sizeof(*desc), desc);
}

void DeferredSample::DestroySphere()
{
	_renderContext->DestroyBuffer(_sphereVertBuf);
	_sphereVertBuf = nullptr;
	_renderContext->DestroyBuffer(_sphereIndexBuf);
	_sphereIndexBuf = nullptr;
	_renderContext->DestroyVertexFormat(_vertFmtSphere);
	_vertFmtSphere = nullptr;
}

void DeferredSample::UpdateLights()
{
	for(auto it = _lights.begin(); it != _lights.end(); ++it)
	{
		it->position += it->dir * 15.0f * _frameTime;
		if(it->position.x < _lightBoundsMin.x)
		{
			it->position.x = _lightBoundsMin.x + (_lightBoundsMin.x - it->position.x);
			clamp(it->position.x, _lightBoundsMin.x, _lightBoundsMax.x);
			it->dir.x = - it->dir.x;
		}
		if(it->position.x > _lightBoundsMax.x)
		{
			it->position.x = _lightBoundsMax.x - (it->position.x - _lightBoundsMax.x);
			clamp(it->position.x, _lightBoundsMin.x, _lightBoundsMax.x);
			it->dir.x = - it->dir.x;
		}

		if(it->position.y < _lightBoundsMin.y)
		{
			it->position.y = _lightBoundsMin.y + (_lightBoundsMin.y - it->position.y);
			clamp(it->position.y, _lightBoundsMin.y, _lightBoundsMax.y);
			it->dir.y = - it->dir.y;
		}
		if(it->position.y > _lightBoundsMax.y)
		{
			it->position.y = _lightBoundsMax.y - (it->position.y - _lightBoundsMax.y);
			clamp(it->position.y, _lightBoundsMin.y, _lightBoundsMax.y);
			it->dir.y = - it->dir.y;
		}

		if(it->position.z < _lightBoundsMin.z)
		{
			it->position.z = _lightBoundsMin.z + (_lightBoundsMin.z - it->position.z);
			clamp(it->position.z, _lightBoundsMin.z, _lightBoundsMax.z);
			it->dir.z = - it->dir.z;
		}
		if(it->position.z > _lightBoundsMax.z)
		{
			it->position.z = _lightBoundsMax.z - (it->position.z - _lightBoundsMax.z);
			clamp(it->position.z, _lightBoundsMin.z, _lightBoundsMax.z);
			it->dir.z = - it->dir.z;
		}
	}
}

void DeferredSample::Update(int frame_time)
{
	vec3f bounds = _modelBoundsMax - _modelBoundsMin;
	float max_dim = max(max(bounds.x, bounds.y), bounds.z);

	_worldMat.set_rotation_y(_rotY);
	_worldMat.rotate_x(_rotX);
	_viewMat.look_at(vec3f(0.0f, 0.0f, max_dim * 1.5f), vec3f::null, vec3f::y_axis);
	mul(_viewProjMat, _viewMat, _projMat);
}
