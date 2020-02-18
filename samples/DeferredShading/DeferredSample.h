
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
	DeferredSample();

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

	gls::IRenderContext* _renderContext;
	gls::IFramebuffer* _gbuffer;
	gls::ITexture2D* _texDiffuse;
	gls::ITexture2D* _texNormal;
	gls::ITexture2D* _texPosition;
	gls::ITexture2D* _depthBuffer;
	gls::IFramebuffer* _sceneBuffer;
	gls::ITexture2D* _texSceneColor;
	gls::ITextureBuffer* _lightMatrixTex;
	gls::IBuffer* _lightMatrixBuf;
	gls::ITextureBuffer* _lightInfoTex;
	gls::IBuffer* _lightInfoBuf;
	gls::IVertexShader* _vertShaderGbuffer;
	gls::IFragmentShader* _fragShaderGBuffer;
	gls::IVertexShader* _vertShaderScreenSpace;
	gls::IFragmentShader* _fragShaderSimpleTex;
	gls::IVertexShader* _vertShaderLight;
	gls::IFragmentShader* _fragShaderLight;
	gls::IVertexFormat* _vertexFormat;
	gls::IVertexFormat* _vertFmtScreenRect;
	gls::IVertexFormat* _vertFmtSphere;
	gls::IBuffer* _vertexBuffer;
	gls::IBuffer* _indexBuffer;
	gls::IBuffer* _ubufVertShaderGBuffer;
	gls::IBuffer* _ubufFragShaderGBuffer;
	gls::IBuffer* _ubufVertShaderSSpace;
	gls::IBuffer* _ubufFragShaderSimpleTex;
	gls::IBuffer* _ubufFragShaderLighting;
	gls::IBuffer* _rectVertBuf;
	gls::IBuffer* _sphereVertBuf;
	gls::IBuffer* _sphereIndexBuf;
	gls::ISamplerState* _samplerGBuffer;
	gls::ISamplerState* _samplerLight;
	gls::IQuery* _query;
	math3d::mat4f _worldMat, _viewMat, _projMat, _viewProjMat;
	Console _console;
	std::vector<PointLight> _lights;
	int _sphereVertCount;
	int _sphereIndexCount;
	int _skullIndexCount;
	math3d::vec3f _modelBoundsMin;
	math3d::vec3f _modelBoundsMax;
	math3d::vec3f _lightBoundsMin;
	math3d::vec3f _lightBoundsMax;
	float _frameTime;
	int _width;
	int _height;
	float _rotX, _rotY;
	bool _showGBuffer;
	int _swapInterval;
};

#endif // _DEFERRED_SHADING_RENDERING_H_
