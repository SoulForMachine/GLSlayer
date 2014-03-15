
#ifndef _SAMPLES_COMMON_ISAMPLE_H_
#define _SAMPLES_COMMON_ISAMPLE_H_

#if defined (_WIN32)
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>
#elif defined (__linux__)
	#include <X11/Xlib.h>
	#include <X11/Xutil.h>
#endif


class ISample
{
public:
	virtual ~ISample() = 0;

#if defined (_WIN32)
	virtual bool Init(HWND hwnd, HINSTANCE hinstance) = 0;
#elif defined (__linux__)
	virtual bool Init(Display* display, Window window, const gls::FramebufferFormat& fbufFormat) = 0;
#endif
	virtual void Deinit() = 0;
	virtual void Render(int frame_time) = 0;
	virtual void OnResize(int width, int height) = 0;
	virtual void OnKeyDown(int key)				{ }
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
