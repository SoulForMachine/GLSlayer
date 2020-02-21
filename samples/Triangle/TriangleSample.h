
#ifndef _SAMPLES_TRIANGLE_SAMPLE_H_
#define _SAMPLES_TRIANGLE_SAMPLE_H_

#include "Math/math3d.h"
#include "GLSlayer/RenderContext.h"
#include "Common/ISample.h"
#include "Common/Console.h"


class TriangleSample : public ISample
{
public:
	TriangleSample() = default;
	~TriangleSample();

	virtual bool Init(gls::CreateContextInfo& info) override;
	virtual void Deinit() override;
	virtual void GetFramebufferFormat(gls::FramebufferFormat& fbufFormat) override;
	virtual void Render(float frame_time) override;
	virtual void OnResize(int width, int height) override;

private:
	gls::IRenderContext* _renderContext = nullptr;
	gls::IVertexShader* _vertexShader = nullptr;
	gls::IFragmentShader* _fragmentShader = nullptr;
	gls::IBuffer* _vertexBuffer = nullptr;
	gls::IBuffer* _vertShaderUniforms = nullptr;
	gls::IVertexFormat* _vertFormat = nullptr;
	math3d::mat4f _projMat;
	Console _console;
};


#endif // _SAMPLES_TRIANGLE_SAMPLE_H_
