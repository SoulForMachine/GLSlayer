
#include "GLShader.h"
#include <cassert>
#include <algorithm>

using namespace std;
using namespace gls;


GLShader::GLShader()
{
	_logInfo = 0;
	_logInfoLength = 0;
}

GLShader::~GLShader()
{
	delete[] _logInfo;
}

bool GLShader::Create(size_t count, const char** source)
{
	GLint linked = GL_FALSE;
	_id = glCreateShaderProgramv(_target, (GLsizei)count, source);
	OPENGL_ERROR_CHECK

	if(_id)
	{
		glGetProgramiv(_id, GL_LINK_STATUS, &linked);
		OPENGL_ERROR_CHECK

		RetrieveLog();
	}

	return (glGetError() == GL_NO_ERROR && linked == GL_TRUE);
}

bool GLShader::Create(size_t size, const void* binary, uint format)
{
	GLint linked = GL_FALSE;
	_id = glCreateProgram();
	if(_id)
	{
		glProgramParameteri(_id, GL_PROGRAM_SEPARABLE, GL_TRUE);
		glProgramBinary(_id, format, binary, (GLsizei)size);
		OPENGL_ERROR_CHECK

		glGetProgramiv(_id, GL_LINK_STATUS, &linked);
		OPENGL_ERROR_CHECK

		RetrieveLog();
	}

	return (glGetError() == GL_NO_ERROR && linked == GL_TRUE);
}

bool GLShader::CreateWithTransformFeedback(size_t count, const char** source, size_t attrib_count, const char** attrib_names)
{
	GLint linked = GL_FALSE;
	GLuint shader = glCreateShader(_target);
	if(shader)
	{
		glShaderSource(shader, (GLsizei)count, source, 0);
		OPENGL_ERROR_CHECK
		glCompileShader(shader);
		OPENGL_ERROR_CHECK
		GLuint program = glCreateProgram();
		if(program)
		{
			GLint compiled = GL_FALSE;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
			glProgramParameteri(program, GL_PROGRAM_SEPARABLE, GL_TRUE);
			if(compiled)
			{
				glAttachShader(program, shader);
				OPENGL_ERROR_CHECK

				glTransformFeedbackVaryings(program, (GLsizei)attrib_count, attrib_names, GL_INTERLEAVED_ATTRIBS);
				OPENGL_ERROR_CHECK

				glLinkProgram(program);
				glDetachShader(program, shader);
				glGetProgramiv(_id, GL_LINK_STATUS, &linked);
			}
			RetrieveLog2(program, shader);
		}
		glDeleteShader(shader);
		_id = program;
	}

	return (glGetError() == GL_NO_ERROR && linked == GL_TRUE);
}

bool GLShader::CreateWithTransformFeedback(size_t size, const void* binary, uint format, size_t attrib_count, const char** attrib_names)
{
	GLint linked = GL_FALSE;
	_id = glCreateProgram();
	if(_id)
	{
		glProgramParameteri(_id, GL_PROGRAM_SEPARABLE, GL_TRUE);
		glTransformFeedbackVaryings(_id, (GLsizei)attrib_count, attrib_names, GL_INTERLEAVED_ATTRIBS);
		OPENGL_ERROR_CHECK

		glProgramBinary(_id, format, binary, (GLsizei)size);
		glGetProgramiv(_id, GL_LINK_STATUS, &linked);

		RetrieveLog();
	}

	return (glGetError() == GL_NO_ERROR && linked == GL_TRUE);
}

void GLShader::Destroy()
{
	if(_id)
	{
		glDeleteProgram(_id);
		OPENGL_ERROR_CHECK
		_id = 0;
	}
}


ShaderType GLShader::GetShaderType()
{
	return _shaderType;
}

const char* GLShader::GetInfoLog()
{
	return _logInfo;
}

int GLShader::GetInfoLogLength()
{
	return _logInfoLength;
}

bool GLShader::Validate()
{
	glValidateProgram(_id);
	OPENGL_ERROR_CHECK

	GLint status;
	glGetProgramiv(_id, GL_VALIDATE_STATUS, &status);
	OPENGL_ERROR_CHECK

	RetrieveLog();

	return (status == GL_TRUE);
}

uint GLShader::GetSubroutineIndex(const char* name)
{
	uint index = glGetSubroutineIndex(_id, _target, name);
	OPENGL_ERROR_CHECK
	return index;
}

bool GLShader::GetBinary(gls::uint& format, size_t buffer_size, void* buffer)
{
	/*glProgramParameteri(_id, GL_PROGRAM_BINARY_RETRIEVABLE_HINT, GL_TRUE);
	OPENGL_ERROR_CHECK

	glLinkProgram(_id);
	OPENGL_ERROR_CHECK

	bool result = (glGetError() == GL_NO_ERROR);
	GLint status;
	glGetProgramiv(_id, GL_LINK_STATUS, &status);
	OPENGL_ERROR_CHECK
	result = result && (status == GL_TRUE);

	RetrieveLog();

	if(!result)
		return false;*/

	GLsizei length;
	GLenum gl_fmt;
	glGetProgramBinary(_id, (GLsizei)buffer_size, &length, &gl_fmt, buffer);
	OPENGL_ERROR_CHECK

	format = gl_fmt;
	return (glGetError() == GL_NO_ERROR);
}

int GLShader::GetBinarySize()
{
	GLint size;
	glGetProgramiv(_id, GL_PROGRAM_BINARY_LENGTH, &size);
	OPENGL_ERROR_CHECK
	return size;
}

