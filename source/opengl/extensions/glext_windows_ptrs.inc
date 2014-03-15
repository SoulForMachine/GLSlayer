
// GL_VERSION_1_2

bool glextLoad_GL_VERSION_1_2()
{
	INIT_FUNC_PTR(glBlendColor);
	INIT_FUNC_PTR(glBlendEquation);
	INIT_FUNC_PTR(glDrawRangeElements);
	INIT_FUNC_PTR(glTexImage3D);
	INIT_FUNC_PTR(glTexSubImage3D);
	INIT_FUNC_PTR(glCopyTexSubImage3D);

	return true;
}

// GL_VERSION_1_3

bool glextLoad_GL_VERSION_1_3()
{
	INIT_FUNC_PTR(glActiveTexture);
	INIT_FUNC_PTR(glSampleCoverage);
	INIT_FUNC_PTR(glCompressedTexImage3D);
	INIT_FUNC_PTR(glCompressedTexImage2D);
	INIT_FUNC_PTR(glCompressedTexImage1D);
	INIT_FUNC_PTR(glCompressedTexSubImage3D);
	INIT_FUNC_PTR(glCompressedTexSubImage2D);
	INIT_FUNC_PTR(glCompressedTexSubImage1D);
	INIT_FUNC_PTR(glGetCompressedTexImage);

	return true;
}

// GL_VERSION_1_4

bool glextLoad_GL_VERSION_1_4()
{
	INIT_FUNC_PTR(glBlendFuncSeparate);
	INIT_FUNC_PTR(glMultiDrawArrays);
	INIT_FUNC_PTR(glMultiDrawElements);
	INIT_FUNC_PTR(glPointParameterf);
	INIT_FUNC_PTR(glPointParameterfv);
	INIT_FUNC_PTR(glPointParameteri);
	INIT_FUNC_PTR(glPointParameteriv);

	return true;
}

// GL_VERSION_1_5

bool glextLoad_GL_VERSION_1_5()
{
	INIT_FUNC_PTR(glGenQueries);
	INIT_FUNC_PTR(glDeleteQueries);
	INIT_FUNC_PTR(glIsQuery);
	INIT_FUNC_PTR(glBeginQuery);
	INIT_FUNC_PTR(glEndQuery);
	INIT_FUNC_PTR(glGetQueryiv);
	INIT_FUNC_PTR(glGetQueryObjectiv);
	INIT_FUNC_PTR(glGetQueryObjectuiv);
	INIT_FUNC_PTR(glBindBuffer);
	INIT_FUNC_PTR(glDeleteBuffers);
	INIT_FUNC_PTR(glGenBuffers);
	INIT_FUNC_PTR(glIsBuffer);
	INIT_FUNC_PTR(glBufferData);
	INIT_FUNC_PTR(glBufferSubData);
	INIT_FUNC_PTR(glGetBufferSubData);
	INIT_FUNC_PTR(glMapBuffer);
	INIT_FUNC_PTR(glUnmapBuffer);
	INIT_FUNC_PTR(glGetBufferParameteriv);
	INIT_FUNC_PTR(glGetBufferPointerv);

	return true;
}

// GL_VERSION_2_0

