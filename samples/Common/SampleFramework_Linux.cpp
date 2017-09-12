
#include <time.h>
#include <cmath>
#include "GLSlayer/RenderContextInit.h"
#include "SampleFramework_Linux.h"
#include "ISample.h"

using namespace std;


SampleFramework::SampleFramework(const wchar_t* name, int wndWidth, int wndHeight)
    : _display(nullptr)
    , _wndWidth(wndWidth)
    , _wndHeight(wndHeight)
    , _appName(name)
    , _prevMouseX(0)
    , _prevMouseY(0)
    , _lbtnDown(false)
    , _rbtnDown(false)
    , _mbtnDown(false)
    , _sample(nullptr)
    , _quit(false)
{

}

SampleFramework::~SampleFramework()
{
	delete _sample;
}

int SampleFramework::Run(ISample* sample)
{
    _display = XOpenDisplay(nullptr);

    if(!_display)
		return 1;

	_sample = sample;

    gls::FramebufferFormat fbufFormat;
	_sample->GetFramebufferFormat(fbufFormat);

    XVisualInfo visual_info;
	if(!gls::GetXVisualInfo(_display, fbufFormat, visual_info))
        return 1;
    Window root_window = XRootWindow(_display, visual_info.screen);

    XSetWindowAttributes swa;
    swa.colormap = XCreateColormap(_display, root_window, visual_info.visual, AllocNone);
    swa.background_pixmap = None;
    swa.border_pixel      = 0;
    swa.event_mask        = StructureNotifyMask | KeyPressMask | KeyReleaseMask | PointerMotionMask | ButtonPressMask | ButtonReleaseMask;

    Window window = XCreateWindow(_display, root_window, 0, 0, 800, 600, 0, visual_info.depth,
                                  InputOutput, visual_info.visual, CWBorderPixel|CWColormap|CWEventMask, &swa);

    if(!window)
        return 1;

    _wmDeleteMessage = XInternAtom(_display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(_display, window, &_wmDeleteMessage, 1);
    XStoreName(_display, window, "Deferred shading");
    XMapWindow(_display, window);

	gls::CreateContextInfo info;
	info.debugContext = false;
	info.format = &fbufFormat;
	info.display = _display;
	info.window = window;
	info.logger = nullptr;
	info.version = 330;
	info.shareContext = nullptr;

    if(!_sample->Init(info))
    {
        XDestroyWindow(_display, window);
        XFreeColormap(_display, swa.colormap);
        XCloseDisplay(_display);
        return 1;
    }

    _sample->OnResize(800, 600);

    timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    double prev_time = t.tv_sec * 1000.0 + t.tv_nsec / 1.0e6;
    XEvent event;

    while(!_quit)
    {
        while(XEventsQueued(_display, QueuedAfterFlush) > 0)
        {
            XNextEvent(_display, &event);
            ProcessEvent(&event);
        }

        clock_gettime(CLOCK_MONOTONIC, &t);
        double cur_time = t.tv_sec * 1000.0 + t.tv_nsec / 1.0e6;
        double frame_time = cur_time - prev_time;
        prev_time = cur_time;

        _sample->Render((int)floor(frame_time + 0.5));
    }

    _sample->Deinit();

    XDestroyWindow(_display, window);
    XFreeColormap(_display, swa.colormap);
    XCloseDisplay(_display);

    return 0;
}

void SampleFramework::OnKeyPress(XKeyEvent* event)
{
	KeySym key = XLookupKeysym(event, 0);

    if(key == XK_Escape)
        _quit = true;
    else
		_sample->OnKeyDown(key & 0xFF);
}

void SampleFramework::OnKeyRelease(XKeyEvent* event)
{
	KeySym key = XLookupKeysym(event, 0);

}

void SampleFramework::OnMotionNotify(XMotionEvent* event)
{
    int x = event->x;
    int y = event->y;
    _sample->OnMouseMove(x, y);

    if(_lbtnDown)
    {
        _sample->OnMouseDrag(x - _prevMouseX, y - _prevMouseY);
        _prevMouseX = x;
        _prevMouseY = y;
    }
}

void SampleFramework::OnButtonPress(XButtonEvent* event)
{
    int x = event->x;
    int y = event->y;

	if(event->button == Button1)
	{
        _lbtnDown = true;
        _prevMouseX = x;
        _prevMouseY = y;
        _sample->OnLBtnDown(x, y);
	}
    else if(event->button == Button2)
    {
        _rbtnDown = true;
        _prevMouseX = x;
        _prevMouseY = y;
        _sample->OnRBtnDown(x, y);
    }
    else if(event->button == Button3)
    {
        _mbtnDown = true;
        _prevMouseX = x;
        _prevMouseY = y;
        _sample->OnMBtnDown(x, y);
    }
}

void SampleFramework::OnButtonRelease(XButtonEvent* event)
{
    int x = event->x;
    int y = event->y;

	if(event->button == Button1)
	{
        _lbtnDown = false;
        _sample->OnLBtnUp(x, y);
	}
    else if(event->button == Button2)
    {
        _rbtnDown = false;
        _sample->OnRBtnUp(x, y);
    }
    else if(event->button == Button3)
    {
        _mbtnDown = false;
        _sample->OnMBtnUp(x, y);
    }
}

void SampleFramework::ProcessEvent(XEvent* event)
{
	switch(event->type)
	{
	case MotionNotify:
		OnMotionNotify(&event->xmotion);
		break;
	case ButtonPress:
		OnButtonPress(&event->xbutton);
		break;
	case ButtonRelease:
		OnButtonRelease(&event->xbutton);
		break;
	case KeyPress:
		OnKeyPress(&event->xkey);
		break;
	case KeyRelease:
		OnKeyRelease(&event->xkey);
		break;
	case ConfigureNotify:
        if(	event->xconfigure.width != _wndWidth ||
            event->xconfigure.height != _wndHeight)
		{
            _wndWidth = event->xconfigure.width;
            _wndHeight = event->xconfigure.height;
            _sample->OnResize(_wndWidth, _wndHeight);
		}
		break;
	case CreateNotify:
		break;
	case DestroyNotify:
		break;
	case ClientMessage:
        if((Atom)event->xclient.data.l[0] == _wmDeleteMessage)
            _quit = true;
		break;
	}
}
