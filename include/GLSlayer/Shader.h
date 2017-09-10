
#ifndef _GLSLAYER_SHADER_H_
#define _GLSLAYER_SHADER_H_

#include "Resource.h"

namespace gls
{

	struct ShaderBlockInfo
	{
	public:
		struct VariableInfo
		{
			char* name;
			ShaderDataType type;
			uint index;
			uint offset;
			uint arraySize;
			int arrayStride;
			int matrixStride;
			bool isRowMajor;
		};

		char* name;
		size_t dataSize;
		size_t variableCount;
		VariableInfo* variables;

		template <typename _T>
		_T& GetVariableInBuffer(void* bufferPtr, size_t posIndex)
		{
			return *reinterpret_cast<_T*>(
				reinterpret_cast<uint8_t*>(bufferPtr) + variables[posIndex]->offset);
		}
	};


	class IShader : public IResource
	{
	public:
		virtual ~IShader() {}

		virtual ShaderType GetShaderType() = 0;
		virtual const char* GetInfoLog() = 0;
		virtual int GetInfoLogLength() = 0;
		virtual bool Validate() = 0;
		virtual uint GetSubroutineIndex(const char* name) = 0;
		virtual bool GetBinary(uint& format, size_t buffer_size, void* buffer) = 0;
		virtual int GetBinarySize() = 0;
		virtual const ShaderBlockInfo* GetUniformBlockInfo(const char* blockName) = 0;
		virtual const ShaderBlockInfo* GetStorageBlockInfo(const char* blockName) = 0;
	};


	class IVertexShader : public IShader
	{
	public:
		virtual void TransformFeedbackVaryings(size_t count, const char** varyings, TransformFeedbackBufferMode mode) = 0;
	};


	class ITessControlShader : public IShader
	{
	public:
		virtual int GetOutputVertexCount() = 0;
	};

	
	class ITessEvaluationShader : public IShader
	{
	public:
		virtual TessGenPrimitiveType GetMode() = 0;
		virtual TessGenSpacing GetSpacing() = 0;
		virtual VertexOrder GetVertexOrder() = 0;
		virtual bool GetPointMode() = 0;
	};


	class IGeometryShader : public IShader
	{
	public:
		virtual int GetInvocations() = 0;
		virtual void TransformFeedbackVaryings(size_t count, const char** varyings, TransformFeedbackBufferMode mode) = 0;
	};


	class IFragmentShader : public IShader
	{
	public:
	};


	class IComputeShader : public IShader
	{
	public:
		virtual void GetWorkGroupSize(int work_group_size[3]) = 0;
	};

}

#endif // _GLSLAYER_SHADER_H_