void GLShader::RetrieveLog()
{
	GLint log_len;
	glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &log_len);
	OPENGL_ERROR_CHECK

	_logInfoLength = log_len;
	delete[] _logInfo;
	_logInfo = new char[max(log_len, 1)];
	_logInfo[0] = '\0';
	if(log_len > 1)
	{
		glGetProgramInfoLog(_id, log_len, 0, _logInfo);
		OPENGL_ERROR_CHECK
	}
}

void GLShader::RetrieveLog2(GLuint program, GLuint shader)
{
	GLint prog_log_len;
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &prog_log_len);
	OPENGL_ERROR_CHECK

	GLint shader_log_len;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &shader_log_len);
	OPENGL_ERROR_CHECK

	_logInfoLength = prog_log_len + shader_log_len;
	delete[] _logInfo;
	_logInfo = new char[max(_logInfoLength, 1)];
	_logInfo[0] = '\0';

	if(prog_log_len > 1)
	{
		glGetProgramInfoLog(program, prog_log_len, 0, _logInfo);
		OPENGL_ERROR_CHECK
	}

	if(shader_log_len > 1)
	{
		GLint append_index = max(prog_log_len - 1, 0);
		glGetShaderInfoLog(shader, shader_log_len, 0, &_logInfo[append_index]);
		OPENGL_ERROR_CHECK
	}
}

//================================ GLVertexShader ==============================================

GLVertexShader::GLVertexShader()
{
	_shaderType = VERTEX_SHADER;
	_resType = RES_SHADER;
	_target = GL_VERTEX_SHADER;
}

void GLVertexShader::TransformFeedbackVaryings(size_t count, const char** varyings, TransformFeedbackBufferMode mode)
{
	glTransformFeedbackVaryings(_id, (GLsizei)count, varyings, GetGLEnum(mode));
	OPENGL_ERROR_CHECK
}

//================================ GLTessControlShader ==============================================

GLTessControlShader::GLTessControlShader()
{
	_shaderType = TESS_CONTROL_SHADER;
	_resType = RES_SHADER;
	_target = GL_TESS_CONTROL_SHADER;
}

int GLTessControlShader::GetOutputVertexCount()
{
	GLint count;
	glGetProgramiv(_id, GL_TESS_CONTROL_OUTPUT_VERTICES, &count);
	OPENGL_ERROR_CHECK
	return count;
}

//================================ GLTessEvaluationShader ==============================================

GLTessEvaluationShader::GLTessEvaluationShader()
{
	_shaderType = TESS_EVALUATION_SHADER;
	_resType = RES_SHADER;
	_target = GL_TESS_EVALUATION_SHADER;
}

TessGenPrimitiveType GLTessEvaluationShader::GetMode()
{
	GLint mode;
	glGetProgramiv(_id, GL_TESS_GEN_MODE, &mode);
	OPENGL_ERROR_CHECK
	return GetFromGLEnum<TessGenPrimitiveType>(mode);
}

TessGenSpacing GLTessEvaluationShader::GetSpacing()
{
	GLint spacing;
	glGetProgramiv(_id, GL_TESS_GEN_SPACING, &spacing);
	OPENGL_ERROR_CHECK
	return GetFromGLEnum<TessGenSpacing>(spacing);
}

VertexOrder GLTessEvaluationShader::GetVertexOrder()
{
	GLint order;
	glGetProgramiv(_id, GL_TESS_GEN_VERTEX_ORDER, &order);
	OPENGL_ERROR_CHECK
	return GetFromGLEnum<VertexOrder>(order);
}

bool GLTessEvaluationShader::GetPointMode()
{
	GLint mode;
	glGetProgramiv(_id, GL_TESS_GEN_POINT_MODE, &mode);
	OPENGL_ERROR_CHECK
	return (mode == GL_TRUE);
}

//================================ GLGeometryShader ==============================================

GLGeometryShader::GLGeometryShader()
{
	_shaderType = GEOMETRY_SHADER;
	_resType = RES_SHADER;
	_target = GL_GEOMETRY_SHADER;
}

void GLGeometryShader::TransformFeedbackVaryings(size_t count, const char** varyings, TransformFeedbackBufferMode mode)
{
	glTransformFeedbackVaryings(_id, (GLsizei)count, varyings, GetGLEnum(mode));
	OPENGL_ERROR_CHECK
}

int GLGeometryShader::GetInvocations()
{
	int invocations;
	glGetProgramiv(_id, GL_GEOMETRY_SHADER_INVOCATIONS, &invocations);
	OPENGL_ERROR_CHECK
	return invocations;
}

//================================ GLFragmentShader ==============================================

GLFragmentShader::GLFragmentShader()
{
	_shaderType = FRAGMENT_SHADER;
	_resType = RES_SHADER;
	_target = GL_FRAGMENT_SHADER;
}

//================================ GLComputeShader ==============================================

GLComputeShader::GLComputeShader()
{
	_shaderType = COMPUTE_SHADER;
	_resType = RES_SHADER;
	_target = GL_COMPUTE_SHADER;
}

void GLComputeShader::GetWorkGroupSize(int work_group_size[3])
{
	glGetProgramiv(_id, GL_COMPUTE_LOCAL_WORK_SIZE, work_group_size); //!GL_COMPUTE_WORK_GROUP_SIZE?
	OPENGL_ERROR_CHECK
}
