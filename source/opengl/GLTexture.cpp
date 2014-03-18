
#include <cassert>
#include "GLBuffer.h"
#include "GLTexture.h"
#include "GLFramebuffer.h"

using namespace gls;


#define STATE_MACHINE_HACK \
	if(_id != _glState->imageUnits[0].texture) \
	{ \
		glBindTexture(_target, _id); \
		OPENGL_ERROR_CHECK \
		_glState->imageUnits[0].texture = _id; \
	}

#define PACK_BUFFER_STATE_MACHINE_HACK \
	if(dyn_cast_ptr<GLResource*>(buffer)->GetID() != _glState->pixelPackBuf) \
	{ \
		glBindBuffer(GL_PIXEL_PACK_BUFFER, dyn_cast_ptr<GLResource*>(buffer)->GetID()); \
		OPENGL_ERROR_CHECK \
		_glState->pixelPackBuf = dyn_cast_ptr<GLResource*>(buffer)->GetID(); \
	}

#define UNPACK_BUFFER_STATE_MACHINE_HACK \
	if(dyn_cast_ptr<GLResource*>(buffer)->GetID() != _glState->pixelUnpackBuf) \
	{ \
		glBindBuffer(GL_PIXEL_UNPACK_BUFFER, dyn_cast_ptr<GLResource*>(buffer)->GetID()); \
		OPENGL_ERROR_CHECK \
		_glState->pixelUnpackBuf = dyn_cast_ptr<GLResource*>(buffer)->GetID(); \
	}

#define FRAMEBUFFER_STATE_MACHINE_HACK \
	if(dyn_cast_ptr<GLFramebuffer*>(source_fbuf)->GetID() != _glState->readFbuf) \
	{ \
		glBindFramebuffer(GL_READ_FRAMEBUFFER, dyn_cast_ptr<GLFramebuffer*>(source_fbuf)->GetID()); \
		OPENGL_ERROR_CHECK \
		_glState->readFbuf = dyn_cast_ptr<GLFramebuffer*>(source_fbuf)->GetID(); \
	} \
	glReadBuffer(GetGLEnum(source_color_buf)); \
	OPENGL_ERROR_CHECK



bool IsCompressedFormat(PixelFormat format)
{
	switch(format)
	{
	case PIXEL_FORMAT_COMPRESSED_R:
	case PIXEL_FORMAT_COMPRESSED_RG:
	case PIXEL_FORMAT_COMPRESSED_RGB:
	case PIXEL_FORMAT_COMPRESSED_RGBA:
	case PIXEL_FORMAT_COMPRESSED_SRGB:
	case PIXEL_FORMAT_COMPRESSED_SRGB_A:
	case PIXEL_FORMAT_COMPRESSED_R_RGTC1:
	case PIXEL_FORMAT_COMPRESSED_SIGNED_R_RGTC1:
	case PIXEL_FORMAT_COMPRESSED_RG_RGTC2:
	case PIXEL_FORMAT_COMPRESSED_SIGNED_RG_RGTC2:
	case PIXEL_FORMAT_COMPRESSED_RGB_DXT1:
	case PIXEL_FORMAT_COMPRESSED_RGBA_DXT1:
	case PIXEL_FORMAT_COMPRESSED_RGBA_DXT3:
	case PIXEL_FORMAT_COMPRESSED_RGBA_DXT5:
	case PIXEL_FORMAT_COMPRESSED_SRGB_DXT1:
	case PIXEL_FORMAT_COMPRESSED_SRGB_A_DXT1:
	case PIXEL_FORMAT_COMPRESSED_SRGB_A_DXT3:
	case PIXEL_FORMAT_COMPRESSED_SRGB_A_DXT5:
	case PIXEL_FORMAT_COMPRESSED_RGBA_BPTC_UNORM:
	case PIXEL_FORMAT_COMPRESSED_SRGB_ALPHA_BPTC_UNORM:
	case PIXEL_FORMAT_COMPRESSED_RGB_BPTC_SIGNED_FLOAT:
	case PIXEL_FORMAT_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT:
	case PIXEL_FORMAT_COMPRESSED_RGB8_ETC2:
	case PIXEL_FORMAT_COMPRESSED_SRGB8_ETC2:
	case PIXEL_FORMAT_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2:
	case PIXEL_FORMAT_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2:
	case PIXEL_FORMAT_COMPRESSED_RGBA8_ETC2_EAC:
	case PIXEL_FORMAT_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC:
	case PIXEL_FORMAT_COMPRESSED_R11_EAC:
	case PIXEL_FORMAT_COMPRESSED_SIGNED_R11_EAC:
	case PIXEL_FORMAT_COMPRESSED_RG11_EAC:
	case PIXEL_FORMAT_COMPRESSED_SIGNED_RG11_EAC:
		return true;

	default:
		return false;
	};
}

//==================== Texture ====================

GLTexture::GLTexture()
{
	_baseLevel = 0;
	_maxLevel = 1000;
}

void GLTexture::Destroy()
{
	if(_id != 0)
	{
		GLuint tmp_id = _id;
		_id = 0;
		STATE_MACHINE_HACK
		glDeleteTextures(1, &tmp_id);
		OPENGL_ERROR_CHECK
	}
}

TextureType GLTexture::GetTextureType()
{
	return _textureType;
}

void GLTexture::GenerateMipmap()
{
	if(_textureType != TEXTURE_BUFFER_DATA && _textureType != TEXTURE_RECTANGLE)
	{
		STATE_MACHINE_HACK
		glGenerateMipmap(_target);
		OPENGL_ERROR_CHECK
	}
	else
	{
		assert(0);
	}
}

void GLTexture::SetBaseLevel(int base_level)
{
	STATE_MACHINE_HACK
	glTexParameteri(_target, GL_TEXTURE_BASE_LEVEL, base_level);
	OPENGL_ERROR_CHECK
	_baseLevel = base_level;
}

