
#ifndef _GL_SHADER_H_
#define _GL_SHADER_H_

#include "GLSlayer/Shader.h"
#include "GLSlayer/TransformFeedback.h"
#include "GLResource.h"


#define IMPLEMENT_ISHADER \
	gls::ShaderType GetShaderType() { return GLShader::GetShaderType(); } \
	const char* GetInfoLog() { return GLShader::GetInfoLog(); } \
	int GetInfoLogLength() { return GLShader::GetInfoLogLength(); } \
	bool Validate() { return GLShader::Validate(); } \
	gls::uint GetSubroutineIndex(const char* name) { return GLShader::GetSubroutineIndex(name); } \
	bool GetBinary(gls::uint& format, size_t buffer_size, void* buffer) { return GLShader::GetBinary(format, buffer_size, buffer); } \
	int GetBinarySize() { return GLShader::GetBinarySize(); }



class GLShader : public GLResource
{
public:
	IMPLEMENT_IRESOURCE

	static const int typeID = TYPE_ID_SHADER;

	GLShader();
	~GLShader() = 0;

	bool Create(size_t count, const char** source);
	bool Create(size_t size, const void* binary, gls::uint format);
	bool CreateWithTransformFeedback(size_t count, const char** source, size_t attrib_count, const char** attrib_names);
	bool CreateWithTransformFeedback(size_t size, const void* binary, gls::uint format, size_t attrib_count, const char** attrib_names);
	void Destroy();

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_SHADER) ? this : GLResource::DynamicCast(type_id); }
	gls::ShaderType GetShaderType();
	const char* GetInfoLog();
	int GetInfoLogLength();
	bool Validate();
	gls::uint GetSubroutineIndex(const char* name);
	bool GetBinary(gls::uint& format, size_t buffer_size, void* buffer);
	int GetBinarySize();

protected:
	gls::ShaderType _shaderType;

private:
	GLShader(const GLShader&);
	GLShader& operator = (const GLShader&);
	void RetrieveLog();
	void RetrieveLog2(GLuint program, GLuint shader);

	char* _logInfo;
	int _logInfoLength;
};


class GLVertexShader : public gls::IVertexShader, public GLShader
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ISHADER

	static const int typeID = TYPE_ID_VERTEX_SHADER;

	GLVertexShader();

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_VERTEX_SHADER) ? this : GLShader::DynamicCast(type_id); }
	void TransformFeedbackVaryings(size_t count, const char** varyings, gls::TransformFeedbackBufferMode mode);
};


class GLTessControlShader : public gls::ITessControlShader, public GLShader
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ISHADER

	static const int typeID = TYPE_ID_TESS_CONTROL_SHADER;

	GLTessControlShader();

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TESS_CONTROL_SHADER) ? this : GLShader::DynamicCast(type_id); }
	int GetOutputVertexCount();
};


class GLTessEvaluationShader : public gls::ITessEvaluationShader, public GLShader
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ISHADER

	static const int typeID = TYPE_ID_TESS_EVAL_SHADER;

	GLTessEvaluationShader();

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TESS_EVAL_SHADER) ? this : GLShader::DynamicCast(type_id); }
	gls::TessGenPrimitiveType GetMode();
	gls::TessGenSpacing GetSpacing();
	gls::VertexOrder GetVertexOrder();
	bool GetPointMode();
};


class GLGeometryShader : public gls::IGeometryShader, public GLShader
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ISHADER

	static const int typeID = TYPE_ID_GEOMETRY_SHADER;

	GLGeometryShader();

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_GEOMETRY_SHADER) ? this : GLShader::DynamicCast(type_id); }
	void TransformFeedbackVaryings(size_t count, const char** varyings, gls::TransformFeedbackBufferMode mode);
	int GetInvocations();
};


class GLFragmentShader : public gls::IFragmentShader, public GLShader
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ISHADER

	static const int typeID = TYPE_ID_FRAGMENT_SHADER;

	GLFragmentShader();

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_FRAGMENT_SHADER) ? this : GLShader::DynamicCast(type_id); }
};


class GLComputeShader : public gls::IComputeShader, public GLShader
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ISHADER

	static const int typeID = TYPE_ID_FRAGMENT_SHADER;

	GLComputeShader();

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_COMPUTE_SHADER) ? this : GLShader::DynamicCast(type_id); }
	void GetWorkGroupSize(int work_group_size[3]);
};


#endif // _GL_SHADER_H_
