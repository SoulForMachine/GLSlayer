
// GL_VERSION_1_2

inline void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels)
{
	GLenum error;
	assert(ptr_glTexSubImage3D);
	ptr_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	GLenum error;
	assert(ptr_glCopyTexSubImage3D);
	ptr_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_VERSION_1_3

inline void glActiveTexture(GLenum texture)
{
	GLenum error;
	assert(ptr_glActiveTexture);
	ptr_glActiveTexture(texture);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glSampleCoverage(GLfloat value, GLboolean invert)
{
	GLenum error;
	assert(ptr_glSampleCoverage);
	ptr_glSampleCoverage(value, invert);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data)
{
	GLenum error;
	assert(ptr_glCompressedTexSubImage3D);
	ptr_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)
{
	GLenum error;
	assert(ptr_glCompressedTexSubImage2D);
	ptr_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data)
{
	GLenum error;
	assert(ptr_glCompressedTexSubImage1D);
	ptr_glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetCompressedTexImage(GLenum target, GLint level, void *img)
{
	GLenum error;
	assert(ptr_glGetCompressedTexImage);
	ptr_glGetCompressedTexImage(target, level, img);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_VERSION_1_4

inline void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
	GLenum error;
	assert(ptr_glBlendFuncSeparate);
	ptr_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_imaging

inline void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	GLenum error;
	assert(ptr_glBlendColor);
	ptr_glBlendColor(red, green, blue, alpha);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBlendEquation(GLenum mode)
{
	GLenum error;
	assert(ptr_glBlendEquation);
	ptr_glBlendEquation(mode);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_VERSION_1_5

inline void glGenQueries(GLsizei n, GLuint *ids)
{
	GLenum error;
	assert(ptr_glGenQueries);
	ptr_glGenQueries(n, ids);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDeleteQueries(GLsizei n, const GLuint *ids)
{
	GLenum error;
	assert(ptr_glDeleteQueries);
	ptr_glDeleteQueries(n, ids);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBeginQuery(GLenum target, GLuint id)
{
	GLenum error;
	assert(ptr_glBeginQuery);
	ptr_glBeginQuery(target, id);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glEndQuery(GLenum target)
{
	GLenum error;
	assert(ptr_glEndQuery);
	ptr_glEndQuery(target);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params)
{
	GLenum error;
	assert(ptr_glGetQueryObjectiv);
	ptr_glGetQueryObjectiv(id, pname, params);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params)
{
	GLenum error;
	assert(ptr_glGetQueryObjectuiv);
	ptr_glGetQueryObjectuiv(id, pname, params);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBindBuffer(GLenum target, GLuint buffer)
{
	GLenum error;
	assert(ptr_glBindBuffer);
	ptr_glBindBuffer(target, buffer);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDeleteBuffers(GLsizei n, const GLuint *buffers)
{
	GLenum error;
	assert(ptr_glDeleteBuffers);
	ptr_glDeleteBuffers(n, buffers);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGenBuffers(GLsizei n, GLuint *buffers)
{
	GLenum error;
	assert(ptr_glGenBuffers);
	ptr_glGenBuffers(n, buffers);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage)
{
	GLenum error;
	assert(ptr_glBufferData);
	ptr_glBufferData(target, size, data, usage);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data)
{
	GLenum error;
	assert(ptr_glBufferSubData);
	ptr_glBufferSubData(target, offset, size, data);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void *data)
{
	GLenum error;
	assert(ptr_glGetBufferSubData);
	ptr_glGetBufferSubData(target, offset, size, data);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void *glMapBuffer(GLenum target, GLenum access)
{
	GLenum error;
	assert(ptr_glMapBuffer);
	void *result;
	result = ptr_glMapBuffer(target, access);
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}

inline GLboolean glUnmapBuffer(GLenum target)
{
	GLenum error;
	assert(ptr_glUnmapBuffer);
	GLboolean result;
	result = ptr_glUnmapBuffer(target);
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}

// GL_VERSION_2_0

inline void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
	GLenum error;
	assert(ptr_glBlendEquationSeparate);
	ptr_glBlendEquationSeparate(modeRGB, modeAlpha);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDrawBuffers(GLsizei n, const GLenum *bufs)
{
	GLenum error;
	assert(ptr_glDrawBuffers);
	ptr_glDrawBuffers(n, bufs);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
	GLenum error;
	assert(ptr_glStencilOpSeparate);
	ptr_glStencilOpSeparate(face, sfail, dpfail, dppass);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
	GLenum error;
	assert(ptr_glStencilFuncSeparate);
	ptr_glStencilFuncSeparate(face, func, ref, mask);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glStencilMaskSeparate(GLenum face, GLuint mask)
{
	GLenum error;
	assert(ptr_glStencilMaskSeparate);
	ptr_glStencilMaskSeparate(face, mask);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glAttachShader(GLuint program, GLuint shader)
{
	GLenum error;
	assert(ptr_glAttachShader);
	ptr_glAttachShader(program, shader);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glCompileShader(GLuint shader)
{
	GLenum error;
	assert(ptr_glCompileShader);
	ptr_glCompileShader(shader);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline GLuint glCreateProgram()
{
	GLenum error;
	assert(ptr_glCreateProgram);
	GLuint result;
	result = ptr_glCreateProgram();
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}

inline GLuint glCreateShader(GLenum type)
{
	GLenum error;
	assert(ptr_glCreateShader);
	GLuint result;
	result = ptr_glCreateShader(type);
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}

inline void glDeleteProgram(GLuint program)
{
	GLenum error;
	assert(ptr_glDeleteProgram);
	ptr_glDeleteProgram(program);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDeleteShader(GLuint shader)
{
	GLenum error;
	assert(ptr_glDeleteShader);
	ptr_glDeleteShader(shader);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDetachShader(GLuint program, GLuint shader)
{
	GLenum error;
	assert(ptr_glDetachShader);
	ptr_glDetachShader(program, shader);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDisableVertexAttribArray(GLuint index)
{
	GLenum error;
	assert(ptr_glDisableVertexAttribArray);
	ptr_glDisableVertexAttribArray(index);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glEnableVertexAttribArray(GLuint index)
{
	GLenum error;
	assert(ptr_glEnableVertexAttribArray);
	ptr_glEnableVertexAttribArray(index);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetProgramiv(GLuint program, GLenum pname, GLint *params)
{
	GLenum error;
	assert(ptr_glGetProgramiv);
	ptr_glGetProgramiv(program, pname, params);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	GLenum error;
	assert(ptr_glGetProgramInfoLog);
	ptr_glGetProgramInfoLog(program, bufSize, length, infoLog);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetShaderiv(GLuint shader, GLenum pname, GLint *params)
{
	GLenum error;
	assert(ptr_glGetShaderiv);
	ptr_glGetShaderiv(shader, pname, params);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	GLenum error;
	assert(ptr_glGetShaderInfoLog);
	ptr_glGetShaderInfoLog(shader, bufSize, length, infoLog);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glLinkProgram(GLuint program)
{
	GLenum error;
	assert(ptr_glLinkProgram);
	ptr_glLinkProgram(program);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length)
{
	GLenum error;
	assert(ptr_glShaderSource);
	ptr_glShaderSource(shader, count, string, length);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glValidateProgram(GLuint program)
{
	GLenum error;
	assert(ptr_glValidateProgram);
	ptr_glValidateProgram(program);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
{
	GLenum error;
	assert(ptr_glVertexAttribPointer);
	ptr_glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_VERSION_2_1

// GL_VERSION_3_0

inline void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
{
	GLenum error;
	assert(ptr_glColorMaski);
	ptr_glColorMaski(index, r, g, b, a);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetIntegeri_v(GLenum target, GLuint index, GLint *data)
{
	GLenum error;
	assert(ptr_glGetIntegeri_v);
	ptr_glGetIntegeri_v(target, index, data);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glEnablei(GLenum target, GLuint index)
{
	GLenum error;
	assert(ptr_glEnablei);
	ptr_glEnablei(target, index);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDisablei(GLenum target, GLuint index)
{
	GLenum error;
	assert(ptr_glDisablei);
	ptr_glDisablei(target, index);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBeginTransformFeedback(GLenum primitiveMode)
{
	GLenum error;
	assert(ptr_glBeginTransformFeedback);
	ptr_glBeginTransformFeedback(primitiveMode);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glEndTransformFeedback()
{
	GLenum error;
	assert(ptr_glEndTransformFeedback);
	ptr_glEndTransformFeedback();
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
	GLenum error;
	assert(ptr_glBindBufferRange);
	ptr_glBindBufferRange(target, index, buffer, offset, size);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBindBufferBase(GLenum target, GLuint index, GLuint buffer)
{
	GLenum error;
	assert(ptr_glBindBufferBase);
	ptr_glBindBufferBase(target, index, buffer);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode)
{
	GLenum error;
	assert(ptr_glTransformFeedbackVaryings);
	ptr_glTransformFeedbackVaryings(program, count, varyings, bufferMode);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glClampColor(GLenum target, GLenum clamp)
{
	GLenum error;
	assert(ptr_glClampColor);
	ptr_glClampColor(target, clamp);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBeginConditionalRender(GLuint id, GLenum mode)
{
	GLenum error;
	assert(ptr_glBeginConditionalRender);
	ptr_glBeginConditionalRender(id, mode);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glEndConditionalRender()
{
	GLenum error;
	assert(ptr_glEndConditionalRender);
	ptr_glEndConditionalRender();
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)
{
	GLenum error;
	assert(ptr_glVertexAttribIPointer);
	ptr_glVertexAttribIPointer(index, size, type, stride, pointer);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value)
{
	GLenum error;
	assert(ptr_glClearBufferiv);
	ptr_glClearBufferiv(buffer, drawbuffer, value);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value)
{
	GLenum error;
	assert(ptr_glClearBufferuiv);
	ptr_glClearBufferuiv(buffer, drawbuffer, value);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value)
{
	GLenum error;
	assert(ptr_glClearBufferfv);
	ptr_glClearBufferfv(buffer, drawbuffer, value);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
{
	GLenum error;
	assert(ptr_glClearBufferfi);
	ptr_glClearBufferfi(buffer, drawbuffer, depth, stencil);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline const GLubyte *glGetStringi(GLenum name, GLuint index)
{
	GLenum error;
	assert(ptr_glGetStringi);
	const GLubyte *result;
	result = ptr_glGetStringi(name, index);
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}

// GL_ARB_framebuffer_object

inline void glBindRenderbuffer(GLenum target, GLuint renderbuffer)
{
	GLenum error;
	assert(ptr_glBindRenderbuffer);
	ptr_glBindRenderbuffer(target, renderbuffer);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers)
{
	GLenum error;
	assert(ptr_glDeleteRenderbuffers);
	ptr_glDeleteRenderbuffers(n, renderbuffers);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers)
{
	GLenum error;
	assert(ptr_glGenRenderbuffers);
	ptr_glGenRenderbuffers(n, renderbuffers);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBindFramebuffer(GLenum target, GLuint framebuffer)
{
	GLenum error;
	assert(ptr_glBindFramebuffer);
	ptr_glBindFramebuffer(target, framebuffer);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers)
{
	GLenum error;
	assert(ptr_glDeleteFramebuffers);
	ptr_glDeleteFramebuffers(n, framebuffers);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGenFramebuffers(GLsizei n, GLuint *framebuffers)
{
	GLenum error;
	assert(ptr_glGenFramebuffers);
	ptr_glGenFramebuffers(n, framebuffers);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline GLenum glCheckFramebufferStatus(GLenum target)
{
	GLenum error;
	assert(ptr_glCheckFramebufferStatus);
	GLenum result;
	result = ptr_glCheckFramebufferStatus(target);
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}

inline void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	GLenum error;
	assert(ptr_glFramebufferTexture2D);
	ptr_glFramebufferTexture2D(target, attachment, textarget, texture, level);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
	GLenum error;
	assert(ptr_glFramebufferRenderbuffer);
	ptr_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGenerateMipmap(GLenum target)
{
	GLenum error;
	assert(ptr_glGenerateMipmap);
	ptr_glGenerateMipmap(target);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
{
	GLenum error;
	assert(ptr_glBlitFramebuffer);
	ptr_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
{
	GLenum error;
	assert(ptr_glRenderbufferStorageMultisample);
	ptr_glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
	GLenum error;
	assert(ptr_glFramebufferTextureLayer);
	ptr_glFramebufferTextureLayer(target, attachment, texture, level, layer);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_map_buffer_range

inline void *glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
	GLenum error;
	assert(ptr_glMapBufferRange);
	void *result;
	result = ptr_glMapBufferRange(target, offset, length, access);
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}

inline void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length)
{
	GLenum error;
	assert(ptr_glFlushMappedBufferRange);
	ptr_glFlushMappedBufferRange(target, offset, length);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_vertex_array_object

inline void glBindVertexArray(GLuint array)
{
	GLenum error;
	assert(ptr_glBindVertexArray);
	ptr_glBindVertexArray(array);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGenVertexArrays(GLsizei n, GLuint *arrays)
{
	GLenum error;
	assert(ptr_glGenVertexArrays);
	ptr_glGenVertexArrays(n, arrays);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_VERSION_3_1

inline void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer)
{
	GLenum error;
	assert(ptr_glTexBuffer);
	ptr_glTexBuffer(target, internalformat, buffer);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glPrimitiveRestartIndex(GLuint index)
{
	GLenum error;
	assert(ptr_glPrimitiveRestartIndex);
	ptr_glPrimitiveRestartIndex(index);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_copy_buffer

inline void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
{
	GLenum error;
	assert(ptr_glCopyBufferSubData);
	ptr_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_VERSION_3_2

// GL_ARB_draw_elements_base_vertex

inline void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex)
{
	GLenum error;
	assert(ptr_glDrawElementsBaseVertex);
	ptr_glDrawElementsBaseVertex(mode, count, type, indices, basevertex);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex)
{
	GLenum error;
	assert(ptr_glDrawRangeElementsBaseVertex);
	ptr_glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_provoking_vertex

inline void glProvokingVertex(GLenum mode)
{
	GLenum error;
	assert(ptr_glProvokingVertex);
	ptr_glProvokingVertex(mode);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_sync

inline GLsync glFenceSync(GLenum condition, GLbitfield flags)
{
	GLenum error;
	assert(ptr_glFenceSync);
	GLsync result;
	result = ptr_glFenceSync(condition, flags);
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}

inline void glDeleteSync(GLsync sync)
{
	GLenum error;
	assert(ptr_glDeleteSync);
	ptr_glDeleteSync(sync);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
	GLenum error;
	assert(ptr_glClientWaitSync);
	GLenum result;
	result = ptr_glClientWaitSync(sync, flags, timeout);
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}

inline void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
	GLenum error;
	assert(ptr_glWaitSync);
	ptr_glWaitSync(sync, flags, timeout);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetInteger64v(GLenum pname, GLint64 *data)
{
	GLenum error;
	assert(ptr_glGetInteger64v);
	ptr_glGetInteger64v(pname, data);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_texture_multisample

inline void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
	GLenum error;
	assert(ptr_glFramebufferTexture);
	ptr_glFramebufferTexture(target, attachment, texture, level);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val)
{
	GLenum error;
	assert(ptr_glGetMultisamplefv);
	ptr_glGetMultisamplefv(pname, index, val);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glSampleMaski(GLuint maskNumber, GLbitfield mask)
{
	GLenum error;
	assert(ptr_glSampleMaski);
	ptr_glSampleMaski(maskNumber, mask);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_VERSION_3_3

// GL_ARB_sampler_objects

inline void glGenSamplers(GLsizei count, GLuint *samplers)
{
	GLenum error;
	assert(ptr_glGenSamplers);
	ptr_glGenSamplers(count, samplers);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDeleteSamplers(GLsizei count, const GLuint *samplers)
{
	GLenum error;
	assert(ptr_glDeleteSamplers);
	ptr_glDeleteSamplers(count, samplers);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBindSampler(GLuint unit, GLuint sampler)
{
	GLenum error;
	assert(ptr_glBindSampler);
	ptr_glBindSampler(unit, sampler);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param)
{
	GLenum error;
	assert(ptr_glSamplerParameteri);
	ptr_glSamplerParameteri(sampler, pname, param);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param)
{
	GLenum error;
	assert(ptr_glSamplerParameterf);
	ptr_glSamplerParameterf(sampler, pname, param);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param)
{
	GLenum error;
	assert(ptr_glSamplerParameterfv);
	ptr_glSamplerParameterfv(sampler, pname, param);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_timer_query

inline void glQueryCounter(GLuint id, GLenum target)
{
	GLenum error;
	assert(ptr_glQueryCounter);
	ptr_glQueryCounter(id, target);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params)
{
	GLenum error;
	assert(ptr_glGetQueryObjectui64v);
	ptr_glGetQueryObjectui64v(id, pname, params);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_vertex_type_2_10_10_10_rev

inline void glVertexAttribDivisor(GLuint index, GLuint divisor)
{
	GLenum error;
	assert(ptr_glVertexAttribDivisor);
	ptr_glVertexAttribDivisor(index, divisor);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_VERSION_4_0

inline void glMinSampleShading(GLfloat value)
{
	GLenum error;
	assert(ptr_glMinSampleShading);
	ptr_glMinSampleShading(value);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBlendEquationi(GLuint buf, GLenum mode)
{
	GLenum error;
	assert(ptr_glBlendEquationi);
	ptr_glBlendEquationi(buf, mode);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
	GLenum error;
	assert(ptr_glBlendEquationSeparatei);
	ptr_glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBlendFunci(GLuint buf, GLenum src, GLenum dst)
{
	GLenum error;
	assert(ptr_glBlendFunci);
	ptr_glBlendFunci(buf, src, dst);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
	GLenum error;
	assert(ptr_glBlendFuncSeparatei);
	ptr_glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_draw_indirect

inline void glDrawArraysIndirect(GLenum mode, const void *indirect)
{
	GLenum error;
	assert(ptr_glDrawArraysIndirect);
	ptr_glDrawArraysIndirect(mode, indirect);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect)
{
	GLenum error;
	assert(ptr_glDrawElementsIndirect);
	ptr_glDrawElementsIndirect(mode, type, indirect);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_shader_subroutine

inline GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name)
{
	GLenum error;
	assert(ptr_glGetSubroutineIndex);
	GLuint result;
	result = ptr_glGetSubroutineIndex(program, shadertype, name);
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}

inline void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices)
{
	GLenum error;
	assert(ptr_glUniformSubroutinesuiv);
	ptr_glUniformSubroutinesuiv(shadertype, count, indices);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_tessellation_shader

inline void glPatchParameteri(GLenum pname, GLint value)
{
	GLenum error;
	assert(ptr_glPatchParameteri);
	ptr_glPatchParameteri(pname, value);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glPatchParameterfv(GLenum pname, const GLfloat *values)
{
	GLenum error;
	assert(ptr_glPatchParameterfv);
	ptr_glPatchParameterfv(pname, values);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_transform_feedback2

inline void glBindTransformFeedback(GLenum target, GLuint id)
{
	GLenum error;
	assert(ptr_glBindTransformFeedback);
	ptr_glBindTransformFeedback(target, id);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids)
{
	GLenum error;
	assert(ptr_glDeleteTransformFeedbacks);
	ptr_glDeleteTransformFeedbacks(n, ids);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGenTransformFeedbacks(GLsizei n, GLuint *ids)
{
	GLenum error;
	assert(ptr_glGenTransformFeedbacks);
	ptr_glGenTransformFeedbacks(n, ids);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glPauseTransformFeedback()
{
	GLenum error;
	assert(ptr_glPauseTransformFeedback);
	ptr_glPauseTransformFeedback();
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glResumeTransformFeedback()
{
	GLenum error;
	assert(ptr_glResumeTransformFeedback);
	ptr_glResumeTransformFeedback();
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_transform_feedback3

inline void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream)
{
	GLenum error;
	assert(ptr_glDrawTransformFeedbackStream);
	ptr_glDrawTransformFeedbackStream(mode, id, stream);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id)
{
	GLenum error;
	assert(ptr_glBeginQueryIndexed);
	ptr_glBeginQueryIndexed(target, index, id);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_VERSION_4_1

// GL_ARB_get_program_binary

inline void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary)
{
	GLenum error;
	assert(ptr_glGetProgramBinary);
	ptr_glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length)
{
	GLenum error;
	assert(ptr_glProgramBinary);
	ptr_glProgramBinary(program, binaryFormat, binary, length);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glProgramParameteri(GLuint program, GLenum pname, GLint value)
{
	GLenum error;
	assert(ptr_glProgramParameteri);
	ptr_glProgramParameteri(program, pname, value);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_separate_shader_objects

inline void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program)
{
	GLenum error;
	assert(ptr_glUseProgramStages);
	ptr_glUseProgramStages(pipeline, stages, program);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const*strings)
{
	GLenum error;
	assert(ptr_glCreateShaderProgramv);
	GLuint result;
	result = ptr_glCreateShaderProgramv(type, count, strings);
	assert((error = glGetError()) == GL_NO_ERROR);
	return result;
}

inline void glBindProgramPipeline(GLuint pipeline)
{
	GLenum error;
	assert(ptr_glBindProgramPipeline);
	ptr_glBindProgramPipeline(pipeline);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGenProgramPipelines(GLsizei n, GLuint *pipelines)
{
	GLenum error;
	assert(ptr_glGenProgramPipelines);
	ptr_glGenProgramPipelines(n, pipelines);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params)
{
	GLenum error;
	assert(ptr_glGetProgramPipelineiv);
	ptr_glGetProgramPipelineiv(pipeline, pname, params);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glValidateProgramPipeline(GLuint pipeline)
{
	GLenum error;
	assert(ptr_glValidateProgramPipeline);
	ptr_glValidateProgramPipeline(pipeline);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_vertex_attrib_64bit

inline void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)
{
	GLenum error;
	assert(ptr_glVertexAttribLPointer);
	ptr_glVertexAttribLPointer(index, size, type, stride, pointer);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_viewport_array

inline void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
	GLenum error;
	assert(ptr_glViewportIndexedf);
	ptr_glViewportIndexedf(index, x, y, w, h);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)
{
	GLenum error;
	assert(ptr_glScissorIndexed);
	ptr_glScissorIndexed(index, left, bottom, width, height);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f)
{
	GLenum error;
	assert(ptr_glDepthRangeIndexed);
	ptr_glDepthRangeIndexed(index, n, f);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glGetFloati_v(GLenum target, GLuint index, GLfloat *data)
{
	GLenum error;
	assert(ptr_glGetFloati_v);
	ptr_glGetFloati_v(target, index, data);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_VERSION_4_2

// GL_ARB_base_instance

inline void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance)
{
	GLenum error;
	assert(ptr_glDrawArraysInstancedBaseInstance);
	ptr_glDrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance)
{
	GLenum error;
	assert(ptr_glDrawElementsInstancedBaseVertexBaseInstance);
	ptr_glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_transform_feedback_instanced

inline void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount)
{
	GLenum error;
	assert(ptr_glDrawTransformFeedbackStreamInstanced);
	ptr_glDrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_internalformat_query

inline void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params)
{
	GLenum error;
	assert(ptr_glGetInternalformativ);
	ptr_glGetInternalformativ(target, internalformat, pname, bufSize, params);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_shader_image_load_store

inline void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)
{
	GLenum error;
	assert(ptr_glBindImageTexture);
	ptr_glBindImageTexture(unit, texture, level, layered, layer, access, format);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glMemoryBarrier(GLbitfield barriers)
{
	GLenum error;
	assert(ptr_glMemoryBarrier);
	ptr_glMemoryBarrier(barriers);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_texture_storage

inline void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)
{
	GLenum error;
	assert(ptr_glTexStorage1D);
	ptr_glTexStorage1D(target, levels, internalformat, width);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
	GLenum error;
	assert(ptr_glTexStorage2D);
	ptr_glTexStorage2D(target, levels, internalformat, width, height);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
	GLenum error;
	assert(ptr_glTexStorage3D);
	ptr_glTexStorage3D(target, levels, internalformat, width, height, depth);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_VERSION_4_3

// GL_ARB_clear_buffer_object

inline void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data)
{
	GLenum error;
	assert(ptr_glClearBufferData);
	ptr_glClearBufferData(target, internalformat, format, type, data);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data)
{
	GLenum error;
	assert(ptr_glClearBufferSubData);
	ptr_glClearBufferSubData(target, internalformat, offset, size, format, type, data);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_compute_shader

inline void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)
{
	GLenum error;
	assert(ptr_glDispatchCompute);
	ptr_glDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDispatchComputeIndirect(GLintptr indirect)
{
	GLenum error;
	assert(ptr_glDispatchComputeIndirect);
	ptr_glDispatchComputeIndirect(indirect);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_copy_image

inline void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)
{
	GLenum error;
	assert(ptr_glCopyImageSubData);
	ptr_glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_KHR_debug

inline void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled)
{
	GLenum error;
	assert(ptr_glDebugMessageControl);
	ptr_glDebugMessageControl(source, type, severity, count, ids, enabled);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf)
{
	GLenum error;
	assert(ptr_glDebugMessageInsert);
	ptr_glDebugMessageInsert(source, type, id, severity, length, buf);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glDebugMessageCallback(GLDEBUGPROC callback, const void *userParam)
{
	GLenum error;
	assert(ptr_glDebugMessageCallback);
	ptr_glDebugMessageCallback(callback, userParam);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message)
{
	GLenum error;
	assert(ptr_glPushDebugGroup);
	ptr_glPushDebugGroup(source, id, length, message);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glPopDebugGroup()
{
	GLenum error;
	assert(ptr_glPopDebugGroup);
	ptr_glPopDebugGroup();
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar *label)
{
	GLenum error;
	assert(ptr_glObjectLabel);
	ptr_glObjectLabel(identifier, name, length, label);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glObjectPtrLabel(const void *ptr, GLsizei length, const GLchar *label)
{
	GLenum error;
	assert(ptr_glObjectPtrLabel);
	ptr_glObjectPtrLabel(ptr, length, label);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_framebuffer_no_attachments

inline void glFramebufferParameteri(GLenum target, GLenum pname, GLint param)
{
	GLenum error;
	assert(ptr_glFramebufferParameteri);
	ptr_glFramebufferParameteri(target, pname, param);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_internalformat_query2

inline void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params)
{
	GLenum error;
	assert(ptr_glGetInternalformati64v);
	ptr_glGetInternalformati64v(target, internalformat, pname, bufSize, params);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_invalidate_subdata

inline void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth)
{
	GLenum error;
	assert(ptr_glInvalidateTexSubImage);
	ptr_glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glInvalidateTexImage(GLuint texture, GLint level)
{
	GLenum error;
	assert(ptr_glInvalidateTexImage);
	ptr_glInvalidateTexImage(texture, level);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length)
{
	GLenum error;
	assert(ptr_glInvalidateBufferSubData);
	ptr_glInvalidateBufferSubData(buffer, offset, length);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glInvalidateBufferData(GLuint buffer)
{
	GLenum error;
	assert(ptr_glInvalidateBufferData);
	ptr_glInvalidateBufferData(buffer);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments)
{
	GLenum error;
	assert(ptr_glInvalidateFramebuffer);
	ptr_glInvalidateFramebuffer(target, numAttachments, attachments);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height)
{
	GLenum error;
	assert(ptr_glInvalidateSubFramebuffer);
	ptr_glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_multi_draw_indirect

inline void glMultiDrawArraysIndirect(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride)
{
	GLenum error;
	assert(ptr_glMultiDrawArraysIndirect);
	ptr_glMultiDrawArraysIndirect(mode, indirect, drawcount, stride);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride)
{
	GLenum error;
	assert(ptr_glMultiDrawElementsIndirect);
	ptr_glMultiDrawElementsIndirect(mode, type, indirect, drawcount, stride);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_texture_buffer_range

inline void glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
	GLenum error;
	assert(ptr_glTexBufferRange);
	ptr_glTexBufferRange(target, internalformat, buffer, offset, size);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_texture_storage_multisample

inline void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
{
	GLenum error;
	assert(ptr_glTexStorage2DMultisample);
	ptr_glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
{
	GLenum error;
	assert(ptr_glTexStorage3DMultisample);
	ptr_glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_texture_view

inline void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)
{
	GLenum error;
	assert(ptr_glTextureView);
	ptr_glTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_ARB_vertex_attrib_binding

inline void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
{
	GLenum error;
	assert(ptr_glBindVertexBuffer);
	ptr_glBindVertexBuffer(bindingindex, buffer, offset, stride);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
{
	GLenum error;
	assert(ptr_glVertexAttribFormat);
	ptr_glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
	GLenum error;
	assert(ptr_glVertexAttribIFormat);
	ptr_glVertexAttribIFormat(attribindex, size, type, relativeoffset);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
{
	GLenum error;
	assert(ptr_glVertexAttribLFormat);
	ptr_glVertexAttribLFormat(attribindex, size, type, relativeoffset);
	assert((error = glGetError()) == GL_NO_ERROR);
}

inline void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor)
{
	GLenum error;
	assert(ptr_glVertexBindingDivisor);
	ptr_glVertexBindingDivisor(bindingindex, divisor);
	assert((error = glGetError()) == GL_NO_ERROR);
}

// GL_VERSION_4_4