void GLTexture::SetMaxLevel(int max_level)
{
	STATE_MACHINE_HACK
	glTexParameteri(_target, GL_TEXTURE_MAX_LEVEL, max_level);
	OPENGL_ERROR_CHECK
	_maxLevel = max_level;
}

int GLTexture::GetCompressedSize(int level) const
{
	if(_textureType != TEXTURE_BUFFER_DATA && _textureType != TEXTURE_RECTANGLE)
	{
		STATE_MACHINE_HACK
		GLint size;
		glGetTexLevelParameteriv(_target, level, GL_TEXTURE_COMPRESSED_IMAGE_SIZE, &size);
		OPENGL_ERROR_CHECK
		return size;
	}
	else
	{
		assert(0);
		return 0;
	}
}

void GLTexture::ComponentSwizzle(TexSwizzleDest dest, TexSwizzleSource source)
{
	STATE_MACHINE_HACK
	glTexParameteri(_target, GetGLEnum(dest), GetGLEnum(source));
	OPENGL_ERROR_CHECK
}

void GLTexture::ComponentSwizzle(TexSwizzleSource source_red, TexSwizzleSource source_green, TexSwizzleSource source_blue, TexSwizzleSource source_alpha)
{
	GLint src_vals[] = {
		(GLint)GetGLEnum(source_red),
		(GLint)GetGLEnum(source_green),
		(GLint)GetGLEnum(source_blue),
		(GLint)GetGLEnum(source_alpha)
	};
	STATE_MACHINE_HACK
	glTexParameteriv(_target, GL_TEXTURE_SWIZZLE_RGBA, src_vals);
	OPENGL_ERROR_CHECK
}

void GLTexture::DepthStencilMode(DepthStencilTexMode mode)
{
	STATE_MACHINE_HACK
	glTexParameteri(_target, GL_DEPTH_STENCIL_TEXTURE_MODE, GetGLEnum(mode));
	OPENGL_ERROR_CHECK
}

//==================== Texture1D ====================

bool GLTexture1D::Create(GLState* gl_state)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glBindTexture(GL_TEXTURE_1D, _id);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;
	_resType = RES_TEXTURE;
	_textureType = TEXTURE_1D;
	_target = GL_TEXTURE_1D;
	_width = 0;

	return true;
}

bool GLTexture1D::CreateImmutable(GLState* gl_state, size_t levels, PixelFormat internal_format, int width)
{
	if(!Create(gl_state))
		return false;

	glTexStorage1D(GL_TEXTURE_1D, (GLsizei)levels, GetGLEnum(internal_format), width);
	OPENGL_ERROR_CHECK

	_format = internal_format;
	_width = width;

	return true;
}

bool GLTexture1D::CreateView(GLState* gl_state, GLuint orig_tex, PixelFormat internal_format, uint min_level, uint num_levels, uint min_layer)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glTextureView(_id, GL_TEXTURE_1D, orig_tex, GetGLEnum(internal_format), min_level, num_levels, min_layer, 1);
	OPENGL_ERROR_CHECK

	_resType = RES_TEXTURE;
	_textureType = TEXTURE_1D;
	_target = GL_TEXTURE_1D;
	_format = internal_format;

	glBindTexture(GL_TEXTURE_1D, _id);
	OPENGL_ERROR_CHECK
	glGetTexLevelParameteriv(GL_TEXTURE_1D, 0, GL_TEXTURE_WIDTH, &_width);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;

	return true;
}

