
// GLX_ARB_create_context

bool glextLoad_GLX_ARB_create_context()
{
	INIT_FUNC_PTR(glXCreateContextAttribsARB);

	return true;
}

// GLX_EXT_swap_control

bool glextLoad_GLX_EXT_swap_control()
{
	INIT_FUNC_PTR(glXSwapIntervalEXT);

	return true;
}