bool glextLoad_GL_VERSION_2_0()
{
	INIT_FUNC_PTR(glBlendEquationSeparate);
	INIT_FUNC_PTR(glDrawBuffers);
	INIT_FUNC_PTR(glStencilOpSeparate);
	INIT_FUNC_PTR(glStencilFuncSeparate);
	INIT_FUNC_PTR(glStencilMaskSeparate);
	INIT_FUNC_PTR(glAttachShader);
	INIT_FUNC_PTR(glBindAttribLocation);
	INIT_FUNC_PTR(glCompileShader);
	INIT_FUNC_PTR(glCreateProgram);
	INIT_FUNC_PTR(glCreateShader);
	INIT_FUNC_PTR(glDeleteProgram);
	INIT_FUNC_PTR(glDeleteShader);
	INIT_FUNC_PTR(glDetachShader);
	INIT_FUNC_PTR(glDisableVertexAttribArray);
	INIT_FUNC_PTR(glEnableVertexAttribArray);
	INIT_FUNC_PTR(glGetActiveAttrib);
	INIT_FUNC_PTR(glGetActiveUniform);
	INIT_FUNC_PTR(glGetAttachedShaders);
	INIT_FUNC_PTR(glGetAttribLocation);
	INIT_FUNC_PTR(glGetProgramiv);
	INIT_FUNC_PTR(glGetProgramInfoLog);
	INIT_FUNC_PTR(glGetShaderiv);
	INIT_FUNC_PTR(glGetShaderInfoLog);
	INIT_FUNC_PTR(glGetShaderSource);
	INIT_FUNC_PTR(glGetUniformLocation);
	INIT_FUNC_PTR(glGetUniformfv);
	INIT_FUNC_PTR(glGetUniformiv);
	INIT_FUNC_PTR(glGetVertexAttribdv);
	INIT_FUNC_PTR(glGetVertexAttribfv);
	INIT_FUNC_PTR(glGetVertexAttribiv);
	INIT_FUNC_PTR(glGetVertexAttribPointerv);
	INIT_FUNC_PTR(glIsProgram);
	INIT_FUNC_PTR(glIsShader);
	INIT_FUNC_PTR(glLinkProgram);
	INIT_FUNC_PTR(glShaderSource);
	INIT_FUNC_PTR(glUseProgram);
	INIT_FUNC_PTR(glUniform1f);
	INIT_FUNC_PTR(glUniform2f);
	INIT_FUNC_PTR(glUniform3f);
	INIT_FUNC_PTR(glUniform4f);
	INIT_FUNC_PTR(glUniform1i);
	INIT_FUNC_PTR(glUniform2i);
	INIT_FUNC_PTR(glUniform3i);
	INIT_FUNC_PTR(glUniform4i);
	INIT_FUNC_PTR(glUniform1fv);
	INIT_FUNC_PTR(glUniform2fv);
	INIT_FUNC_PTR(glUniform3fv);
	INIT_FUNC_PTR(glUniform4fv);
	INIT_FUNC_PTR(glUniform1iv);
	INIT_FUNC_PTR(glUniform2iv);
	INIT_FUNC_PTR(glUniform3iv);
	INIT_FUNC_PTR(glUniform4iv);
	INIT_FUNC_PTR(glUniformMatrix2fv);
	INIT_FUNC_PTR(glUniformMatrix3fv);
	INIT_FUNC_PTR(glUniformMatrix4fv);
	INIT_FUNC_PTR(glValidateProgram);
	INIT_FUNC_PTR(glVertexAttrib1d);
	INIT_FUNC_PTR(glVertexAttrib1dv);
	INIT_FUNC_PTR(glVertexAttrib1f);
	INIT_FUNC_PTR(glVertexAttrib1fv);
	INIT_FUNC_PTR(glVertexAttrib1s);
	INIT_FUNC_PTR(glVertexAttrib1sv);
	INIT_FUNC_PTR(glVertexAttrib2d);
	INIT_FUNC_PTR(glVertexAttrib2dv);
	INIT_FUNC_PTR(glVertexAttrib2f);
	INIT_FUNC_PTR(glVertexAttrib2fv);
	INIT_FUNC_PTR(glVertexAttrib2s);
	INIT_FUNC_PTR(glVertexAttrib2sv);
	INIT_FUNC_PTR(glVertexAttrib3d);
	INIT_FUNC_PTR(glVertexAttrib3dv);
	INIT_FUNC_PTR(glVertexAttrib3f);
	INIT_FUNC_PTR(glVertexAttrib3fv);
	INIT_FUNC_PTR(glVertexAttrib3s);
	INIT_FUNC_PTR(glVertexAttrib3sv);
	INIT_FUNC_PTR(glVertexAttrib4Nbv);
	INIT_FUNC_PTR(glVertexAttrib4Niv);
	INIT_FUNC_PTR(glVertexAttrib4Nsv);
	INIT_FUNC_PTR(glVertexAttrib4Nub);
	INIT_FUNC_PTR(glVertexAttrib4Nubv);
	INIT_FUNC_PTR(glVertexAttrib4Nuiv);
	INIT_FUNC_PTR(glVertexAttrib4Nusv);
	INIT_FUNC_PTR(glVertexAttrib4bv);
	INIT_FUNC_PTR(glVertexAttrib4d);
	INIT_FUNC_PTR(glVertexAttrib4dv);
	INIT_FUNC_PTR(glVertexAttrib4f);
	INIT_FUNC_PTR(glVertexAttrib4fv);
	INIT_FUNC_PTR(glVertexAttrib4iv);
	INIT_FUNC_PTR(glVertexAttrib4s);
	INIT_FUNC_PTR(glVertexAttrib4sv);
	INIT_FUNC_PTR(glVertexAttrib4ubv);
	INIT_FUNC_PTR(glVertexAttrib4uiv);
	INIT_FUNC_PTR(glVertexAttrib4usv);
	INIT_FUNC_PTR(glVertexAttribPointer);

	return true;
}

// GL_VERSION_2_1

bool glextLoad_GL_VERSION_2_1()
{
	INIT_FUNC_PTR(glUniformMatrix2x3fv);
	INIT_FUNC_PTR(glUniformMatrix3x2fv);
	INIT_FUNC_PTR(glUniformMatrix2x4fv);
	INIT_FUNC_PTR(glUniformMatrix4x2fv);
	INIT_FUNC_PTR(glUniformMatrix3x4fv);
	INIT_FUNC_PTR(glUniformMatrix4x3fv);

	return true;
}

// GL_VERSION_3_0

