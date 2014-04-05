
// WGL_ARB_pixel_format

inline BOOL wglChoosePixelFormatARB(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats)
{
	GLenum error;
	assert(ptr_wglChoosePixelFormatARB);
	BOOL result;
	result = ptr_wglChoosePixelFormatARB(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}

// WGL_ARB_create_context

inline HGLRC wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int *attribList)
{
	GLenum error;
	assert(ptr_wglCreateContextAttribsARB);
	HGLRC result;
	result = ptr_wglCreateContextAttribsARB(hDC, hShareContext, attribList);
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}

// WGL_EXT_swap_control

inline BOOL wglSwapIntervalEXT(int interval)
{
	GLenum error;
	assert(ptr_wglSwapIntervalEXT);
	BOOL result;
	result = ptr_wglSwapIntervalEXT(interval);
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}