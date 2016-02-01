
#ifndef _SAMPLES_TRIANGLE_SAMPLE_H_
#define _SAMPLES_TRIANGLE_SAMPLE_H_

#include "Math/math3d.h"
#include "GLSlayer/RenderContext.h"
#include "Common/ISample.h"
#include "Common/Console.h"


class TriangleSample : public ISample
{
public:
	TriangleSample();
	~TriangleSample();

	virtual bool Init(gls::CreateContextInfo& info) override;
	virtual void Deinit() override;
	virtual void GetFramebufferFormat(gls::FramebufferFormat& fbufFormat) override;
	virtual void Render(int frame_time) override;
	virtual void OnResize(int width, int height) override;

private:
	gls::IRenderContext* _renderContext;
	gls::IVertexShader* _vertexShader;
	gls::IFragmentShader* _fragmentShader;
	gls::IBuffer* _vertexBuffer;
	gls::IBuffer* _vertShaderUniforms;
	gls::IVertexFormat* _vertFormat;
	math3d::mat4f _projMat;
	Console _console;
};


#endif // _SAMPLES_TRIANGLE_SAMPLE_H_