bool glextLoad_GL_VERSION_3_0()
{
	INIT_FUNC_PTR(glColorMaski);
	INIT_FUNC_PTR(glGetBooleani_v);
	INIT_FUNC_PTR(glGetIntegeri_v);
	INIT_FUNC_PTR(glEnablei);
	INIT_FUNC_PTR(glDisablei);
	INIT_FUNC_PTR(glIsEnabledi);
	INIT_FUNC_PTR(glBeginTransformFeedback);
	INIT_FUNC_PTR(glEndTransformFeedback);
	INIT_FUNC_PTR(glBindBufferRange);
	INIT_FUNC_PTR(glBindBufferBase);
	INIT_FUNC_PTR(glTransformFeedbackVaryings);
	INIT_FUNC_PTR(glGetTransformFeedbackVarying);
	INIT_FUNC_PTR(glClampColor);
	INIT_FUNC_PTR(glBeginConditionalRender);
	INIT_FUNC_PTR(glEndConditionalRender);
	INIT_FUNC_PTR(glVertexAttribIPointer);
	INIT_FUNC_PTR(glGetVertexAttribIiv);
	INIT_FUNC_PTR(glGetVertexAttribIuiv);
	INIT_FUNC_PTR(glVertexAttribI1i);
	INIT_FUNC_PTR(glVertexAttribI2i);
	INIT_FUNC_PTR(glVertexAttribI3i);
	INIT_FUNC_PTR(glVertexAttribI4i);
	INIT_FUNC_PTR(glVertexAttribI1ui);
	INIT_FUNC_PTR(glVertexAttribI2ui);
	INIT_FUNC_PTR(glVertexAttribI3ui);
	INIT_FUNC_PTR(glVertexAttribI4ui);
	INIT_FUNC_PTR(glVertexAttribI1iv);
	INIT_FUNC_PTR(glVertexAttribI2iv);
	INIT_FUNC_PTR(glVertexAttribI3iv);
	INIT_FUNC_PTR(glVertexAttribI4iv);
	INIT_FUNC_PTR(glVertexAttribI1uiv);
	INIT_FUNC_PTR(glVertexAttribI2uiv);
	INIT_FUNC_PTR(glVertexAttribI3uiv);
	INIT_FUNC_PTR(glVertexAttribI4uiv);
	INIT_FUNC_PTR(glVertexAttribI4bv);
	INIT_FUNC_PTR(glVertexAttribI4sv);
	INIT_FUNC_PTR(glVertexAttribI4ubv);
	INIT_FUNC_PTR(glVertexAttribI4usv);
	INIT_FUNC_PTR(glGetUniformuiv);
	INIT_FUNC_PTR(glBindFragDataLocation);
	INIT_FUNC_PTR(glGetFragDataLocation);
	INIT_FUNC_PTR(glUniform1ui);
	INIT_FUNC_PTR(glUniform2ui);
	INIT_FUNC_PTR(glUniform3ui);
	INIT_FUNC_PTR(glUniform4ui);
	INIT_FUNC_PTR(glUniform1uiv);
	INIT_FUNC_PTR(glUniform2uiv);
	INIT_FUNC_PTR(glUniform3uiv);
	INIT_FUNC_PTR(glUniform4uiv);
	INIT_FUNC_PTR(glTexParameterIiv);
	INIT_FUNC_PTR(glTexParameterIuiv);
	INIT_FUNC_PTR(glGetTexParameterIiv);
	INIT_FUNC_PTR(glGetTexParameterIuiv);
	INIT_FUNC_PTR(glClearBufferiv);
	INIT_FUNC_PTR(glClearBufferuiv);
	INIT_FUNC_PTR(glClearBufferfv);
	INIT_FUNC_PTR(glClearBufferfi);
	INIT_FUNC_PTR(glGetStringi);

	return true;
}

// GL_VERSION_3_1

bool glextLoad_GL_VERSION_3_1()
{
	INIT_FUNC_PTR(glDrawArraysInstanced);
	INIT_FUNC_PTR(glDrawElementsInstanced);
	INIT_FUNC_PTR(glTexBuffer);
	INIT_FUNC_PTR(glPrimitiveRestartIndex);

	return true;
}

// GL_VERSION_3_2

bool glextLoad_GL_VERSION_3_2()
{
	INIT_FUNC_PTR(glGetInteger64i_v);
	INIT_FUNC_PTR(glGetBufferParameteri64v);
	INIT_FUNC_PTR(glFramebufferTexture);

	return true;
}

// GL_VERSION_3_3

bool glextLoad_GL_VERSION_3_3()
{
	INIT_FUNC_PTR(glVertexAttribDivisor);

	return true;
}

// GL_VERSION_4_0

