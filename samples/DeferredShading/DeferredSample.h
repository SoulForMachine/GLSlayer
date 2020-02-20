
#ifndef _DEFERRED_SHADING_RENDERING_H_
#define _DEFERRED_SHADING_RENDERING_H_

#include <vector>
#include "Math/math3d.h"
#include "GLSlayer/RenderContext.h"
#include "Light.h"
#include "Common/ISample.h"
#include "Common/Console.h"


class DeferredSample : public ISample
{
public:
	DeferredSample() = default;
	~DeferredSample();

	virtual bool Init(gls::CreateContextInfo& info) override;
	virtual void Deinit() override;
	virtual void GetFramebufferFormat(gls::FramebufferFormat& fbufFormat) override;
	virtual void Render(int frame_time) override;
	virtual void OnResize(int width, int height) override;
	virtual void OnKeyDown(int key) override;
	virtual void OnMouseDrag(int dx, int dy) override;

private:
	void CreateFramebuffers(int width, int height);
	void DestroyFramebuffers();
	void RenderGeometryPass();
	void RenderLightingPass();
	void RenderGBuffer();
	void CreateRandomLights(int count, const math3d::vec3f& min_pt, const math3d::vec3f& max_pt);
	void CreateSphere(float radius, int slices, int stacks);
	void DestroySphere();
	void UpdateLights();
	void Update(int frame_time);

	gls::IRenderContext* _renderContext = nullptr;
	gls::IFramebuffer* _gbuffer = nullptr;
	gls::ITexture2D* _texDiffuse = nullptr;
	gls::ITexture2D* _texNormal = nullptr;
	gls::ITexture2D* _texPosition = nullptr;
	gls::ITexture2D* _depthBuffer = nullptr;
	gls::IFramebuffer* _sceneBuffer = nullptr;
	gls::ITexture2D* _texSceneColor = nullptr;
	gls::ITextureBuffer* _lightMatrixTex = nullptr;
	gls::IBuffer* _lightMatrixBuf = nullptr;
	gls::ITextureBuffer* _lightInfoTex = nullptr;
	gls::IBuffer* _lightInfoBuf = nullptr;
	gls::IVertexShader* _vertShaderGbuffer = nullptr;
	gls::IFragmentShader* _fragShaderGBuffer = nullptr;
	gls::IVertexShader* _vertShaderScreenSpace = nullptr;
	gls::IFragmentShader* _fragShaderSimpleTex = nullptr;
	gls::IVertexShader* _vertShaderLight = nullptr;
	gls::IFragmentShader* _fragShaderLight = nullptr;
	gls::IVertexFormat* _vertexFormat = nullptr;
	gls::IVertexFormat* _vertFmtScreenRect = nullptr;
	gls::IVertexFormat* _vertFmtSphere = nullptr;
	gls::IBuffer* _vertexBuffer = nullptr;
	gls::IBuffer* _indexBuffer = nullptr;
	gls::IBuffer* _ubufVertShaderGBuffer = nullptr;
	gls::IBuffer* _ubufFragShaderGBuffer = nullptr;
	gls::IBuffer* _ubufVertShaderSSpace = nullptr;
	gls::IBuffer* _ubufFragShaderSimpleTex = nullptr;
	gls::IBuffer* _ubufFragShaderLighting = nullptr;
	gls::IBuffer* _rectVertBuf = nullptr;
	gls::IBuffer* _sphereVertBuf = nullptr;
	gls::IBuffer* _sphereIndexBuf = nullptr;
	gls::ISamplerState* _samplerGBuffer = nullptr;
	gls::ISamplerState* _samplerLight = nullptr;
	gls::IQuery* _query = nullptr;
	math3d::mat4f _worldMat, _viewMat, _projMat, _viewProjMat;
	Console _console;
	std::vector<PointLight> _lights;
	int _sphereVertCount = 0;
	int _sphereIndexCount = 0;
	int _skullIndexCount = 0;
	math3d::vec3f _modelBoundsMin;
	math3d::vec3f _modelBoundsMax;
	math3d::vec3f _lightBoundsMin;
	math3d::vec3f _lightBoundsMax;
	float _frameTime = 0.0f;
	int _width = 0;
	int _height = 0;
	float _rotX = 0.0f;
	float _rotY = 0.0f;
	bool _showGBuffer = false;
	int _swapInterval = 1;
};

#endif // _DEFERRED_SHADING_RENDERING_H_
