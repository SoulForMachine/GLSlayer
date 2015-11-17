
// GL_VERSION_1_2

inline void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels)
{
	assert(ptr_glTexSubImage3D);
	ptr_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	assert(ptr_glCopyTexSubImage3D);
	ptr_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_VERSION_1_3

inline void glActiveTexture(GLenum texture)
{
	assert(ptr_glActiveTexture);
	ptr_glActiveTexture(texture);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glSampleCoverage(GLfloat value, GLboolean invert)
{
	assert(ptr_glSampleCoverage);
	ptr_glSampleCoverage(value, invert);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data)
{
	assert(ptr_glCompressedTexSubImage3D);
	ptr_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)
{
	assert(ptr_glCompressedTexSubImage2D);
	ptr_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data)
{
	assert(ptr_glCompressedTexSubImage1D);
	ptr_glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetCompressedTexImage(GLenum target, GLint level, void *img)
{
	assert(ptr_glGetCompressedTexImage);
	ptr_glGetCompressedTexImage(target, level, img);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_VERSION_1_4

inline void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
	assert(ptr_glBlendFuncSeparate);
	ptr_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	assert(ptr_glBlendColor);
	ptr_glBlendColor(red, green, blue, alpha);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBlendEquation(GLenum mode)
{
	assert(ptr_glBlendEquation);
	ptr_glBlendEquation(mode);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_VERSION_1_5

inline void glGenQueries(GLsizei n, GLuint *ids)
{
	assert(ptr_glGenQueries);
	ptr_glGenQueries(n, ids);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDeleteQueries(GLsizei n, const GLuint *ids)
{
	assert(ptr_glDeleteQueries);
	ptr_glDeleteQueries(n, ids);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBeginQuery(GLenum target, GLuint id)
{
	assert(ptr_glBeginQuery);
	ptr_glBeginQuery(target, id);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glEndQuery(GLenum target)
{
	assert(ptr_glEndQuery);
	ptr_glEndQuery(target);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params)
{
	assert(ptr_glGetQueryObjectiv);
	ptr_glGetQueryObjectiv(id, pname, params);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params)
{
	assert(ptr_glGetQueryObjectuiv);
	ptr_glGetQueryObjectuiv(id, pname, params);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBindBuffer(GLenum target, GLuint buffer)
{
	assert(ptr_glBindBuffer);
	ptr_glBindBuffer(target, buffer);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDeleteBuffers(GLsizei n, const GLuint *buffers)
{
	assert(ptr_glDeleteBuffers);
	ptr_glDeleteBuffers(n, buffers);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGenBuffers(GLsizei n, GLuint *buffers)
{
	assert(ptr_glGenBuffers);
	ptr_glGenBuffers(n, buffers);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage)
{
	assert(ptr_glBufferData);
	ptr_glBufferData(target, size, data, usage);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data)
{
	assert(ptr_glBufferSubData);
	ptr_glBufferSubData(target, offset, size, data);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void *data)
{
	assert(ptr_glGetBufferSubData);
	ptr_glGetBufferSubData(target, offset, size, data);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void *glMapBuffer(GLenum target, GLenum access)
{
	assert(ptr_glMapBuffer);
	void *result;
	result = ptr_glMapBuffer(target, access);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
	return result;
}

inline GLboolean glUnmapBuffer(GLenum target)
{
	assert(ptr_glUnmapBuffer);
	GLboolean result;
	result = ptr_glUnmapBuffer(target);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
	return result;
}

// GL_VERSION_2_0

inline void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
	assert(ptr_glBlendEquationSeparate);
	ptr_glBlendEquationSeparate(modeRGB, modeAlpha);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDrawBuffers(GLsizei n, const GLenum *bufs)
{
	assert(ptr_glDrawBuffers);
	ptr_glDrawBuffers(n, bufs);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
	assert(ptr_glStencilOpSeparate);
	ptr_glStencilOpSeparate(face, sfail, dpfail, dppass);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
	assert(ptr_glStencilFuncSeparate);
	ptr_glStencilFuncSeparate(face, func, ref, mask);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glStencilMaskSeparate(GLenum face, GLuint mask)
{
	assert(ptr_glStencilMaskSeparate);
	ptr_glStencilMaskSeparate(face, mask);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glAttachShader(GLuint program, GLuint shader)
{
	assert(ptr_glAttachShader);
	ptr_glAttachShader(program, shader);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glCompileShader(GLuint shader)
{
	assert(ptr_glCompileShader);
	ptr_glCompileShader(shader);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline GLuint glCreateProgram()
{
	assert(ptr_glCreateProgram);
	GLuint result;
	result = ptr_glCreateProgram();
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
	return result;
}

inline GLuint glCreateShader(GLenum type)
{
	assert(ptr_glCreateShader);
	GLuint result;
	result = ptr_glCreateShader(type);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
	return result;
}

inline void glDeleteProgram(GLuint program)
{
	assert(ptr_glDeleteProgram);
	ptr_glDeleteProgram(program);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDeleteShader(GLuint shader)
{
	assert(ptr_glDeleteShader);
	ptr_glDeleteShader(shader);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDetachShader(GLuint program, GLuint shader)
{
	assert(ptr_glDetachShader);
	ptr_glDetachShader(program, shader);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDisableVertexAttribArray(GLuint index)
{
	assert(ptr_glDisableVertexAttribArray);
	ptr_glDisableVertexAttribArray(index);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glEnableVertexAttribArray(GLuint index)
{
	assert(ptr_glEnableVertexAttribArray);
	ptr_glEnableVertexAttribArray(index);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetProgramiv(GLuint program, GLenum pname, GLint *params)
{
	assert(ptr_glGetProgramiv);
	ptr_glGetProgramiv(program, pname, params);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	assert(ptr_glGetProgramInfoLog);
	ptr_glGetProgramInfoLog(program, bufSize, length, infoLog);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetShaderiv(GLuint shader, GLenum pname, GLint *params)
{
	assert(ptr_glGetShaderiv);
	ptr_glGetShaderiv(shader, pname, params);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	assert(ptr_glGetShaderInfoLog);
	ptr_glGetShaderInfoLog(shader, bufSize, length, infoLog);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glLinkProgram(GLuint program)
{
	assert(ptr_glLinkProgram);
	ptr_glLinkProgram(program);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length)
{
	assert(ptr_glShaderSource);
	ptr_glShaderSource(shader, count, string, length);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glValidateProgram(GLuint program)
{
	assert(ptr_glValidateProgram);
	ptr_glValidateProgram(program);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
{
	assert(ptr_glVertexAttribPointer);
	ptr_glVertexAttribPointer(index, size, type, normalized, stride, pointer);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_VERSION_2_1

// GL_VERSION_3_0

inline void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
{
	assert(ptr_glColorMaski);
	ptr_glColorMaski(index, r, g, b, a);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetIntegeri_v(GLenum target, GLuint index, GLint *data)
{
	assert(ptr_glGetIntegeri_v);
	ptr_glGetIntegeri_v(target, index, data);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glEnablei(GLenum target, GLuint index)
{
	assert(ptr_glEnablei);
	ptr_glEnablei(target, index);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDisablei(GLenum target, GLuint index)
{
	assert(ptr_glDisablei);
	ptr_glDisablei(target, index);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBeginTransformFeedback(GLenum primitiveMode)
{
	assert(ptr_glBeginTransformFeedback);
	ptr_glBeginTransformFeedback(primitiveMode);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glEndTransformFeedback()
{
	assert(ptr_glEndTransformFeedback);
	ptr_glEndTransformFeedback();
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
	assert(ptr_glBindBufferRange);
	ptr_glBindBufferRange(target, index, buffer, offset, size);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBindBufferBase(GLenum target, GLuint index, GLuint buffer)
{
	assert(ptr_glBindBufferBase);
	ptr_glBindBufferBase(target, index, buffer);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode)
{
	assert(ptr_glTransformFeedbackVaryings);
	ptr_glTransformFeedbackVaryings(program, count, varyings, bufferMode);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glClampColor(GLenum target, GLenum clamp)
{
	assert(ptr_glClampColor);
	ptr_glClampColor(target, clamp);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBeginConditionalRender(GLuint id, GLenum mode)
{
	assert(ptr_glBeginConditionalRender);
	ptr_glBeginConditionalRender(id, mode);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glEndConditionalRender()
{
	assert(ptr_glEndConditionalRender);
	ptr_glEndConditionalRender();
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)
{
	assert(ptr_glVertexAttribIPointer);
	ptr_glVertexAttribIPointer(index, size, type, stride, pointer);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value)
{
	assert(ptr_glClearBufferiv);
	ptr_glClearBufferiv(buffer, drawbuffer, value);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value)
{
	assert(ptr_glClearBufferuiv);
	ptr_glClearBufferuiv(buffer, drawbuffer, value);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value)
{
	assert(ptr_glClearBufferfv);
	ptr_glClearBufferfv(buffer, drawbuffer, value);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
{
	assert(ptr_glClearBufferfi);
	ptr_glClearBufferfi(buffer, drawbuffer, depth, stencil);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_framebuffer_object

inline void glBindRenderbuffer(GLenum target, GLuint renderbuffer)
{
	assert(ptr_glBindRenderbuffer);
	ptr_glBindRenderbuffer(target, renderbuffer);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers)
{
	assert(ptr_glDeleteRenderbuffers);
	ptr_glDeleteRenderbuffers(n, renderbuffers);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers)
{
	assert(ptr_glGenRenderbuffers);
	ptr_glGenRenderbuffers(n, renderbuffers);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBindFramebuffer(GLenum target, GLuint framebuffer)
{
	assert(ptr_glBindFramebuffer);
	ptr_glBindFramebuffer(target, framebuffer);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers)
{
	assert(ptr_glDeleteFramebuffers);
	ptr_glDeleteFramebuffers(n, framebuffers);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGenFramebuffers(GLsizei n, GLuint *framebuffers)
{
	assert(ptr_glGenFramebuffers);
	ptr_glGenFramebuffers(n, framebuffers);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline GLenum glCheckFramebufferStatus(GLenum target)
{
	assert(ptr_glCheckFramebufferStatus);
	GLenum result;
	result = ptr_glCheckFramebufferStatus(target);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
	return result;
}

inline void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	assert(ptr_glFramebufferTexture2D);
	ptr_glFramebufferTexture2D(target, attachment, textarget, texture, level);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
	assert(ptr_glFramebufferRenderbuffer);
	ptr_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGenerateMipmap(GLenum target)
{
	assert(ptr_glGenerateMipmap);
	ptr_glGenerateMipmap(target);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
{
	assert(ptr_glBlitFramebuffer);
	ptr_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
{
	assert(ptr_glRenderbufferStorageMultisample);
	ptr_glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
	assert(ptr_glFramebufferTextureLayer);
	ptr_glFramebufferTextureLayer(target, attachment, texture, level, layer);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_map_buffer_range

inline void *glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
	assert(ptr_glMapBufferRange);
	void *result;
	result = ptr_glMapBufferRange(target, offset, length, access);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
	return result;
}

inline void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length)
{
	assert(ptr_glFlushMappedBufferRange);
	ptr_glFlushMappedBufferRange(target, offset, length);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_vertex_array_object

inline void glBindVertexArray(GLuint array)
{
	assert(ptr_glBindVertexArray);
	ptr_glBindVertexArray(array);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGenVertexArrays(GLsizei n, GLuint *arrays)
{
	assert(ptr_glGenVertexArrays);
	ptr_glGenVertexArrays(n, arrays);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_VERSION_3_1

inline void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer)
{
	assert(ptr_glTexBuffer);
	ptr_glTexBuffer(target, internalformat, buffer);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glPrimitiveRestartIndex(GLuint index)
{
	assert(ptr_glPrimitiveRestartIndex);
	ptr_glPrimitiveRestartIndex(index);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_copy_buffer

inline void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
{
	assert(ptr_glCopyBufferSubData);
	ptr_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_VERSION_3_2

// GL_ARB_draw_elements_base_vertex

inline void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex)
{
	assert(ptr_glDrawElementsBaseVertex);
	ptr_glDrawElementsBaseVertex(mode, count, type, indices, basevertex);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex)
{
	assert(ptr_glDrawRangeElementsBaseVertex);
	ptr_glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_provoking_vertex

inline void glProvokingVertex(GLenum mode)
{
	assert(ptr_glProvokingVertex);
	ptr_glProvokingVertex(mode);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_sync

inline GLsync glFenceSync(GLenum condition, GLbitfield flags)
{
	assert(ptr_glFenceSync);
	GLsync result;
	result = ptr_glFenceSync(condition, flags);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
	return result;
}

inline void glDeleteSync(GLsync sync)
{
	assert(ptr_glDeleteSync);
	ptr_glDeleteSync(sync);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
	assert(ptr_glClientWaitSync);
	GLenum result;
	result = ptr_glClientWaitSync(sync, flags, timeout);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
	return result;
}

inline void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
	assert(ptr_glWaitSync);
	ptr_glWaitSync(sync, flags, timeout);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetInteger64v(GLenum pname, GLint64 *data)
{
	assert(ptr_glGetInteger64v);
	ptr_glGetInteger64v(pname, data);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_texture_multisample

inline void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
	assert(ptr_glFramebufferTexture);
	ptr_glFramebufferTexture(target, attachment, texture, level);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val)
{
	assert(ptr_glGetMultisamplefv);
	ptr_glGetMultisamplefv(pname, index, val);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glSampleMaski(GLuint maskNumber, GLbitfield mask)
{
	assert(ptr_glSampleMaski);
	ptr_glSampleMaski(maskNumber, mask);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_VERSION_3_3

// GL_ARB_sampler_objects

inline void glGenSamplers(GLsizei count, GLuint *samplers)
{
	assert(ptr_glGenSamplers);
	ptr_glGenSamplers(count, samplers);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDeleteSamplers(GLsizei count, const GLuint *samplers)
{
	assert(ptr_glDeleteSamplers);
	ptr_glDeleteSamplers(count, samplers);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBindSampler(GLuint unit, GLuint sampler)
{
	assert(ptr_glBindSampler);
	ptr_glBindSampler(unit, sampler);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param)
{
	assert(ptr_glSamplerParameteri);
	ptr_glSamplerParameteri(sampler, pname, param);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param)
{
	assert(ptr_glSamplerParameterf);
	ptr_glSamplerParameterf(sampler, pname, param);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param)
{
	assert(ptr_glSamplerParameterfv);
	ptr_glSamplerParameterfv(sampler, pname, param);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_timer_query

inline void glQueryCounter(GLuint id, GLenum target)
{
	assert(ptr_glQueryCounter);
	ptr_glQueryCounter(id, target);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params)
{
	assert(ptr_glGetQueryObjectui64v);
	ptr_glGetQueryObjectui64v(id, pname, params);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_vertex_type_2_10_10_10_rev

inline void glVertexAttribDivisor(GLuint index, GLuint divisor)
{
	assert(ptr_glVertexAttribDivisor);
	ptr_glVertexAttribDivisor(index, divisor);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_VERSION_4_0

inline void glMinSampleShading(GLfloat value)
{
	assert(ptr_glMinSampleShading);
	ptr_glMinSampleShading(value);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBlendEquationi(GLuint buf, GLenum mode)
{
	assert(ptr_glBlendEquationi);
	ptr_glBlendEquationi(buf, mode);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
	assert(ptr_glBlendEquationSeparatei);
	ptr_glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBlendFunci(GLuint buf, GLenum src, GLenum dst)
{
	assert(ptr_glBlendFunci);
	ptr_glBlendFunci(buf, src, dst);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
	assert(ptr_glBlendFuncSeparatei);
	ptr_glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_draw_indirect

inline void glDrawArraysIndirect(GLenum mode, const void *indirect)
{
	assert(ptr_glDrawArraysIndirect);
	ptr_glDrawArraysIndirect(mode, indirect);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect)
{
	assert(ptr_glDrawElementsIndirect);
	ptr_glDrawElementsIndirect(mode, type, indirect);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_shader_subroutine

inline GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name)
{
	assert(ptr_glGetSubroutineIndex);
	GLuint result;
	result = ptr_glGetSubroutineIndex(program, shadertype, name);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
	return result;
}

inline void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices)
{
	assert(ptr_glUniformSubroutinesuiv);
	ptr_glUniformSubroutinesuiv(shadertype, count, indices);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_tessellation_shader

inline void glPatchParameteri(GLenum pname, GLint value)
{
	assert(ptr_glPatchParameteri);
	ptr_glPatchParameteri(pname, value);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glPatchParameterfv(GLenum pname, const GLfloat *values)
{
	assert(ptr_glPatchParameterfv);
	ptr_glPatchParameterfv(pname, values);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_transform_feedback2

inline void glBindTransformFeedback(GLenum target, GLuint id)
{
	assert(ptr_glBindTransformFeedback);
	ptr_glBindTransformFeedback(target, id);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids)
{
	assert(ptr_glDeleteTransformFeedbacks);
	ptr_glDeleteTransformFeedbacks(n, ids);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGenTransformFeedbacks(GLsizei n, GLuint *ids)
{
	assert(ptr_glGenTransformFeedbacks);
	ptr_glGenTransformFeedbacks(n, ids);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glPauseTransformFeedback()
{
	assert(ptr_glPauseTransformFeedback);
	ptr_glPauseTransformFeedback();
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glResumeTransformFeedback()
{
	assert(ptr_glResumeTransformFeedback);
	ptr_glResumeTransformFeedback();
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_transform_feedback3

inline void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream)
{
	assert(ptr_glDrawTransformFeedbackStream);
	ptr_glDrawTransformFeedbackStream(mode, id, stream);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id)
{
	assert(ptr_glBeginQueryIndexed);
	ptr_glBeginQueryIndexed(target, index, id);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_VERSION_4_1

// GL_ARB_get_program_binary

inline void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary)
{
	assert(ptr_glGetProgramBinary);
	ptr_glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length)
{
	assert(ptr_glProgramBinary);
	ptr_glProgramBinary(program, binaryFormat, binary, length);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glProgramParameteri(GLuint program, GLenum pname, GLint value)
{
	assert(ptr_glProgramParameteri);
	ptr_glProgramParameteri(program, pname, value);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_separate_shader_objects

inline void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program)
{
	assert(ptr_glUseProgramStages);
	ptr_glUseProgramStages(pipeline, stages, program);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const*strings)
{
	assert(ptr_glCreateShaderProgramv);
	GLuint result;
	result = ptr_glCreateShaderProgramv(type, count, strings);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
	return result;
}

inline void glBindProgramPipeline(GLuint pipeline)
{
	assert(ptr_glBindProgramPipeline);
	ptr_glBindProgramPipeline(pipeline);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGenProgramPipelines(GLsizei n, GLuint *pipelines)
{
	assert(ptr_glGenProgramPipelines);
	ptr_glGenProgramPipelines(n, pipelines);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params)
{
	assert(ptr_glGetProgramPipelineiv);
	ptr_glGetProgramPipelineiv(pipeline, pname, params);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glValidateProgramPipeline(GLuint pipeline)
{
	assert(ptr_glValidateProgramPipeline);
	ptr_glValidateProgramPipeline(pipeline);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_vertex_attrib_64bit

inline void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)
{
	assert(ptr_glVertexAttribLPointer);
	ptr_glVertexAttribLPointer(index, size, type, stride, pointer);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_viewport_array

inline void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
	assert(ptr_glViewportIndexedf);
	ptr_glViewportIndexedf(index, x, y, w, h);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)
{
	assert(ptr_glScissorIndexed);
	ptr_glScissorIndexed(index, left, bottom, width, height);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f)
{
	assert(ptr_glDepthRangeIndexed);
	ptr_glDepthRangeIndexed(index, n, f);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glGetFloati_v(GLenum target, GLuint index, GLfloat *data)
{
	assert(ptr_glGetFloati_v);
	ptr_glGetFloati_v(target, index, data);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_VERSION_4_2

// GL_ARB_base_instance

inline void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance)
{
	assert(ptr_glDrawArraysInstancedBaseInstance);
	ptr_glDrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance)
{
	assert(ptr_glDrawElementsInstancedBaseVertexBaseInstance);
	ptr_glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_transform_feedback_instanced

inline void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount)
{
	assert(ptr_glDrawTransformFeedbackStreamInstanced);
	ptr_glDrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_internalformat_query

inline void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params)
{
	assert(ptr_glGetInternalformativ);
	ptr_glGetInternalformativ(target, internalformat, pname, bufSize, params);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_shader_image_load_store

inline void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)
{
	assert(ptr_glBindImageTexture);
	ptr_glBindImageTexture(unit, texture, level, layered, layer, access, format);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glMemoryBarrier(GLbitfield barriers)
{
	assert(ptr_glMemoryBarrier);
	ptr_glMemoryBarrier(barriers);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_texture_storage

inline void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)
{
	assert(ptr_glTexStorage1D);
	ptr_glTexStorage1D(target, levels, internalformat, width);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
	assert(ptr_glTexStorage2D);
	ptr_glTexStorage2D(target, levels, internalformat, width, height);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
	assert(ptr_glTexStorage3D);
	ptr_glTexStorage3D(target, levels, internalformat, width, height, depth);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_VERSION_4_3

// GL_ARB_clear_buffer_object

inline void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data)
{
	assert(ptr_glClearBufferData);
	ptr_glClearBufferData(target, internalformat, format, type, data);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data)
{
	assert(ptr_glClearBufferSubData);
	ptr_glClearBufferSubData(target, internalformat, offset, size, format, type, data);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_compute_shader

inline void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)
{
	assert(ptr_glDispatchCompute);
	ptr_glDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDispatchComputeIndirect(GLintptr indirect)
{
	assert(ptr_glDispatchComputeIndirect);
	ptr_glDispatchComputeIndirect(indirect);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_copy_image

inline void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)
{
	assert(ptr_glCopyImageSubData);
	ptr_glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_KHR_debug

inline void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled)
{
	assert(ptr_glDebugMessageControl);
	ptr_glDebugMessageControl(source, type, severity, count, ids, enabled);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf)
{
	assert(ptr_glDebugMessageInsert);
	ptr_glDebugMessageInsert(source, type, id, severity, length, buf);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glDebugMessageCallback(GLDEBUGPROC callback, const void *userParam)
{
	assert(ptr_glDebugMessageCallback);
	ptr_glDebugMessageCallback(callback, userParam);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message)
{
	assert(ptr_glPushDebugGroup);
	ptr_glPushDebugGroup(source, id, length, message);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glPopDebugGroup()
{
	assert(ptr_glPopDebugGroup);
	ptr_glPopDebugGroup();
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar *label)
{
	assert(ptr_glObjectLabel);
	ptr_glObjectLabel(identifier, name, length, label);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glObjectPtrLabel(const void *ptr, GLsizei length, const GLchar *label)
{
	assert(ptr_glObjectPtrLabel);
	ptr_glObjectPtrLabel(ptr, length, label);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_framebuffer_no_attachments

inline void glFramebufferParameteri(GLenum target, GLenum pname, GLint param)
{
	assert(ptr_glFramebufferParameteri);
	ptr_glFramebufferParameteri(target, pname, param);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_internalformat_query2

inline void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params)
{
	assert(ptr_glGetInternalformati64v);
	ptr_glGetInternalformati64v(target, internalformat, pname, bufSize, params);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_invalidate_subdata

inline void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth)
{
	assert(ptr_glInvalidateTexSubImage);
	ptr_glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glInvalidateTexImage(GLuint texture, GLint level)
{
	assert(ptr_glInvalidateTexImage);
	ptr_glInvalidateTexImage(texture, level);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length)
{
	assert(ptr_glInvalidateBufferSubData);
	ptr_glInvalidateBufferSubData(buffer, offset, length);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glInvalidateBufferData(GLuint buffer)
{
	assert(ptr_glInvalidateBufferData);
	ptr_glInvalidateBufferData(buffer);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments)
{
	assert(ptr_glInvalidateFramebuffer);
	ptr_glInvalidateFramebuffer(target, numAttachments, attachments);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height)
{
	assert(ptr_glInvalidateSubFramebuffer);
	ptr_glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_multi_draw_indirect

inline void glMultiDrawArraysIndirect(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride)
{
	assert(ptr_glMultiDrawArraysIndirect);
	ptr_glMultiDrawArraysIndirect(mode, indirect, drawcount, stride);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride)
{
	assert(ptr_glMultiDrawElementsIndirect);
	ptr_glMultiDrawElementsIndirect(mode, type, indirect, drawcount, stride);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_texture_buffer_range

inline void glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
	assert(ptr_glTexBufferRange);
	ptr_glTexBufferRange(target, internalformat, buffer, offset, size);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_texture_storage_multisample

inline void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
{
	assert(ptr_glTexStorage2DMultisample);
	ptr_glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
{
	assert(ptr_glTexStorage3DMultisample);
	ptr_glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_texture_view

inline void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)
{
	assert(ptr_glTextureView);
	ptr_glTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_ARB_vertex_attrib_binding

inline void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
{
	assert(ptr_glBindVertexBuffer);
	ptr_glBindVertexBuffer(bindingindex, buffer, offset, stride);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
{
	assert(ptr_glVertexAttribFormat);
	ptr_glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
	assert(ptr_glVertexAttribIFormat);
	ptr_glVertexAttribIFormat(attribindex, size, type, relativeoffset);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
	assert(ptr_glVertexAttribLFormat);
	ptr_glVertexAttribLFormat(attribindex, size, type, relativeoffset);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor)
{
	assert(ptr_glVertexBindingDivisor);
	ptr_glVertexBindingDivisor(bindingindex, divisor);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

// GL_VERSION_4_4

// GL_ARB_clear_texture

inline void glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void *data)
{
	assert(ptr_glClearTexImage);
	ptr_glClearTexImage(texture, level, format, type, data);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}

inline void glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data)
{
	assert(ptr_glClearTexSubImage);
	ptr_glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
#ifdef _DEBUG
	GLenum error;
	assert((error = glGetError()) == GL_NO_ERROR);
#endif
}