bool glextLoad_GL_VERSION_4_0()
{
	INIT_FUNC_PTR(glMinSampleShading);
	INIT_FUNC_PTR(glBlendEquationi);
	INIT_FUNC_PTR(glBlendEquationSeparatei);
	INIT_FUNC_PTR(glBlendFunci);
	INIT_FUNC_PTR(glBlendFuncSeparatei);

	return true;
}

// GL_ARB_framebuffer_object

bool glextLoad_GL_ARB_framebuffer_object()
{
	INIT_FUNC_PTR(glIsRenderbuffer);
	INIT_FUNC_PTR(glBindRenderbuffer);
	INIT_FUNC_PTR(glDeleteRenderbuffers);
	INIT_FUNC_PTR(glGenRenderbuffers);
	INIT_FUNC_PTR(glRenderbufferStorage);
	INIT_FUNC_PTR(glGetRenderbufferParameteriv);
	INIT_FUNC_PTR(glIsFramebuffer);
	INIT_FUNC_PTR(glBindFramebuffer);
	INIT_FUNC_PTR(glDeleteFramebuffers);
	INIT_FUNC_PTR(glGenFramebuffers);
	INIT_FUNC_PTR(glCheckFramebufferStatus);
	INIT_FUNC_PTR(glFramebufferTexture1D);
	INIT_FUNC_PTR(glFramebufferTexture2D);
	INIT_FUNC_PTR(glFramebufferTexture3D);
	INIT_FUNC_PTR(glFramebufferRenderbuffer);
	INIT_FUNC_PTR(glGetFramebufferAttachmentParameteriv);
	INIT_FUNC_PTR(glGenerateMipmap);
	INIT_FUNC_PTR(glBlitFramebuffer);
	INIT_FUNC_PTR(glRenderbufferStorageMultisample);
	INIT_FUNC_PTR(glFramebufferTextureLayer);

	return true;
}

// GL_ARB_geometry_shader4

bool glextLoad_GL_ARB_geometry_shader4()
{
	INIT_FUNC_PTR(glProgramParameteriARB);
	INIT_FUNC_PTR(glFramebufferTextureARB);
	INIT_FUNC_PTR(glFramebufferTextureLayerARB);
	INIT_FUNC_PTR(glFramebufferTextureFaceARB);

	return true;
}

// GL_ARB_map_buffer_range

bool glextLoad_GL_ARB_map_buffer_range()
{
	INIT_FUNC_PTR(glMapBufferRange);
	INIT_FUNC_PTR(glFlushMappedBufferRange);

	return true;
}

// GL_ARB_vertex_array_object

bool glextLoad_GL_ARB_vertex_array_object()
{
	INIT_FUNC_PTR(glBindVertexArray);
	INIT_FUNC_PTR(glDeleteVertexArrays);
	INIT_FUNC_PTR(glGenVertexArrays);
	INIT_FUNC_PTR(glIsVertexArray);

	return true;
}

// GL_ARB_uniform_buffer_object

bool glextLoad_GL_ARB_uniform_buffer_object()
{
	INIT_FUNC_PTR(glGetUniformIndices);
	INIT_FUNC_PTR(glGetActiveUniformsiv);
	INIT_FUNC_PTR(glGetActiveUniformName);
	INIT_FUNC_PTR(glGetUniformBlockIndex);
	INIT_FUNC_PTR(glGetActiveUniformBlockiv);
	INIT_FUNC_PTR(glGetActiveUniformBlockName);
	INIT_FUNC_PTR(glUniformBlockBinding);

	return true;
}

// GL_ARB_copy_buffer

bool glextLoad_GL_ARB_copy_buffer()
{
	INIT_FUNC_PTR(glCopyBufferSubData);

	return true;
}

// GL_ARB_draw_elements_base_vertex

bool glextLoad_GL_ARB_draw_elements_base_vertex()
{
	INIT_FUNC_PTR(glDrawElementsBaseVertex);
	INIT_FUNC_PTR(glDrawRangeElementsBaseVertex);
	INIT_FUNC_PTR(glDrawElementsInstancedBaseVertex);
	INIT_FUNC_PTR(glMultiDrawElementsBaseVertex);

	return true;
}

// GL_ARB_provoking_vertex

bool glextLoad_GL_ARB_provoking_vertex()
{
	INIT_FUNC_PTR(glProvokingVertex);

	return true;
}

// GL_ARB_sync

bool glextLoad_GL_ARB_sync()
{
	INIT_FUNC_PTR(glFenceSync);
	INIT_FUNC_PTR(glIsSync);
	INIT_FUNC_PTR(glDeleteSync);
	INIT_FUNC_PTR(glClientWaitSync);
	INIT_FUNC_PTR(glWaitSync);
	INIT_FUNC_PTR(glGetInteger64v);
	INIT_FUNC_PTR(glGetSynciv);

	return true;
}

// GL_ARB_texture_multisample