void GLTexture1D::TexSubImage(int level, int xoffset, int width, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelUnpackState(_glState, pixel_store);
	glTexSubImage1D(GL_TEXTURE_1D, level, xoffset, width, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture1D::TexSubImage(int level, int xoffset, int width, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset)
{
	UNPACK_BUFFER_STATE_MACHINE_HACK
	TexSubImage(level, xoffset, width, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTexture1D::CompressedTexSubImage(int level, int xoffset, int width, ImageFormat format, size_t size, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	glCompressedTexSubImage1D(GL_TEXTURE_1D, level, xoffset, width, GetGLEnum(format), (GLsizei)size, pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture1D::CopyTexImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, PixelFormat internal_format, int x, int y, int width)
{
	assert(_id);
	FRAMEBUFFER_STATE_MACHINE_HACK
	STATE_MACHINE_HACK

	glCopyTexImage1D(GL_TEXTURE_1D, level, GetGLEnum(internal_format), x, y, width, 0);
	OPENGL_ERROR_CHECK

	if(level == 0)
	{
		_format = internal_format;
		_width = width;
	}
}

void GLTexture1D::CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, int xoffset, int x, int y, int width)
{
	assert(_id);
	FRAMEBUFFER_STATE_MACHINE_HACK
	STATE_MACHINE_HACK

	glCopyTexSubImage1D(GL_TEXTURE_1D, level, xoffset, x, y, width);
	OPENGL_ERROR_CHECK
}

void GLTexture1D::InvalidateTexImage(int level)
{
	assert(_id);
	glInvalidateTexImage(_id, level);
	OPENGL_ERROR_CHECK
}

void GLTexture1D::InvalidateTexSubImage(int level, int xoffset, int width)
{
	assert(_id);
	glInvalidateTexSubImage(_id, level, xoffset, 0, 0, width, 1, 1);
	OPENGL_ERROR_CHECK
}

void GLTexture1D::GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelPackState(_glState, pixel_store);
	glGetTexImage(GL_TEXTURE_1D, level, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture1D::GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetTexImage(level, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTexture1D::GetCompressedTexImage(int level, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	glGetCompressedTexImage(GL_TEXTURE_1D, level, pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture1D::GetCompressedTexImage(int level, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetCompressedTexImage(level, BUFFER_OFFSET(buffer_offset));
}


//==================== Texture2D ====================

bool GLTexture2D::Create(GLState* gl_state)
{
	if(_id)
		return false;
	
	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glBindTexture(GL_TEXTURE_2D, _id);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;
	_resType = RES_TEXTURE;
	_textureType = TEXTURE_2D;
	_target = GL_TEXTURE_2D;
	_width = 0;
	_height = 0;

	return true;
}

bool GLTexture2D::CreateImmutable(GLState* gl_state, size_t levels, PixelFormat internal_format, int width, int height)
{
	if(!Create(gl_state))
		return false;

	glTexStorage2D(GL_TEXTURE_2D, (GLsizei)levels, GetGLEnum(internal_format), width, height);
	OPENGL_ERROR_CHECK

	_format = internal_format;
	_width = width;
	_height = height;

	return true;
}

bool GLTexture2D::CreateView(GLState* gl_state, GLuint orig_tex, PixelFormat internal_format, uint min_level, uint num_levels, uint min_layer)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glTextureView(_id, GL_TEXTURE_2D, orig_tex, GetGLEnum(internal_format), min_level, num_levels, min_layer, 1);
	OPENGL_ERROR_CHECK

	_resType = RES_TEXTURE;
	_textureType = TEXTURE_2D;
	_target = GL_TEXTURE_2D;
	_format = internal_format;

	glBindTexture(GL_TEXTURE_2D, _id);
	OPENGL_ERROR_CHECK

	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &_width);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &_height);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;

	return true;
}

void GLTexture2D::TexSubImage(int level, int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelUnpackState(_glState, pixel_store);
	glTexSubImage2D(GL_TEXTURE_2D, level, xoffset, yoffset, width, height, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture2D::TexSubImage(int level, int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset)
{
	UNPACK_BUFFER_STATE_MACHINE_HACK
	TexSubImage(level, xoffset, yoffset, width, height, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTexture2D::CompressedTexSubImage(int level, int xoffset, int yoffset, int width, int height, ImageFormat format, size_t size, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	glCompressedTexSubImage2D(GL_TEXTURE_2D, level, xoffset, yoffset, width, height, GetGLEnum(format), (GLsizei)size, pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture2D::CopyTexImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, PixelFormat internal_format, int x, int y, int width, int height)
{
	assert(_id);
	FRAMEBUFFER_STATE_MACHINE_HACK
	STATE_MACHINE_HACK

	glCopyTexImage2D(GL_TEXTURE_2D, level, GetGLEnum(internal_format), x, y, width, height, 0);
	OPENGL_ERROR_CHECK

	if(level == 0)
	{
		_format = internal_format;
		_width = width;
		_height = height;
	}
}

void GLTexture2D::CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int x, int y, int width, int height)
{
	assert(_id);
	FRAMEBUFFER_STATE_MACHINE_HACK
	STATE_MACHINE_HACK

	glCopyTexSubImage2D(GL_TEXTURE_2D, level, xoffset, yoffset, x, y, width, height);
	OPENGL_ERROR_CHECK
}

void GLTexture2D::InvalidateTexImage(int level)
{
	assert(_id);
	glInvalidateTexImage(_id, level);
	OPENGL_ERROR_CHECK
}

void GLTexture2D::InvalidateTexSubImage(int level, int xoffset, int yoffset, int width, int height)
{
	assert(_id);
	glInvalidateTexSubImage(_id, level, xoffset, yoffset, 0, width, height, 1);
	OPENGL_ERROR_CHECK
}

void GLTexture2D::GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelPackState(_glState, pixel_store);
	glGetTexImage(GL_TEXTURE_2D, level, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture2D::GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetTexImage(level, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTexture2D::GetCompressedTexImage(int level, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	glGetCompressedTexImage(GL_TEXTURE_2D, level, pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture2D::GetCompressedTexImage(int level, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetCompressedTexImage(level, BUFFER_OFFSET(buffer_offset));
}

//==================== Texture2DMultisample ====================

bool GLTexture2DMultisample::Create(GLState* gl_state)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, _id);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;
	_resType = RES_TEXTURE;
	_textureType = TEXTURE_2D_MULTISAMPLE;
	_target = GL_TEXTURE_2D_MULTISAMPLE;
	_width = 0;
	_height = 0;

	return true;
}

bool GLTexture2DMultisample::CreateImmutable(GLState* gl_state, int samples, PixelFormat internal_format, int width, int height, bool fixed_sample_locations)
{
	if(!Create(gl_state))
		return false;

	glTexStorage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, samples, GetGLEnum(internal_format), width, height, fixed_sample_locations);
	OPENGL_ERROR_CHECK

	_format = internal_format;
	_width = width;
	_height = height;

	return true;
}

bool GLTexture2DMultisample::CreateView(GLState* gl_state, GLuint orig_tex, PixelFormat internal_format, uint min_level, uint num_levels)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glTextureView(_id, GL_TEXTURE_2D_MULTISAMPLE, orig_tex, GetGLEnum(internal_format), min_level, num_levels, 0, 1);
	OPENGL_ERROR_CHECK

	_resType = RES_TEXTURE;
	_textureType = TEXTURE_2D_MULTISAMPLE;
	_target = GL_TEXTURE_2D_MULTISAMPLE;
	_format = internal_format;

	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, _id);
	OPENGL_ERROR_CHECK

	glGetTexLevelParameteriv(GL_TEXTURE_2D_MULTISAMPLE, 0, GL_TEXTURE_WIDTH, &_width);
	glGetTexLevelParameteriv(GL_TEXTURE_2D_MULTISAMPLE, 0, GL_TEXTURE_HEIGHT, &_height);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;

	return true;
}

void GLTexture2DMultisample::InvalidateTexImage()
{
	assert(_id);
	glInvalidateTexImage(_id, 0);
	OPENGL_ERROR_CHECK
}

void GLTexture2DMultisample::InvalidateTexSubImage(int xoffset, int yoffset, int width, int height)
{
	assert(_id);
	glInvalidateTexSubImage(_id, 0, xoffset, yoffset, 0, width, height, 1);
	OPENGL_ERROR_CHECK
}

//==================== Texture3D ====================

bool GLTexture3D::Create(GLState* gl_state)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glBindTexture(GL_TEXTURE_3D, _id);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;
	_resType = RES_TEXTURE;
	_textureType = TEXTURE_3D;
	_target = GL_TEXTURE_3D;
	_width = 0;
	_height = 0;
	_depth = 0;

	return true;
}

bool GLTexture3D::CreateImmutable(GLState* gl_state, size_t levels, PixelFormat internal_format, int width, int height, int depth)
{
	if(!Create(gl_state))
		return false;

	glTexStorage3D(GL_TEXTURE_3D, (GLsizei)levels, GetGLEnum(internal_format), width, height, depth);
	OPENGL_ERROR_CHECK

	_format = internal_format;
	_width = width;
	_height = height;
	_depth = depth;

	return true;
}

bool GLTexture3D::CreateView(GLState* gl_state, GLuint orig_tex, PixelFormat internal_format, uint min_level, uint num_levels)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glTextureView(_id, GL_TEXTURE_3D, orig_tex, GetGLEnum(internal_format), min_level, num_levels, 0, 1);
	OPENGL_ERROR_CHECK

	_resType = RES_TEXTURE;
	_textureType = TEXTURE_3D;
	_target = GL_TEXTURE_3D;
	_format = internal_format;

	glBindTexture(GL_TEXTURE_3D, _id);
	OPENGL_ERROR_CHECK

	glGetTexLevelParameteriv(GL_TEXTURE_3D, 0, GL_TEXTURE_WIDTH, &_width);
	glGetTexLevelParameteriv(GL_TEXTURE_3D, 0, GL_TEXTURE_HEIGHT, &_height);
	glGetTexLevelParameteriv(GL_TEXTURE_3D, 0, GL_TEXTURE_DEPTH, &_depth);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;

	return true;
}
	
void GLTexture3D::TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelUnpackState(_glState, pixel_store);
	glTexSubImage3D(GL_TEXTURE_3D, level, xoffset, yoffset, zoffset, width, height, depth, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture3D::TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset)
{
	UNPACK_BUFFER_STATE_MACHINE_HACK
	TexSubImage(level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTexture3D::CompressedTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, size_t size, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	glCompressedTexSubImage3D(GL_TEXTURE_3D, level, xoffset, yoffset, zoffset, width, height, depth, GetGLEnum(format), (GLsizei)size, pixels);
	OPENGL_ERROR_CHECK
}
	
void GLTexture3D::CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height)
{
	//assert(false && "do not call this function for now, no GL_EXT_copy_texture extension although glCopyTexSubImage3DEXT entry exists");

	assert(_id);
	FRAMEBUFFER_STATE_MACHINE_HACK
	STATE_MACHINE_HACK

	glCopyTexSubImage3D(GL_TEXTURE_3D, level, xoffset, yoffset, zoffset, x, y, width, height);
	OPENGL_ERROR_CHECK
}

void GLTexture3D::InvalidateTexImage(int level)
{
	assert(_id);
	glInvalidateTexImage(_id, level);
	OPENGL_ERROR_CHECK
}

void GLTexture3D::InvalidateTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth)
{
	assert(_id);
	glInvalidateTexSubImage(_id, level, xoffset, yoffset, zoffset, width, height, depth);
	OPENGL_ERROR_CHECK
}

void GLTexture3D::GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelPackState(_glState, pixel_store);
	glGetTexImage(GL_TEXTURE_3D, level, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture3D::GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetTexImage(level, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTexture3D::GetCompressedTexImage(int level, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	glGetCompressedTexImage(GL_TEXTURE_3D, level, pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture3D::GetCompressedTexImage(int level, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetCompressedTexImage(level, BUFFER_OFFSET(buffer_offset));
}

//==================== TextureCube ====================

bool GLTextureCube::Create(GLState* gl_state)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glBindTexture(GL_TEXTURE_CUBE_MAP, _id);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;
	_resType = RES_TEXTURE;
	_textureType = TEXTURE_CUBE;
	_target = GL_TEXTURE_CUBE_MAP;
	_width = 0;

	return true;
}

bool GLTextureCube::CreateImmutable(GLState* gl_state, size_t levels, PixelFormat internal_format, int width)
{
	if(!Create(gl_state))
		return false;

	glTexStorage2D(GL_TEXTURE_CUBE_MAP, (GLsizei)levels, GetGLEnum(internal_format), width, width);
	OPENGL_ERROR_CHECK

	_format = internal_format;
	_width = width;

	return true;
}

bool GLTextureCube::CreateView(GLState* gl_state, GLuint orig_tex, PixelFormat internal_format, uint min_level, uint num_levels, uint min_layer, uint num_layers)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glTextureView(_id, GL_TEXTURE_CUBE_MAP, orig_tex, GetGLEnum(internal_format), min_level, num_levels, min_layer, num_layers);
	OPENGL_ERROR_CHECK

	_resType = RES_TEXTURE;
	_textureType = TEXTURE_2D;
	_target = GL_TEXTURE_CUBE_MAP;
	_format = internal_format;

	glBindTexture(GL_TEXTURE_CUBE_MAP, _id);
	OPENGL_ERROR_CHECK

	glGetTexLevelParameteriv(GL_TEXTURE_CUBE_MAP, 0, GL_TEXTURE_WIDTH, &_width);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;

	return true;
}

void GLTextureCube::TexSubImage(CubeFace face, int level, int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelUnpackState(_glState, pixel_store);
	glTexSubImage2D(GetGLEnum(face), level, xoffset, yoffset, width, height, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTextureCube::TexSubImage(CubeFace face, int level, int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset)
{
	UNPACK_BUFFER_STATE_MACHINE_HACK
	TexSubImage(face, level, xoffset, yoffset, width, height, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTextureCube::CompressedTexSubImage(CubeFace face, int level, int xoffset, int yoffset, int width, int height, ImageFormat format, size_t size, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	glCompressedTexSubImage2D(GetGLEnum(face), level, xoffset, yoffset, width, height, GetGLEnum(format), (GLsizei)size, pixels);
	OPENGL_ERROR_CHECK
}

void GLTextureCube::CopyTexImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, CubeFace face, int level, PixelFormat internal_format, int x, int y, int width)
{
	assert(_id);
	FRAMEBUFFER_STATE_MACHINE_HACK
	STATE_MACHINE_HACK

	glCopyTexImage2D(GetGLEnum(face), level, GetGLEnum(internal_format), x, y, width, width, 0);
	OPENGL_ERROR_CHECK

	if(level == 0)
	{
		_format = internal_format;
		_width = width;
	}
}

void GLTextureCube::CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, CubeFace face, int level, int xoffset, int yoffset, int x, int y, int width, int height)
{
	assert(_id);
	FRAMEBUFFER_STATE_MACHINE_HACK
	STATE_MACHINE_HACK

	glCopyTexSubImage2D(GetGLEnum(face), level, xoffset, yoffset, x, y, width, height);
	OPENGL_ERROR_CHECK
}

void GLTextureCube::InvalidateTexImage(int level)
{
	assert(_id);
	glInvalidateTexImage(_id, level);
	OPENGL_ERROR_CHECK
}

void GLTextureCube::InvalidateTexSubImage(CubeFace face, int level, int xoffset, int yoffset, int width, int height)
{
	assert(_id);
	glInvalidateTexSubImage(_id, level, xoffset, yoffset, (GLint)face, width, height, 1); //! depth?
	OPENGL_ERROR_CHECK
}

void GLTextureCube::GetTexImage(CubeFace face, int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelPackState(_glState, pixel_store);
	glGetTexImage(GetGLEnum(face), level, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTextureCube::GetTexImage(CubeFace face, int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetTexImage(face, level, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTextureCube::GetCompressedTexImage(CubeFace face, int level, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	glGetCompressedTexImage(GetGLEnum(face), level, pixels);
	OPENGL_ERROR_CHECK
}

void GLTextureCube::GetCompressedTexImage(CubeFace face, int level, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetCompressedTexImage(face, level, BUFFER_OFFSET(buffer_offset));
}

//==================== Texture1DArray ====================

bool GLTexture1DArray::Create(GLState* gl_state)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glBindTexture(GL_TEXTURE_1D_ARRAY, _id);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;
	_resType = RES_TEXTURE;
	_textureType = TEXTURE_1D_ARRAY;
	_target = GL_TEXTURE_1D_ARRAY;
	_width = 0;
	_height = 0;

	return true;
}

bool GLTexture1DArray::CreateImmutable(GLState* gl_state, size_t levels, PixelFormat internal_format, int width, int height)
{
	if(!Create(gl_state))
		return false;

	glTexStorage2D(GL_TEXTURE_1D_ARRAY, (GLsizei)levels, GetGLEnum(internal_format), width, height);
	OPENGL_ERROR_CHECK

	_format = internal_format;
	_width = width;
	_height = height;

	return true;
}

bool GLTexture1DArray::CreateView(GLState* gl_state, GLuint orig_tex, PixelFormat internal_format, uint min_level, uint num_levels, uint min_layer, uint num_layers)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glTextureView(_id, GL_TEXTURE_1D_ARRAY, orig_tex, GetGLEnum(internal_format), min_level, num_levels, min_layer, num_layers);
	OPENGL_ERROR_CHECK

	_resType = RES_TEXTURE;
	_textureType = TEXTURE_1D_ARRAY;
	_target = GL_TEXTURE_1D_ARRAY;
	_format = internal_format;

	glBindTexture(GL_TEXTURE_1D_ARRAY, _id);
	OPENGL_ERROR_CHECK

	glGetTexLevelParameteriv(GL_TEXTURE_1D_ARRAY, 0, GL_TEXTURE_WIDTH, &_width);
	glGetTexLevelParameteriv(GL_TEXTURE_1D_ARRAY, 0, GL_TEXTURE_HEIGHT, &_height);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;

	return true;
}

void GLTexture1DArray::TexSubImage(int level, int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelUnpackState(_glState, pixel_store);
	glTexSubImage2D(GL_TEXTURE_1D_ARRAY, level, xoffset, yoffset, width, height, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture1DArray::TexSubImage(int level, int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset)
{
	UNPACK_BUFFER_STATE_MACHINE_HACK
	TexSubImage(level, xoffset, yoffset, width, height, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTexture1DArray::CompressedTexSubImage(int level, int xoffset, int yoffset, int width, int height, ImageFormat format, size_t size, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	glCompressedTexSubImage2D(GL_TEXTURE_1D_ARRAY, level, xoffset, yoffset, width, height, GetGLEnum(format), (GLsizei)size, pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture1DArray::CopyTexImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, PixelFormat internal_format, int x, int y, int width, int height)
{
	assert(_id);
	FRAMEBUFFER_STATE_MACHINE_HACK
	STATE_MACHINE_HACK

	glCopyTexImage2D(GL_TEXTURE_1D_ARRAY, level, GetGLEnum(internal_format), x, y, width, height, 0);
	OPENGL_ERROR_CHECK

	if(level == 0)
	{
		_format = internal_format;
		_width = width;
		_height = height;
	}
}

void GLTexture1DArray::CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int x, int y, int width, int height)
{
	assert(_id);
	FRAMEBUFFER_STATE_MACHINE_HACK
	STATE_MACHINE_HACK

	glCopyTexSubImage2D(GL_TEXTURE_1D_ARRAY, level, xoffset, yoffset, x, y, width, height);
	OPENGL_ERROR_CHECK
}

void GLTexture1DArray::InvalidateTexImage(int level)
{
	assert(_id);
	glInvalidateTexImage(_id, level);
	OPENGL_ERROR_CHECK
}

void GLTexture1DArray::InvalidateTexSubImage(int level, int xoffset, int yoffset, int width, int height)
{
	assert(_id);
	glInvalidateTexSubImage(_id, level, xoffset, yoffset, 0, width, height, 1);
	OPENGL_ERROR_CHECK
}

void GLTexture1DArray::GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelPackState(_glState, pixel_store);
	glGetTexImage(GL_TEXTURE_1D_ARRAY, level, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture1DArray::GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetTexImage(level, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTexture1DArray::GetCompressedTexImage(int level, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	glGetCompressedTexImage(GL_TEXTURE_1D_ARRAY, level, pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture1DArray::GetCompressedTexImage(int level, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetCompressedTexImage(level, BUFFER_OFFSET(buffer_offset));
}

//==================== Texture2DArray ====================

bool GLTexture2DArray::Create(GLState* gl_state)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glBindTexture(GL_TEXTURE_2D_ARRAY, _id);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;
	_resType = RES_TEXTURE;
	_textureType = TEXTURE_2D_ARRAY;
	_target = GL_TEXTURE_2D_ARRAY;
	_width = 0;
	_height = 0;
	_depth = 0;

	return true;
}

bool GLTexture2DArray::CreateImmutable(GLState* gl_state, size_t levels, PixelFormat internal_format, int width, int height, int depth)
{
	if(!Create(gl_state))
		return false;

	glTexStorage3D(GL_TEXTURE_2D_ARRAY, (GLsizei)levels, GetGLEnum(internal_format), width, height, depth);
	OPENGL_ERROR_CHECK

	_format = internal_format;
	_width = width;
	_height = height;
	_depth = depth;

	return true;
}

bool GLTexture2DArray::CreateView(GLState* gl_state, GLuint orig_tex, PixelFormat internal_format, uint min_level, uint num_levels, uint min_layer, uint num_layers)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glTextureView(_id, GL_TEXTURE_2D_ARRAY, orig_tex, GetGLEnum(internal_format), min_level, num_levels, min_layer, num_layers);
	OPENGL_ERROR_CHECK

	_resType = RES_TEXTURE;
	_textureType = TEXTURE_2D_ARRAY;
	_target = GL_TEXTURE_2D_ARRAY;
	_format = internal_format;

	glBindTexture(GL_TEXTURE_2D_ARRAY, _id);
	OPENGL_ERROR_CHECK

	glGetTexLevelParameteriv(GL_TEXTURE_2D_ARRAY, 0, GL_TEXTURE_WIDTH, &_width);
	glGetTexLevelParameteriv(GL_TEXTURE_2D_ARRAY, 0, GL_TEXTURE_HEIGHT, &_height);
	glGetTexLevelParameteriv(GL_TEXTURE_2D_ARRAY, 0, GL_TEXTURE_HEIGHT, &_depth);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;

	return true;
}

void GLTexture2DArray::TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelUnpackState(_glState, pixel_store);
	glTexSubImage3D(GL_TEXTURE_2D_ARRAY, level, xoffset, yoffset, zoffset, width, height, depth, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture2DArray::TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset)
{
	UNPACK_BUFFER_STATE_MACHINE_HACK
	TexSubImage(level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTexture2DArray::CompressedTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, size_t size, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	glCompressedTexSubImage3D(GL_TEXTURE_2D_ARRAY, level, xoffset, yoffset, zoffset, width, height, depth, GetGLEnum(format), (GLsizei)size, pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture2DArray::CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height)
{
	assert(_id);
	FRAMEBUFFER_STATE_MACHINE_HACK
	STATE_MACHINE_HACK

	glCopyTexSubImage3D(GL_TEXTURE_2D_ARRAY, level, xoffset, yoffset, zoffset, x, y, width, height);
	OPENGL_ERROR_CHECK
}

void GLTexture2DArray::InvalidateTexImage(int level)
{
	assert(_id);
	glInvalidateTexImage(_id, level);
	OPENGL_ERROR_CHECK
}

void GLTexture2DArray::InvalidateTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth)
{
	assert(_id);
	glInvalidateTexSubImage(_id, level, xoffset, yoffset, zoffset, width, height, depth);
	OPENGL_ERROR_CHECK
}

void GLTexture2DArray::GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelPackState(_glState, pixel_store);
	glGetTexImage(GL_TEXTURE_2D_ARRAY, level, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture2DArray::GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetTexImage(level, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTexture2DArray::GetCompressedTexImage(int level, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	glGetCompressedTexImage(GL_TEXTURE_2D_ARRAY, level, pixels);
	OPENGL_ERROR_CHECK
}

void GLTexture2DArray::GetCompressedTexImage(int level, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetCompressedTexImage(level, BUFFER_OFFSET(buffer_offset));
}

//==================== Texture2DMultisampleArray ====================

bool GLTexture2DMultisampleArray::Create(GLState* gl_state)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, _id);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;
	_resType = RES_TEXTURE;
	_textureType = TEXTURE_2D_MULTISAMPLE_ARRAY;
	_target = GL_TEXTURE_2D_MULTISAMPLE_ARRAY;
	_width = 0;
	_height = 0;
	_depth = 0;

	return true;
}

bool GLTexture2DMultisampleArray::CreateImmutable(GLState* gl_state, int samples, PixelFormat internal_format, int width, int height, int depth, bool fixed_sample_locations)
{
	if(!Create(gl_state))
		return false;

	glTexStorage3DMultisample(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, samples, GetGLEnum(internal_format), width, height, depth, fixed_sample_locations);
	OPENGL_ERROR_CHECK

	_format = internal_format;
	_width = width;
	_height = height;
	_depth = depth;

	return true;
}

bool GLTexture2DMultisampleArray::CreateView(GLState* gl_state, GLuint orig_tex, PixelFormat internal_format, uint min_level, uint num_levels, uint min_layer, uint num_layers)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glTextureView(_id, GL_TEXTURE_2D_MULTISAMPLE_ARRAY, orig_tex, GetGLEnum(internal_format), min_level, num_levels, min_layer, num_layers);
	OPENGL_ERROR_CHECK

	_resType = RES_TEXTURE;
	_textureType = TEXTURE_2D_MULTISAMPLE_ARRAY;
	_target = GL_TEXTURE_2D_MULTISAMPLE_ARRAY;
	_format = internal_format;

	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, _id);
	OPENGL_ERROR_CHECK

	glGetTexLevelParameteriv(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, 0, GL_TEXTURE_WIDTH, &_width);
	glGetTexLevelParameteriv(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, 0, GL_TEXTURE_HEIGHT, &_height);
	glGetTexLevelParameteriv(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, 0, GL_TEXTURE_HEIGHT, &_depth);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;

	return true;
}

void GLTexture2DMultisampleArray::InvalidateTexImage()
{
	assert(_id);
	glInvalidateTexImage(_id, 0);
	OPENGL_ERROR_CHECK
}

void GLTexture2DMultisampleArray::InvalidateTexSubImage(int xoffset, int yoffset, int zoffset, int width, int height, int depth)
{
	assert(_id);
	glInvalidateTexSubImage(_id, 0, xoffset, yoffset, zoffset, width, height, depth);
	OPENGL_ERROR_CHECK
}

//==================== TextureCubeArray ====================

bool GLTextureCubeArray::Create(GLState* gl_state)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glBindTexture(GL_TEXTURE_CUBE_MAP_ARRAY, _id);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;
	_resType = RES_TEXTURE;
	_textureType = TEXTURE_CUBE_ARRAY;
	_target = GL_TEXTURE_CUBE_MAP_ARRAY;
	_width = 0;
	_depth = 0;

	return true;
}

bool GLTextureCubeArray::CreateImmutable(GLState* gl_state, size_t levels, PixelFormat internal_format, int width, int depth)
{
	if(!Create(gl_state))
		return false;

	glTexStorage3D(GL_TEXTURE_CUBE_MAP_ARRAY, (GLsizei)levels, GetGLEnum(internal_format), width, width, depth);
	OPENGL_ERROR_CHECK

	_format = internal_format;
	_width = width;
	_depth = depth;

	return true;
}

bool GLTextureCubeArray::CreateView(GLState* gl_state, GLuint orig_tex, PixelFormat internal_format, uint min_level, uint num_levels, uint min_layer, uint num_layers)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glTextureView(_id, GL_TEXTURE_CUBE_MAP_ARRAY, orig_tex, GetGLEnum(internal_format), min_level, num_levels, min_layer, num_layers);
	OPENGL_ERROR_CHECK

	_resType = RES_TEXTURE;
	_textureType = TEXTURE_CUBE_ARRAY;
	_target = GL_TEXTURE_CUBE_MAP_ARRAY;
	_format = internal_format;

	glBindTexture(GL_TEXTURE_CUBE_MAP_ARRAY, _id);
	OPENGL_ERROR_CHECK

	glGetTexLevelParameteriv(GL_TEXTURE_CUBE_MAP_ARRAY, 0, GL_TEXTURE_WIDTH, &_width);
	glGetTexLevelParameteriv(GL_TEXTURE_CUBE_MAP_ARRAY, 0, GL_TEXTURE_DEPTH, &_depth);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;

	return true;
}

void GLTextureCubeArray::TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelUnpackState(_glState, pixel_store);
	glTexSubImage3D(GL_TEXTURE_CUBE_MAP_ARRAY, level, xoffset, yoffset, zoffset, width, height, depth, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTextureCubeArray::TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset)
{
	UNPACK_BUFFER_STATE_MACHINE_HACK
	TexSubImage(level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTextureCubeArray::CompressedTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, size_t size, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	glCompressedTexSubImage3D(GL_TEXTURE_CUBE_MAP_ARRAY, level, xoffset, yoffset, zoffset, width, height, depth, GetGLEnum(format), (GLsizei)size, pixels);
	OPENGL_ERROR_CHECK
}

void GLTextureCubeArray::CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height)
{
	assert(_id);
	FRAMEBUFFER_STATE_MACHINE_HACK
	STATE_MACHINE_HACK

	glCopyTexSubImage3D(GL_TEXTURE_CUBE_MAP_ARRAY, level, xoffset, yoffset, zoffset, x, y, width, height);
	OPENGL_ERROR_CHECK
}

void GLTextureCubeArray::InvalidateTexImage(int level)
{
	assert(_id);
	glInvalidateTexImage(_id, level);
	OPENGL_ERROR_CHECK
}

void GLTextureCubeArray::InvalidateTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth)
{
	assert(_id);
	glInvalidateTexSubImage(_id, level, xoffset, yoffset, zoffset, width, height, depth);
	OPENGL_ERROR_CHECK
}

void GLTextureCubeArray::GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelPackState(_glState, pixel_store);
	glGetTexImage(GL_TEXTURE_CUBE_MAP_ARRAY, level, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTextureCubeArray::GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetTexImage(level, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

//==================== TextureBuffer ====================

bool GLTextureBuffer::Create(GLState* gl_state)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glBindTexture(GL_TEXTURE_BUFFER, _id);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;
	_resType = RES_TEXTURE;
	_textureType = TEXTURE_BUFFER_DATA;
	_target = GL_TEXTURE_BUFFER;
	_size = 0;

	return true;
}

void GLTextureBuffer::TexBuffer(PixelFormat internal_format, IBuffer* buffer)
{
	assert(_id);
	STATE_MACHINE_HACK

	glTexBuffer(GL_TEXTURE_BUFFER, GetGLEnum(internal_format), dyn_cast_ptr<GLResource*>(buffer)->GetID());
	OPENGL_ERROR_CHECK

	_format = internal_format;
	_size = dyn_cast_ptr<GLBuffer*>(buffer)->GetSize();
}

void GLTextureBuffer::TexBufferRange(PixelFormat internal_format, IBuffer* buffer, size_t offset, size_t size)
{
	assert(_id);
	STATE_MACHINE_HACK

	glTexBufferRange(GL_TEXTURE_BUFFER, GetGLEnum(internal_format), dyn_cast_ptr<GLResource*>(buffer)->GetID(), offset, size);
	OPENGL_ERROR_CHECK

	_format = internal_format;
	_size = dyn_cast_ptr<GLBuffer*>(buffer)->GetSize();
}

void GLTextureBuffer::InvalidateTexImage()
{
	assert(_id);
	glInvalidateTexImage(_id, 0);
	OPENGL_ERROR_CHECK
}

void GLTextureBuffer::InvalidateTexSubImage(int xoffset, int yoffset, int width, int height)
{
	assert(_id);
	glInvalidateTexSubImage(_id, 0, xoffset, yoffset, 0, width, height, 1);
	OPENGL_ERROR_CHECK
}

//==================== TextureRectangle ====================
// - REPEAT AND MIRRORED_REPEAT not alowed for texture wrap mode
// - minification filter must be NEAREST or LINEAR
// - compressed formats not allowed
// - mipmaps not allowed
// - texture base level must be 0

bool GLTextureRectangle::Create(GLState* gl_state)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glBindTexture(GL_TEXTURE_RECTANGLE, _id);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;
	_resType = RES_TEXTURE;
	_textureType = TEXTURE_RECTANGLE;
	_target = GL_TEXTURE_RECTANGLE;
	_width = 0;
	_height = 0;

	return true;
}

bool GLTextureRectangle::CreateImmutable(GLState* gl_state, size_t levels, PixelFormat internal_format, int width, int height)
{
	if(!Create(gl_state))
		return false;

	glTexStorage2D(GL_TEXTURE_RECTANGLE, (GLsizei)levels, GetGLEnum(internal_format), width, height);
	OPENGL_ERROR_CHECK

	_format = internal_format;
	_width = width;
	_height = height;

	return true;
}

bool GLTextureRectangle::CreateView(GLState* gl_state, GLuint orig_tex, PixelFormat internal_format, uint min_level, uint num_levels)
{
	if(_id)
		return false;

	_glState = gl_state;

	glGenTextures(1, &_id);
	OPENGL_ERROR_CHECK
	if(!_id)
		return false;

	glTextureView(_id, GL_TEXTURE_RECTANGLE, orig_tex, GetGLEnum(internal_format), min_level, num_levels, 0, 1);
	OPENGL_ERROR_CHECK

	_resType = RES_TEXTURE;
	_textureType = TEXTURE_RECTANGLE;
	_target = GL_TEXTURE_RECTANGLE;
	_format = internal_format;

	glBindTexture(GL_TEXTURE_RECTANGLE, _id);
	OPENGL_ERROR_CHECK

	glGetTexLevelParameteriv(GL_TEXTURE_RECTANGLE, 0, GL_TEXTURE_WIDTH, &_width);
	glGetTexLevelParameteriv(GL_TEXTURE_RECTANGLE, 0, GL_TEXTURE_HEIGHT, &_height);
	OPENGL_ERROR_CHECK
	_glState->imageUnits[0].texture = _id;

	return true;
}

void GLTextureRectangle::TexSubImage(int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels)
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelUnpackState(_glState, pixel_store);
	glTexSubImage2D(GL_TEXTURE_RECTANGLE, 0, xoffset, yoffset, width, height, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTextureRectangle::TexSubImage(int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset)
{
	UNPACK_BUFFER_STATE_MACHINE_HACK
	TexSubImage(xoffset, yoffset, width, height, format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}

void GLTextureRectangle::CopyTexImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, PixelFormat internal_format, int x, int y, int width, int height)
{
	assert(_id);
	FRAMEBUFFER_STATE_MACHINE_HACK
	STATE_MACHINE_HACK

	glCopyTexImage2D(GL_TEXTURE_RECTANGLE, 0, GetGLEnum(internal_format), x, y, width, height, 0);
	OPENGL_ERROR_CHECK

	_format = internal_format;
	_width = width;
	_height = height;
}

void GLTextureRectangle::CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int xoffset, int yoffset, int x, int y, int width, int height)
{
	assert(_id);
	FRAMEBUFFER_STATE_MACHINE_HACK
	STATE_MACHINE_HACK

	glCopyTexSubImage2D(GL_TEXTURE_RECTANGLE, 0, xoffset, yoffset, x, y, width, height);
	OPENGL_ERROR_CHECK
}

void GLTextureRectangle::InvalidateTexImage()
{
	assert(_id);
	glInvalidateTexImage(_id, 0);
	OPENGL_ERROR_CHECK
}

void GLTextureRectangle::InvalidateTexSubImage(int xoffset, int yoffset, int width, int height)
{
	assert(_id);
	glInvalidateTexSubImage(_id, 0, xoffset, yoffset, 0, width, height, 1);
	OPENGL_ERROR_CHECK
}

void GLTextureRectangle::GetTexImage(ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const
{
	assert(_id);
	STATE_MACHINE_HACK

	__SetPixelPackState(_glState, pixel_store);
	glGetTexImage(GL_TEXTURE_RECTANGLE, 0, GetGLEnum(format), GetGLEnum(type), pixels);
	OPENGL_ERROR_CHECK
}

void GLTextureRectangle::GetTexImage(ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const
{
	PACK_BUFFER_STATE_MACHINE_HACK
	GetTexImage(format, type, pixel_store, BUFFER_OFFSET(buffer_offset));
}
