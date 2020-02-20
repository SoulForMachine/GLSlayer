
#ifndef _SAMPLES_COMMON_ISAMPLE_H_
#define _SAMPLES_COMMON_ISAMPLE_H_

namespace gls
{
struct CreateContextInfo;
struct FramebufferFormat;
}

class ISample
{
public:
	virtual ~ISample() = 0;

	virtual bool Init(gls::CreateContextInfo& info) = 0;
	virtual void Deinit() = 0;
	virtual void GetFramebufferFormat(gls::FramebufferFormat& fbufFormat) = 0;
	virtual void Render(int frame_time) = 0;
	virtual void OnResize(int width, int height) = 0;
	virtual void OnKeyDown(int key)				{ }
	virtual void OnKeyUp(int key)				{ }
	virtual void OnMouseMove(int x, int y)		{ }
	virtual void OnMouseDrag(int dx, int dy)	{ }
	virtual void OnLBtnDown(int x, int y)		{ }
	virtual void OnRBtnDown(int x, int y)		{ }
	virtual void OnMBtnDown(int x, int y)		{ }
	virtual void OnLBtnUp(int x, int y)			{ }
	virtual void OnRBtnUp(int x, int y)			{ }
	virtual void OnMBtnUp(int x, int y)			{ }
};


inline
ISample::~ISample()
{
}


#endif // _SAMPLES_COMMON_ISAMPLE_H_