bool glextLoad_GL_ARB_texture_multisample()
{
	INIT_FUNC_PTR(glTexImage2DMultisample);
	INIT_FUNC_PTR(glTexImage3DMultisample);
	INIT_FUNC_PTR(glGetMultisamplefv);
	INIT_FUNC_PTR(glSampleMaski);

	return true;
}

// GL_ARB_blend_func_extended

bool glextLoad_GL_ARB_blend_func_extended()
{
	INIT_FUNC_PTR(glBindFragDataLocationIndexed);
	INIT_FUNC_PTR(glGetFragDataIndex);

	return true;
}

// GL_ARB_sampler_objects

bool glextLoad_GL_ARB_sampler_objects()
{
	INIT_FUNC_PTR(glGenSamplers);
	INIT_FUNC_PTR(glDeleteSamplers);
	INIT_FUNC_PTR(glIsSampler);
	INIT_FUNC_PTR(glBindSampler);
	INIT_FUNC_PTR(glSamplerParameteri);
	INIT_FUNC_PTR(glSamplerParameteriv);
	INIT_FUNC_PTR(glSamplerParameterf);
	INIT_FUNC_PTR(glSamplerParameterfv);
	INIT_FUNC_PTR(glSamplerParameterIiv);
	INIT_FUNC_PTR(glSamplerParameterIuiv);
	INIT_FUNC_PTR(glGetSamplerParameteriv);
	INIT_FUNC_PTR(glGetSamplerParameterIiv);
	INIT_FUNC_PTR(glGetSamplerParameterfv);
	INIT_FUNC_PTR(glGetSamplerParameterIuiv);

	return true;
}

// GL_ARB_timer_query

bool glextLoad_GL_ARB_timer_query()
{
	INIT_FUNC_PTR(glQueryCounter);
	INIT_FUNC_PTR(glGetQueryObjecti64v);
	INIT_FUNC_PTR(glGetQueryObjectui64v);

	return true;
}

// GL_ARB_draw_indirect

bool glextLoad_GL_ARB_draw_indirect()
{
	INIT_FUNC_PTR(glDrawArraysIndirect);
	INIT_FUNC_PTR(glDrawElementsIndirect);

	return true;
}

// GL_ARB_gpu_shader_fp64

bool glextLoad_GL_ARB_gpu_shader_fp64()
{
	INIT_FUNC_PTR(glUniform1d);
	INIT_FUNC_PTR(glUniform2d);
	INIT_FUNC_PTR(glUniform3d);
	INIT_FUNC_PTR(glUniform4d);
	INIT_FUNC_PTR(glUniform1dv);
	INIT_FUNC_PTR(glUniform2dv);
	INIT_FUNC_PTR(glUniform3dv);
	INIT_FUNC_PTR(glUniform4dv);
	INIT_FUNC_PTR(glUniformMatrix2dv);
	INIT_FUNC_PTR(glUniformMatrix3dv);
	INIT_FUNC_PTR(glUniformMatrix4dv);
	INIT_FUNC_PTR(glUniformMatrix2x3dv);
	INIT_FUNC_PTR(glUniformMatrix2x4dv);
	INIT_FUNC_PTR(glUniformMatrix3x2dv);
	INIT_FUNC_PTR(glUniformMatrix3x4dv);
	INIT_FUNC_PTR(glUniformMatrix4x2dv);
	INIT_FUNC_PTR(glUniformMatrix4x3dv);
	INIT_FUNC_PTR(glGetUniformdv);

	return true;
}

// GL_ARB_shader_subroutine

bool glextLoad_GL_ARB_shader_subroutine()
{
	INIT_FUNC_PTR(glGetSubroutineUniformLocation);
	INIT_FUNC_PTR(glGetSubroutineIndex);
	INIT_FUNC_PTR(glGetActiveSubroutineUniformiv);
	INIT_FUNC_PTR(glGetActiveSubroutineUniformName);
	INIT_FUNC_PTR(glGetActiveSubroutineName);
	INIT_FUNC_PTR(glUniformSubroutinesuiv);
	INIT_FUNC_PTR(glGetUniformSubroutineuiv);
	INIT_FUNC_PTR(glGetProgramStageiv);

	return true;
}

// GL_ARB_tessellation_shader

bool glextLoad_GL_ARB_tessellation_shader()
{
	INIT_FUNC_PTR(glPatchParameteri);
	INIT_FUNC_PTR(glPatchParameterfv);

	return true;
}

// GL_ARB_transform_feedback2

bool glextLoad_GL_ARB_transform_feedback2()
{
	INIT_FUNC_PTR(glBindTransformFeedback);
	INIT_FUNC_PTR(glDeleteTransformFeedbacks);
	INIT_FUNC_PTR(glGenTransformFeedbacks);
	INIT_FUNC_PTR(glIsTransformFeedback);
	INIT_FUNC_PTR(glPauseTransformFeedback);
	INIT_FUNC_PTR(glResumeTransformFeedback);
	INIT_FUNC_PTR(glDrawTransformFeedback);

	return true;
}

