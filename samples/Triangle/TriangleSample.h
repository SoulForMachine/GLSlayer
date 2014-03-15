
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

#if defined (_WIN32)
	virtual bool Init(HWND hwnd, HINSTANCE hinstance);
#elif defined (__linux__)
	virtual bool Init(Display* display, Window window, const gls::FramebufferFormat& fbufFormat);
#endif
	virtual void Deinit();
	virtual void Render(int frame_time);
	virtual void OnResize(int width, int height);

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
