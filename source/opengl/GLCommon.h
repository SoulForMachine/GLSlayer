
#ifndef _GL_COMMON_H_
#define _GL_COMMON_H_

#if defined(_WIN32)
	#define WIN32_LEAN_AND_MEAN
	#define NOMINMAX
	#include <windows.h>
	#include <tchar.h>
	#pragma comment(lib, "opengl32.lib")
#elif defined(__linux__)
	#define GL_GLEXT_LEGACY 1
	#include <X11/Xlib.h>
	#include <X11/Xutil.h>
	#include <GL/glx.h>
#endif

#include <GL/gl.h>

#include "GLSlayer/Common.h"
#include "GLSlayer/Resource.h"
#include "extensions/h_glext.h"


using gls::ulong;
using gls::uint;
using gls::ushort;
using gls::ubyte;
using gls::uint64;
using gls::int64;


#define BUFFER_OFFSET(offset) ((char*)0 + (offset))


#define DECL_GL_ENUM_LOOKUP_TABLE(type, table) \
	extern const GLenum table[]; \
	gls::type GetFromGLEnum_##type(GLenum value); \
	template <> inline GLenum GetGLEnum<gls::type>(gls::type value) { return table[value]; } \
	template <> inline gls::type GetFromGLEnum<gls::type>(GLenum value) { return GetFromGLEnum_##type(value); }


template <class _EnumT>
GLenum GetGLEnum(_EnumT value);

template <class _EnumT>
_EnumT GetFromGLEnum(GLenum value);


DECL_GL_ENUM_LOOKUP_TABLE(BufferType, __bufferTypeTable)
DECL_GL_ENUM_LOOKUP_TABLE(ShaderType, __shaderTypeTable)
DECL_GL_ENUM_LOOKUP_TABLE(TextureType, __textureTypeTable)
DECL_GL_ENUM_LOOKUP_TABLE(QueryType, __queryTypeTable)
DECL_GL_ENUM_LOOKUP_TABLE(DataType, __dataTypeTable)
DECL_GL_ENUM_LOOKUP_TABLE(ImageFormat, __imageFormatTable)
DECL_GL_ENUM_LOOKUP_TABLE(PixelFormat, __pixelFormatTable)
DECL_GL_ENUM_LOOKUP_TABLE(CubeFace, __cubeFaceTable)
DECL_GL_ENUM_LOOKUP_TABLE(BufferAccess, __bufferAccessTable)
DECL_GL_ENUM_LOOKUP_TABLE(ColorBuffer, __colorBufferTable)
DECL_GL_ENUM_LOOKUP_TABLE(AttachmentBuffer, __attachmentBufferTable)
DECL_GL_ENUM_LOOKUP_TABLE(PolygonFace, __polygonFaceTable)
DECL_GL_ENUM_LOOKUP_TABLE(PrimitiveType, __primitiveTypeTable)
DECL_GL_ENUM_LOOKUP_TABLE(TessGenPrimitiveType, __tessGenPrimitiveTypeTable)
DECL_GL_ENUM_LOOKUP_TABLE(TessGenSpacing, __tessGenSpacingTable)
DECL_GL_ENUM_LOOKUP_TABLE(RasterMode, __rasterModeTable)
DECL_GL_ENUM_LOOKUP_TABLE(VertexOrder, __vertexOrderTable)
DECL_GL_ENUM_LOOKUP_TABLE(CompareFunc, __compareFuncTable)
DECL_GL_ENUM_LOOKUP_TABLE(StencilOp, __stencilOpTable)
DECL_GL_ENUM_LOOKUP_TABLE(BlendOp, __blendOpTable)
DECL_GL_ENUM_LOOKUP_TABLE(BlendFunc, __blendFuncTable)
DECL_GL_ENUM_LOOKUP_TABLE(ColorReadClamp, __colorReadClampTable)
DECL_GL_ENUM_LOOKUP_TABLE(LogicOp, __logicOpTable)
DECL_GL_ENUM_LOOKUP_TABLE(TexAddressMode, __texAddressingModeTable)
DECL_GL_ENUM_LOOKUP_TABLE(TexFilter, __texFilterTable)
DECL_GL_ENUM_LOOKUP_TABLE(TexCompareMode, __texCompareMode)
DECL_GL_ENUM_LOOKUP_TABLE(FramebufferStatus, __framebufferStatusTable)
DECL_GL_ENUM_LOOKUP_TABLE(SwapMethod, __swapMethodTable)
DECL_GL_ENUM_LOOKUP_TABLE(ColorBufferType, __colorBufferTypeTable)
DECL_GL_ENUM_LOOKUP_TABLE(ProgramParam, __programParamTable)
DECL_GL_ENUM_LOOKUP_TABLE(ConditionalRenderMode, __condRenderModeTable)
DECL_GL_ENUM_LOOKUP_TABLE(TransformFeedbackBufferMode, __tfBufferModeTable)
DECL_GL_ENUM_LOOKUP_TABLE(VertexConvention, __vertConventionModeTable)
DECL_GL_ENUM_LOOKUP_TABLE(FenceSyncCondition, __fenceSyncConditionTable)
DECL_GL_ENUM_LOOKUP_TABLE(SyncWaitStatus, __syncWaitStatusTable)
DECL_GL_ENUM_LOOKUP_TABLE(TexSwizzleSource, __texSwizzleSourceTable)
DECL_GL_ENUM_LOOKUP_TABLE(TexSwizzleDest, __texSwizzleDestTable)
DECL_GL_ENUM_LOOKUP_TABLE(FeatureSupport, __featureSupportTable)
DECL_GL_ENUM_LOOKUP_TABLE(TextureComponentType, __texComponentTypeTable)
DECL_GL_ENUM_LOOKUP_TABLE(ColorEncoding, __colorEncodingTable)
DECL_GL_ENUM_LOOKUP_TABLE(ImageClass, __imageClassTable)
DECL_GL_ENUM_LOOKUP_TABLE(ImageFormatCompatibilityType, __imageFormatCompatibilityTypeTable)
DECL_GL_ENUM_LOOKUP_TABLE(ViewClass, __viewClassTable)
DECL_GL_ENUM_LOOKUP_TABLE(DepthStencilTexMode, __depthStencilTexModeTable)
DECL_GL_ENUM_LOOKUP_TABLE(ErrorCode, __errorCodeTable)
DECL_GL_ENUM_LOOKUP_TABLE(DebugMessageSource, __debugMessageSourceTable)
DECL_GL_ENUM_LOOKUP_TABLE(DebugMessageType, __debugMessageTypeTable)
DECL_GL_ENUM_LOOKUP_TABLE(DebugMessageSeverity, __debugMessageSeverityTable)
DECL_GL_ENUM_LOOKUP_TABLE(ResourceType, __resourceTypeTable)



// Type ids of resource implementation classes
enum
{
	TYPE_ID_RESOURCE,
	
	TYPE_ID_BUFFER,
	
	TYPE_ID_TEXTURE,
	TYPE_ID_TEXTURE_1D,
	TYPE_ID_TEXTURE_2D,
	TYPE_ID_TEXTURE_2D_MULTISAMPLE,
	TYPE_ID_TEXTURE_3D,
	TYPE_ID_TEXTURE_CUBE,
	TYPE_ID_TEXTURE_1D_ARRAY,
	TYPE_ID_TEXTURE_2D_ARRAY,
	TYPE_ID_TEXTURE_2D_MULTISAMPLE_ARRAY,
	TYPE_ID_TEXTURE_CUBE_ARRAY,
	TYPE_ID_TEXTURE_BUFFER,
	TYPE_ID_TEXTURE_RECTANGLE,

	TYPE_ID_FRAMEBUFFER,
	TYPE_ID_RENDERBUFFER,

	TYPE_ID_SHADER,
	TYPE_ID_VERTEX_SHADER,
	TYPE_ID_TESS_CONTROL_SHADER,
	TYPE_ID_TESS_EVAL_SHADER,
	TYPE_ID_GEOMETRY_SHADER,
	TYPE_ID_FRAGMENT_SHADER,
	TYPE_ID_COMPUTE_SHADER,

	TYPE_ID_TRANSFORM_FEEDBACK,

	TYPE_ID_SAMPLER_STATE,
};


struct GLState
{
	// buffer objects
	GLuint vertexBuf;
	GLuint indexBuf;
	GLuint pixelPackBuf;
	GLuint pixelUnpackBuf;
	GLuint textureBuf;
	GLuint uniformBuf;
	GLuint transfFeedbackBuf;
	GLuint drawIndirectBuf;
	GLuint dispatchIndirectBuf;
	GLuint atomicCounterBuf;
	GLuint shaderStorageBuf;
	GLuint queryBuffer;

	// textures
	struct SamplerState
	{
		GLuint sampler;
		GLuint texture;
	};
	SamplerState* imageUnits;

	// GLSL
	GLuint glslProg;

	// framebuffer
	GLuint drawFbuf;
	GLuint readFbuf;

	// renderbuffer
	GLuint renderbuffer;

	// transform feedback
	GLuint transformFeedback;

	// pixel store
	gls::PixelStore pixelStorePack;
	gls::PixelStore pixelStoreUnpack;
};


void __SetPixelPackState(GLState* gl_state, const gls::PixelStore* pixel_store);
void __SetPixelUnpackState(GLState* gl_state, const gls::PixelStore* pixel_store);

template<class Type>
class dyn_cast_ptr;

template<class Type>
class dyn_cast_ptr<Type*>
{
public:
	dyn_cast_ptr(gls::IResource* res)	{ _res = res; }
	operator Type* ()		{ return (_res != 0) ? static_cast<Type*>(_res->DynamicCast(Type::typeID)) : 0; }
	Type* operator -> ()	{ return operator Type*(); }

private:
	gls::IResource* _res;
};

#endif // _GL_COMMON_H_