// GL_ARB_transform_feedback3

bool glextLoad_GL_ARB_transform_feedback3()
{
	INIT_FUNC_PTR(glDrawTransformFeedbackStream);
	INIT_FUNC_PTR(glBeginQueryIndexed);
	INIT_FUNC_PTR(glEndQueryIndexed);
	INIT_FUNC_PTR(glGetQueryIndexediv);

	return true;
}

// GL_ARB_ES2_compatibility

bool glextLoad_GL_ARB_ES2_compatibility()
{
	INIT_FUNC_PTR(glReleaseShaderCompiler);
	INIT_FUNC_PTR(glShaderBinary);
	INIT_FUNC_PTR(glGetShaderPrecisionFormat);
	INIT_FUNC_PTR(glDepthRangef);
	INIT_FUNC_PTR(glClearDepthf);

	return true;
}

// GL_ARB_get_program_binary

bool glextLoad_GL_ARB_get_program_binary()
{
	INIT_FUNC_PTR(glGetProgramBinary);
	INIT_FUNC_PTR(glProgramBinary);
	INIT_FUNC_PTR(glProgramParameteri);

	return true;
}

// GL_ARB_separate_shader_objects

bool glextLoad_GL_ARB_separate_shader_objects()
{
	INIT_FUNC_PTR(glUseProgramStages);
	INIT_FUNC_PTR(glActiveShaderProgram);
	INIT_FUNC_PTR(glCreateShaderProgramv);
	INIT_FUNC_PTR(glBindProgramPipeline);
	INIT_FUNC_PTR(glDeleteProgramPipelines);
	INIT_FUNC_PTR(glGenProgramPipelines);
	INIT_FUNC_PTR(glIsProgramPipeline);
	INIT_FUNC_PTR(glGetProgramPipelineiv);
	INIT_FUNC_PTR(glProgramUniform1i);
	INIT_FUNC_PTR(glProgramUniform1iv);
	INIT_FUNC_PTR(glProgramUniform1f);
	INIT_FUNC_PTR(glProgramUniform1fv);
	INIT_FUNC_PTR(glProgramUniform1d);
	INIT_FUNC_PTR(glProgramUniform1dv);
	INIT_FUNC_PTR(glProgramUniform1ui);
	INIT_FUNC_PTR(glProgramUniform1uiv);
	INIT_FUNC_PTR(glProgramUniform2i);
	INIT_FUNC_PTR(glProgramUniform2iv);
	INIT_FUNC_PTR(glProgramUniform2f);
	INIT_FUNC_PTR(glProgramUniform2fv);
	INIT_FUNC_PTR(glProgramUniform2d);
	INIT_FUNC_PTR(glProgramUniform2dv);
	INIT_FUNC_PTR(glProgramUniform2ui);
	INIT_FUNC_PTR(glProgramUniform2uiv);
	INIT_FUNC_PTR(glProgramUniform3i);
	INIT_FUNC_PTR(glProgramUniform3iv);
	INIT_FUNC_PTR(glProgramUniform3f);
	INIT_FUNC_PTR(glProgramUniform3fv);
	INIT_FUNC_PTR(glProgramUniform3d);
	INIT_FUNC_PTR(glProgramUniform3dv);
	INIT_FUNC_PTR(glProgramUniform3ui);
	INIT_FUNC_PTR(glProgramUniform3uiv);
	INIT_FUNC_PTR(glProgramUniform4i);
	INIT_FUNC_PTR(glProgramUniform4iv);
	INIT_FUNC_PTR(glProgramUniform4f);
	INIT_FUNC_PTR(glProgramUniform4fv);
	INIT_FUNC_PTR(glProgramUniform4d);
	INIT_FUNC_PTR(glProgramUniform4dv);
	INIT_FUNC_PTR(glProgramUniform4ui);
	INIT_FUNC_PTR(glProgramUniform4uiv);
	INIT_FUNC_PTR(glProgramUniformMatrix2fv);
	INIT_FUNC_PTR(glProgramUniformMatrix3fv);
	INIT_FUNC_PTR(glProgramUniformMatrix4fv);
	INIT_FUNC_PTR(glProgramUniformMatrix2dv);
	INIT_FUNC_PTR(glProgramUniformMatrix3dv);
	INIT_FUNC_PTR(glProgramUniformMatrix4dv);
	INIT_FUNC_PTR(glProgramUniformMatrix2x3fv);
	INIT_FUNC_PTR(glProgramUniformMatrix3x2fv);
	INIT_FUNC_PTR(glProgramUniformMatrix2x4fv);
	INIT_FUNC_PTR(glProgramUniformMatrix4x2fv);
	INIT_FUNC_PTR(glProgramUniformMatrix3x4fv);
	INIT_FUNC_PTR(glProgramUniformMatrix4x3fv);
	INIT_FUNC_PTR(glProgramUniformMatrix2x3dv);
	INIT_FUNC_PTR(glProgramUniformMatrix3x2dv);
	INIT_FUNC_PTR(glProgramUniformMatrix2x4dv);
	INIT_FUNC_PTR(glProgramUniformMatrix4x2dv);
	INIT_FUNC_PTR(glProgramUniformMatrix3x4dv);
	INIT_FUNC_PTR(glProgramUniformMatrix4x3dv);
	INIT_FUNC_PTR(glValidateProgramPipeline);
	INIT_FUNC_PTR(glGetProgramPipelineInfoLog);

	return true;
}

