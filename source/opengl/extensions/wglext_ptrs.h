
// WGL_ARB_multisample

bool glextLoad_WGL_ARB_multisample(GLContextInfo& info);


// WGL_ARB_extensions_string

bool glextLoad_WGL_ARB_extensions_string(GLContextInfo& info);


// WGL_ARB_pixel_format

bool glextLoad_WGL_ARB_pixel_format(GLContextInfo& info);

EXTPTR PFNWGLCHOOSEPIXELFORMATARBPROC ptr_wglChoosePixelFormatARB;

// WGL_ARB_pixel_format_float

bool glextLoad_WGL_ARB_pixel_format_float(GLContextInfo& info);


// WGL_ARB_create_context

bool glextLoad_WGL_ARB_create_context(GLContextInfo& info);

EXTPTR PFNWGLCREATECONTEXTATTRIBSARBPROC ptr_wglCreateContextAttribsARB;

// WGL_EXT_swap_control

bool glextLoad_WGL_EXT_swap_control(GLContextInfo& info);

EXTPTR PFNWGLSWAPINTERVALEXTPROC ptr_wglSwapIntervalEXT;

// WGL_EXT_framebuffer_sRGB

bool glextLoad_WGL_EXT_framebuffer_sRGB(GLContextInfo& info);

