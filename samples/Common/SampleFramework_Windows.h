
#ifndef _SAMPLES_COMMON_SAMPLE_FRAMEWORK_WINDOWS_H_
#define _SAMPLES_COMMON_SAMPLE_FRAMEWORK_WINDOWS_H_

#include <string>

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#ifdef MemoryBarrier
	#undef MemoryBarrier
#endif
#include <mmsystem.h>


class ISample;


class SampleFramework
{
public:
	SampleFramework(const wchar_t* name, int wndWidth, int wndHeight);
	~SampleFramework();
	int Run(ISample* sample);

private:
	void OnSize(int width, int height);
	void OnMouseMove(int x, int y);
	void OnLBtnDown(int x, int y);
	void OnRBtnDown(int x, int y);
	void OnMBtnDown(int x, int y);
	void OnLBtnUp(int x, int y);
	void OnRBtnUp(int x, int y);
	void OnMBtnUp(int x, int y);
	void OnKeyDown(int key);
	void OnKeyUp(int key);
	bool MyCreateWindow();
	bool WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	static LRESULT	WINAPI	WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	HINSTANCE _hinstance;
	HWND _hwnd;
	int _wndWidth;
	int _wndHeight;
	std::wstring _appName;
	int _prevMouseX, _prevMouseY;
	bool _lbtnDown, _rbtnDown, _mbtnDown;
	ISample* _sample;
};


#endif // _SAMPLES_COMMON_SAMPLE_FRAMEWORK_WINDOWS_H_