// GL_ARB_vertex_attrib_64bit

bool glextLoad_GL_ARB_vertex_attrib_64bit()
{
	INIT_FUNC_PTR(glVertexAttribL1d);
	INIT_FUNC_PTR(glVertexAttribL2d);
	INIT_FUNC_PTR(glVertexAttribL3d);
	INIT_FUNC_PTR(glVertexAttribL4d);
	INIT_FUNC_PTR(glVertexAttribL1dv);
	INIT_FUNC_PTR(glVertexAttribL2dv);
	INIT_FUNC_PTR(glVertexAttribL3dv);
	INIT_FUNC_PTR(glVertexAttribL4dv);
	INIT_FUNC_PTR(glVertexAttribLPointer);
	INIT_FUNC_PTR(glGetVertexAttribLdv);

	return true;
}

// GL_ARB_viewport_array

bool glextLoad_GL_ARB_viewport_array()
{
	INIT_FUNC_PTR(glViewportArrayv);
	INIT_FUNC_PTR(glViewportIndexedf);
	INIT_FUNC_PTR(glViewportIndexedfv);
	INIT_FUNC_PTR(glScissorArrayv);
	INIT_FUNC_PTR(glScissorIndexed);
	INIT_FUNC_PTR(glScissorIndexedv);
	INIT_FUNC_PTR(glDepthRangeArrayv);
	INIT_FUNC_PTR(glDepthRangeIndexed);
	INIT_FUNC_PTR(glGetFloati_v);
	INIT_FUNC_PTR(glGetDoublei_v);

	return true;
}

// GL_ARB_base_instance

bool glextLoad_GL_ARB_base_instance()
{
	INIT_FUNC_PTR(glDrawArraysInstancedBaseInstance);
	INIT_FUNC_PTR(glDrawElementsInstancedBaseInstance);
	INIT_FUNC_PTR(glDrawElementsInstancedBaseVertexBaseInstance);

	return true;
}

// GL_ARB_transform_feedback_instanced

bool glextLoad_GL_ARB_transform_feedback_instanced()
{
	INIT_FUNC_PTR(glDrawTransformFeedbackInstanced);
	INIT_FUNC_PTR(glDrawTransformFeedbackStreamInstanced);

	return true;
}

// GL_ARB_internalformat_query

bool glextLoad_GL_ARB_internalformat_query()
{
	INIT_FUNC_PTR(glGetInternalformativ);

	return true;
}

// GL_ARB_shader_atomic_counters

bool glextLoad_GL_ARB_shader_atomic_counters()
{
	INIT_FUNC_PTR(glGetActiveAtomicCounterBufferiv);

	return true;
}

// GL_ARB_shader_image_load_store

bool glextLoad_GL_ARB_shader_image_load_store()
{
	INIT_FUNC_PTR(glBindImageTexture);
	INIT_FUNC_PTR(glMemoryBarrier);

	return true;
}

// GL_ARB_texture_storage

bool glextLoad_GL_ARB_texture_storage()
{
	INIT_FUNC_PTR(glTexStorage1D);
	INIT_FUNC_PTR(glTexStorage2D);
	INIT_FUNC_PTR(glTexStorage3D);
	INIT_FUNC_PTR(glTextureStorage1DEXT);
	INIT_FUNC_PTR(glTextureStorage2DEXT);
	INIT_FUNC_PTR(glTextureStorage3DEXT);

	return true;
}

// GL_KHR_debug

bool glextLoad_GL_KHR_debug()
{
	INIT_FUNC_PTR(glDebugMessageControl);
	INIT_FUNC_PTR(glDebugMessageInsert);
	INIT_FUNC_PTR(glDebugMessageCallback);
	INIT_FUNC_PTR(glGetDebugMessageLog);
	INIT_FUNC_PTR(glPushDebugGroup);
	INIT_FUNC_PTR(glPopDebugGroup);
	INIT_FUNC_PTR(glObjectLabel);
	INIT_FUNC_PTR(glGetObjectLabel);
	INIT_FUNC_PTR(glObjectPtrLabel);
	INIT_FUNC_PTR(glGetObjectPtrLabel);

	return true;
}

// GL_ARB_clear_buffer_object

