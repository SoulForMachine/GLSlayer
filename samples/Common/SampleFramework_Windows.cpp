
#include "SampleFramework_Windows.h"
#include <cassert>
#include "GLSlayer/RenderContextInit.h"
#include "ISample.h"

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "GLSlayer.lib")



SampleFramework::SampleFramework(const wchar_t* name, int wndWidth, int wndHeight)
	: _appName(name)
	, _wndWidth(wndWidth)
	, _wndHeight(wndHeight)
	, _hinstance(NULL)
	, _hwnd(NULL)
	, _prevMouseX(0)
	, _prevMouseY(0)
	, _lbtnDown(false), _rbtnDown(false), _mbtnDown(false)
	, _sample(nullptr)
{

}

SampleFramework::~SampleFramework()
{
	delete _sample;
}

int SampleFramework::Run(ISample* sample)
{
	_hinstance = (HINSTANCE)GetModuleHandle(0);
	_sample = sample;

	if(!MyCreateWindow())
		return 1;

	timeBeginPeriod(1);
	int frame_time;
	int prev_time = timeGetTime();
	int curr_time;

	MSG msg = { 0 };

	while(msg.message != WM_QUIT)
	{
		do
		{
			curr_time = timeGetTime();
			frame_time = curr_time - prev_time;
		}
		while(frame_time < 1);

		prev_time = curr_time;

		if(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		_sample->Render(frame_time);
	}

	timeEndPeriod(1);

	return (int)msg.wParam;
}

void SampleFramework::OnSize(int width, int height)
{
	_sample->OnResize(width, height);
	_wndWidth = width;
	_wndHeight = height;
}

void SampleFramework::OnMouseMove(int x, int y)
{
	_sample->OnMouseMove(x, y);

	if(_lbtnDown)
	{
		_sample->OnMouseDrag(x - _prevMouseX, y - _prevMouseY);
		_prevMouseX = x;
		_prevMouseY = y;
	}
}

void SampleFramework::OnLBtnDown(int x, int y)
{
	_lbtnDown = true;
	_prevMouseX = x;
	_prevMouseY = y;
	SetCapture(_hwnd);

	_sample->OnLBtnDown(x, y);
}

void SampleFramework::OnRBtnDown(int x, int y)
{
	_rbtnDown = true;
	_prevMouseX = x;
	_prevMouseY = y;
	SetCapture(_hwnd);

	_sample->OnRBtnDown(x, y);
}

void SampleFramework::OnMBtnDown(int x, int y)
{
	_mbtnDown = true;
	_prevMouseX = x;
	_prevMouseY = y;
	SetCapture(_hwnd);

	_sample->OnMBtnDown(x, y);
}

void SampleFramework::OnLBtnUp(int x, int y)
{
	_lbtnDown = false;
	ReleaseCapture();

	_sample->OnLBtnUp(x, y);
}

void SampleFramework::OnRBtnUp(int x, int y)
{
	_rbtnDown = false;
	ReleaseCapture();

	_sample->OnRBtnUp(x, y);
}

void SampleFramework::OnMBtnUp(int x, int y)
{
	_mbtnDown = false;
	ReleaseCapture();

	_sample->OnMBtnUp(x, y);
}

void SampleFramework::OnKeyDown(int key)
{
	_sample->OnKeyDown(key);
}

void SampleFramework::OnKeyUp(int key)
{
	_sample->OnKeyUp(key);
}

bool SampleFramework::MyCreateWindow()
{
	TCHAR wndClass[] = TEXT("GLSlayer samples wnd class");

	WNDCLASS wc;
	memset(&wc, 0, sizeof(wc));
	wc.hInstance = _hinstance;
	wc.style = CS_OWNDC;
	wc.lpszClassName = wndClass;
	wc.lpfnWndProc = WndProc;
	wc.hCursor = LoadCursor(0, IDC_ARROW);

	if(RegisterClass(&wc))
	{
		RECT rect = { 100, 100, 100 + _wndWidth, 100 + _wndHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, FALSE);
		_hwnd = CreateWindow(  wndClass, _appName.c_str(), WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
			rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 0, 0, _hinstance, 0);

		gls::FramebufferFormat format;
		_sample->GetFramebufferFormat(format);
		gls::CreateContextInfo info;
		info.debugContext = false;
		info.format = &format;
		info.instanceHandle = _hinstance;
		info.windowHandle = _hwnd;
		info.logger = nullptr;
		info.version = 330;
		info.shareContext = nullptr;

		if(!_sample->Init(info))
		{
			getc(stdin);
			return false;
		}

		_sample->OnResize(_wndWidth, _wndHeight);

		if(_hwnd)
			SetWindowLongPtr(_hwnd, GWLP_USERDATA, (LONG_PTR)this);

		return _hwnd != 0;
	}
	else
	{
		return false;
	}
}

bool SampleFramework::WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_CREATE:
		return true;

	case WM_DESTROY:
		_sample->Deinit();
		PostQuitMessage(0);
		return true;

	case WM_SIZE:
		OnSize(LOWORD(lParam), HIWORD(lParam));
		return true;

	case WM_KEYDOWN:
		if(wParam == VK_ESCAPE)
			DestroyWindow(_hwnd);
		else
			OnKeyDown((int)wParam);
		return true;

	case WM_KEYUP:
		OnKeyUp((int)wParam);
		return true;

	case WM_MOUSEMOVE:
		OnMouseMove(LOWORD(lParam), HIWORD(lParam));
		return true;

	case WM_LBUTTONDOWN:
		OnLBtnDown(LOWORD(lParam), HIWORD(lParam));
		return true;

	case WM_RBUTTONDOWN:
		OnRBtnDown(LOWORD(lParam), HIWORD(lParam));
		return true;

	case WM_MBUTTONDOWN:
		OnMBtnDown(LOWORD(lParam), HIWORD(lParam));
		return true;

	case WM_LBUTTONUP:
		OnLBtnUp(LOWORD(lParam), HIWORD(lParam));
		return true;

	case WM_RBUTTONUP:
		OnRBtnUp(LOWORD(lParam), HIWORD(lParam));
		return true;

	case WM_MBUTTONUP:
		OnMBtnUp(LOWORD(lParam), HIWORD(lParam));
		return true;
	}

	return false;
}

LRESULT	WINAPI	SampleFramework::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	SampleFramework* framework = (SampleFramework*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
	if(framework)
	{
		if(framework->WindowProc(hwnd, message, wParam, lParam))
			return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}