bool glextLoad_GL_ARB_clear_buffer_object()
{
	INIT_FUNC_PTR(glClearBufferData);
	INIT_FUNC_PTR(glClearBufferSubData);
	INIT_FUNC_PTR(glClearNamedBufferDataEXT);
	INIT_FUNC_PTR(glClearNamedBufferSubDataEXT);

	return true;
}

// GL_ARB_compute_shader

bool glextLoad_GL_ARB_compute_shader()
{
	INIT_FUNC_PTR(glDispatchCompute);
	INIT_FUNC_PTR(glDispatchComputeIndirect);

	return true;
}

// GL_ARB_copy_image

bool glextLoad_GL_ARB_copy_image()
{
	INIT_FUNC_PTR(glCopyImageSubData);

	return true;
}

// GL_ARB_texture_view

bool glextLoad_GL_ARB_texture_view()
{
	INIT_FUNC_PTR(glTextureView);

	return true;
}

// GL_ARB_vertex_attrib_binding

bool glextLoad_GL_ARB_vertex_attrib_binding()
{
	INIT_FUNC_PTR(glBindVertexBuffer);
	INIT_FUNC_PTR(glVertexAttribFormat);
	INIT_FUNC_PTR(glVertexAttribIFormat);
	INIT_FUNC_PTR(glVertexAttribLFormat);
	INIT_FUNC_PTR(glVertexAttribBinding);
	INIT_FUNC_PTR(glVertexBindingDivisor);
	INIT_FUNC_PTR(glVertexArrayBindVertexBufferEXT);
	INIT_FUNC_PTR(glVertexArrayVertexAttribFormatEXT);
	INIT_FUNC_PTR(glVertexArrayVertexAttribIFormatEXT);
	INIT_FUNC_PTR(glVertexArrayVertexAttribLFormatEXT);
	INIT_FUNC_PTR(glVertexArrayVertexAttribBindingEXT);
	INIT_FUNC_PTR(glVertexArrayVertexBindingDivisorEXT);

	return true;
}

// GL_ARB_framebuffer_no_attachments

bool glextLoad_GL_ARB_framebuffer_no_attachments()
{
	INIT_FUNC_PTR(glFramebufferParameteri);
	INIT_FUNC_PTR(glGetFramebufferParameteriv);
	INIT_FUNC_PTR(glNamedFramebufferParameteriEXT);
	INIT_FUNC_PTR(glGetNamedFramebufferParameterivEXT);

	return true;
}

// GL_ARB_internalformat_query2

bool glextLoad_GL_ARB_internalformat_query2()
{
	INIT_FUNC_PTR(glGetInternalformati64v);

	return true;
}

// GL_ARB_invalidate_subdata

bool glextLoad_GL_ARB_invalidate_subdata()
{
	INIT_FUNC_PTR(glInvalidateTexSubImage);
	INIT_FUNC_PTR(glInvalidateTexImage);
	INIT_FUNC_PTR(glInvalidateBufferSubData);
	INIT_FUNC_PTR(glInvalidateBufferData);
	INIT_FUNC_PTR(glInvalidateFramebuffer);
	INIT_FUNC_PTR(glInvalidateSubFramebuffer);

	return true;
}

// GL_ARB_multi_draw_indirect

bool glextLoad_GL_ARB_multi_draw_indirect()
{
	INIT_FUNC_PTR(glMultiDrawArraysIndirect);
	INIT_FUNC_PTR(glMultiDrawElementsIndirect);

	return true;
}

// GL_ARB_program_interface_query

bool glextLoad_GL_ARB_program_interface_query()
{
	INIT_FUNC_PTR(glGetProgramInterfaceiv);
	INIT_FUNC_PTR(glGetProgramResourceIndex);
	INIT_FUNC_PTR(glGetProgramResourceName);
	INIT_FUNC_PTR(glGetProgramResourceiv);
	INIT_FUNC_PTR(glGetProgramResourceLocation);
	INIT_FUNC_PTR(glGetProgramResourceLocationIndex);

	return true;
}

// GL_ARB_shader_storage_buffer_object

bool glextLoad_GL_ARB_shader_storage_buffer_object()
{
	INIT_FUNC_PTR(glShaderStorageBlockBinding);

	return true;
}

// GL_ARB_texture_buffer_range

bool glextLoad_GL_ARB_texture_buffer_range()
{
	INIT_FUNC_PTR(glTexBufferRange);
	INIT_FUNC_PTR(glTextureBufferRangeEXT);

	return true;
}

// GL_ARB_texture_storage_multisample

bool glextLoad_GL_ARB_texture_storage_multisample()
{
	INIT_FUNC_PTR(glTexStorage2DMultisample);
	INIT_FUNC_PTR(glTexStorage3DMultisample);
	INIT_FUNC_PTR(glTextureStorage2DMultisampleEXT);
	INIT_FUNC_PTR(glTextureStorage3DMultisampleEXT);

	return true;
}
