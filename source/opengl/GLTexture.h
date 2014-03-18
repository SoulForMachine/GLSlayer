
#ifndef _GL_TEXTURE_H_
#define _GL_TEXTURE_H_

#include "GLSlayer/Texture.h"
#include "GLResource.h"




bool IsCompressedFormat(gls::PixelFormat format);


#define IMPLEMENT_ITEXTURE \
	gls::TextureType GetTextureType() { return GLTexture::GetTextureType(); } \
	void GenerateMipmap() { GLTexture::GenerateMipmap(); } \
	gls::PixelFormat GetFormat() const { return GLTexture::GetFormat(); } \
	void SetBaseLevel(int base_level) { GLTexture::SetBaseLevel(base_level); } \
	int GetBaseLevel() const { return GLTexture::GetBaseLevel(); } \
	void SetMaxLevel(int max_level) { GLTexture::SetMaxLevel(max_level); } \
	int GetMaxLevel() const { return GLTexture::GetMaxLevel(); } \
	bool IsCompressed() const { return GLTexture::IsCompressed(); } \
	int GetCompressedSize(int level) const { return GLTexture::GetCompressedSize(level); } \
	void ComponentSwizzle(gls::TexSwizzleDest dest, gls::TexSwizzleSource source) { GLTexture::ComponentSwizzle(dest, source); } \
	void ComponentSwizzle(gls::TexSwizzleSource source_red, gls::TexSwizzleSource source_green, gls::TexSwizzleSource source_blue, gls::TexSwizzleSource source_alpha) \
		{ GLTexture::ComponentSwizzle(source_red, source_green, source_blue, source_alpha); } \
	void DepthStencilMode(gls::DepthStencilTexMode mode) { GLTexture::DepthStencilMode(mode); }



class GLTexture : public GLResource
{
public:
	IMPLEMENT_IRESOURCE

	static const int typeID = TYPE_ID_TEXTURE;

	GLTexture();
	virtual ~GLTexture() = 0;

	void Destroy();

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TEXTURE) ? this : GLResource::DynamicCast(type_id); }
	gls::TextureType GetTextureType();
	void GenerateMipmap();
	gls::PixelFormat GetFormat() const		{ return _format; }
	void SetBaseLevel(int base_level);
	int GetBaseLevel() const		{ return _baseLevel; }
	void SetMaxLevel(int max_level);
	int GetMaxLevel() const			{ return _maxLevel; }
	bool IsCompressed() const		{ return IsCompressedFormat(_format); }
	int GetCompressedSize(int level) const;
	void ComponentSwizzle(gls::TexSwizzleDest dest, gls::TexSwizzleSource source);
	void ComponentSwizzle(gls::TexSwizzleSource source_red, gls::TexSwizzleSource source_green, gls::TexSwizzleSource source_blue, gls::TexSwizzleSource source_alpha);
	void DepthStencilMode(gls::DepthStencilTexMode mode);

protected:
	GLState* _glState;
	gls::PixelFormat _format;	// that's internal format
	int _baseLevel;
	int _maxLevel;
	gls::TextureType _textureType;

private:
	GLTexture(const GLTexture&);
	GLTexture& operator = (const GLTexture&);
};

inline
GLTexture::~GLTexture()
{
}

class GLTexture1D : public gls::ITexture1D, public GLTexture
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ITEXTURE

	static const int typeID = TYPE_ID_TEXTURE_1D;

	bool CreateImmutable(GLState* gl_state, size_t levels, gls::PixelFormat internal_format, int width);
	bool CreateView(GLState* gl_state, GLuint orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer);

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TEXTURE_1D) ? this : GLTexture::DynamicCast(type_id); }
	void TexSubImage(int level, int xoffset, int width, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels);
	void TexSubImage(int level, int xoffset, int width, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset);
	void CompressedTexSubImage(int level, int xoffset, int width, gls::ImageFormat format, size_t size, void* pixels);
	void CopyTexImage(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, int level, gls::PixelFormat internal_format, int x, int y, int width);
	void CopyTexSubImage(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, int level, int xoffset, int x, int y, int width);
	void InvalidateTexImage(int level);
	void InvalidateTexSubImage(int level, int xoffset, int width);
	void GetTexImage(int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels) const;
	void GetTexImage(int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset) const;
	void GetCompressedTexImage(int level, void* pixels) const;
	void GetCompressedTexImage(int level, gls::IBuffer* buffer, size_t buffer_offset) const;

	int GetWidth() const
		{ return _width; }

private:
	bool Create(GLState* gl_state);

	int _width;
};

class GLTexture2D : public gls::ITexture2D, public GLTexture
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ITEXTURE

	static const int typeID = TYPE_ID_TEXTURE_2D;

	bool CreateImmutable(GLState* gl_state, size_t levels, gls::PixelFormat internal_format, int width, int height);
	bool CreateView(GLState* gl_state, GLuint orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer);

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TEXTURE_2D) ? this : GLTexture::DynamicCast(type_id); }
	void TexSubImage(int level, int xoffset, int yoffset, int width, int height, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels);
	void TexSubImage(int level, int xoffset, int yoffset, int width, int height, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset);
	void CompressedTexSubImage(int level, int xoffset, int yoffset, int width, int height, gls::ImageFormat format, size_t size, void* pixels);
	void CopyTexImage(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, int level, gls::PixelFormat internal_format, int x, int y, int width, int height);
	void CopyTexSubImage(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int x, int y, int width, int height);
	void InvalidateTexImage(int level);
	void InvalidateTexSubImage(int level, int xoffset, int yoffset, int width, int height);
	void GetTexImage(int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels) const;
	void GetTexImage(int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset) const;
	void GetCompressedTexImage(int level, void* pixels) const;
	void GetCompressedTexImage(int level, gls::IBuffer* buffer, size_t buffer_offset) const;

	int GetWidth() const
		{ return _width; }
	int GetHeight() const
		{ return _height; }

private:
	bool Create(GLState* gl_state);

	int _width;
	int _height;
};

class GLTexture2DMultisample : public gls::ITexture2DMultisample, public GLTexture
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ITEXTURE

	static const int typeID = TYPE_ID_TEXTURE_2D_MULTISAMPLE;

	bool CreateImmutable(GLState* gl_state, int samples, gls::PixelFormat internal_format, int width, int height, bool fixed_sample_locations);
	bool CreateView(GLState* gl_state, GLuint orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels);

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TEXTURE_2D_MULTISAMPLE) ? this : GLTexture::DynamicCast(type_id); }
	void InvalidateTexImage();
	void InvalidateTexSubImage(int xoffset, int yoffset, int width, int height);

	int GetWidth() const
		{ return _width; }
	int GetHeight() const
		{ return _height; }

private:
	bool Create(GLState* gl_state);

	int _width;
	int _height;
};

class GLTexture3D : public gls::ITexture3D, public GLTexture
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ITEXTURE

	static const int typeID = TYPE_ID_TEXTURE_3D;

	bool CreateImmutable(GLState* gl_state, size_t levels, gls::PixelFormat internal_format, int width, int height, int depth);
	bool CreateView(GLState* gl_state, GLuint orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels);

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TEXTURE_3D) ? this : GLTexture::DynamicCast(type_id); }
	void TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels);
	void TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset);
	void CompressedTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, gls::ImageFormat format, size_t size, void* pixels);
	void CopyTexSubImage(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height);
	void InvalidateTexImage(int level);
	void InvalidateTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth);
	void GetTexImage(int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels) const;
	void GetTexImage(int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset) const;
	void GetCompressedTexImage(int level, void* pixels) const;
	void GetCompressedTexImage(int level, gls::IBuffer* buffer, size_t buffer_offset) const;

	int GetWidth() const
		{ return _width; }
	int GetHeight() const
		{ return _height; }
	int GetDepth() const
		{ return _depth; }

private:
	bool Create(GLState* gl_state);

	int _width;
	int _height;
	int _depth;
};

class GLTextureCube : public gls::ITextureCube, public GLTexture
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ITEXTURE

	static const int typeID = TYPE_ID_TEXTURE_CUBE;

	bool CreateImmutable(GLState* gl_state, size_t levels, gls::PixelFormat internal_format, int width);
	bool CreateView(GLState* gl_state, GLuint orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TEXTURE_CUBE) ? this : GLTexture::DynamicCast(type_id); }
	void TexSubImage(gls::CubeFace face, int level, int xoffset, int yoffset, int width, int height, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels);
	void TexSubImage(gls::CubeFace face, int level, int xoffset, int yoffset, int width, int height, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset);
	void CompressedTexSubImage(gls::CubeFace face, int level, int xoffset, int yoffset, int width, int height, gls::ImageFormat format, size_t size, void* pixels);
	void CopyTexImage(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, gls::CubeFace face, int level, gls::PixelFormat internal_format, int x, int y, int width);
	void CopyTexSubImage(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, gls::CubeFace face, int level, int xoffset, int yoffset, int x, int y, int width, int height);
	void InvalidateTexImage(int level);
	void InvalidateTexSubImage(gls::CubeFace face, int level, int xoffset, int yoffset, int width, int height);
	void GetTexImage(gls::CubeFace face, int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels) const;
	void GetTexImage(gls::CubeFace face, int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset) const;
	void GetCompressedTexImage(gls::CubeFace face, int level, void* pixels) const;
	void GetCompressedTexImage(gls::CubeFace face, int level, gls::IBuffer* buffer, size_t buffer_offset) const;

	int GetWidth() const
		{ return _width; }

private:
	bool Create(GLState* gl_state);

	int _width;
};

class GLTexture1DArray : public gls::ITexture1DArray, public GLTexture
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ITEXTURE

	static const int typeID = TYPE_ID_TEXTURE_1D_ARRAY;

	bool CreateImmutable(GLState* gl_state, size_t levels, gls::PixelFormat internal_format, int width, int height);
	bool CreateView(GLState* gl_state, GLuint orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TEXTURE_1D_ARRAY) ? this : GLTexture::DynamicCast(type_id); }
	void TexSubImage(int level, int xoffset, int yoffset, int width, int height, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels);
	void TexSubImage(int level, int xoffset, int yoffset, int width, int height, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset);
	void CompressedTexSubImage(int level, int xoffset, int yoffset, int width, int height, gls::ImageFormat format, size_t size, void* pixels);
	void CopyTexImage(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, int level, gls::PixelFormat internal_format, int x, int y, int width, int height);
	void CopyTexSubImage(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int x, int y, int width, int height);
	void InvalidateTexImage(int level);
	void InvalidateTexSubImage(int level, int xoffset, int yoffset, int width, int height);
	void GetTexImage(int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels) const;
	void GetTexImage(int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset) const;
	void GetCompressedTexImage(int level, void* pixels) const;
	void GetCompressedTexImage(int level, gls::IBuffer* buffer, size_t buffer_offset) const;

	int GetWidth() const
		{ return _width; }
	int GetHeight() const
		{ return _height; }

private:
	bool Create(GLState* gl_state);

	int _width;
	int _height;
};

class GLTexture2DArray : public gls::ITexture2DArray, public GLTexture
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ITEXTURE

	static const int typeID = TYPE_ID_TEXTURE_2D_ARRAY;

	bool CreateImmutable(GLState* gl_state, size_t levels, gls::PixelFormat internal_format, int width, int height, int depth);
	bool CreateView(GLState* gl_state, GLuint orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TEXTURE_2D_ARRAY) ? this : GLTexture::DynamicCast(type_id); }
	void TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels);
	void TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset);
	void CompressedTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, gls::ImageFormat format, size_t size, void* pixels);
	void CopyTexSubImage(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height);
	void InvalidateTexImage(int level);
	void InvalidateTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth);
	void GetTexImage(int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels) const;
	void GetTexImage(int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset) const;
	void GetCompressedTexImage(int level, void* pixels) const;
	void GetCompressedTexImage(int level, gls::IBuffer* buffer, size_t buffer_offset) const;

	int GetWidth() const
		{ return _width; }
	int GetHeight() const
		{ return _height; }
	int GetDepth() const
		{ return _depth; }

private:
	bool Create(GLState* gl_state);

	int _width;
	int _height;
	int _depth;
};

class GLTexture2DMultisampleArray : public gls::ITexture2DMultisampleArray, public GLTexture
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ITEXTURE

	static const int typeID = TYPE_ID_TEXTURE_2D_MULTISAMPLE_ARRAY;

	bool CreateImmutable(GLState* gl_state, int samples, gls::PixelFormat internal_format, int width, int height, int depth, bool fixed_sample_locations);
	bool CreateView(GLState* gl_state, GLuint orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TEXTURE_2D_MULTISAMPLE_ARRAY) ? this : GLTexture::DynamicCast(type_id); }
	void InvalidateTexImage();
	void InvalidateTexSubImage(int xoffset, int yoffset, int zoffset, int width, int height, int depth);

	int GetWidth() const
		{ return _width; }
	int GetHeight() const
		{ return _height; }
	int GetDepth() const
		{ return _depth; }

private:
	bool Create(GLState* gl_state);

	int _width;
	int _height;
	int _depth;
};

class GLTextureCubeArray : public gls::ITextureCubeArray, public GLTexture
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ITEXTURE

	static const int typeID = TYPE_ID_TEXTURE_CUBE_ARRAY;

	bool CreateImmutable(GLState* gl_state, size_t levels, gls::PixelFormat internal_format, int width, int depth);
	bool CreateView(GLState* gl_state, GLuint orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels, gls::uint min_layer, gls::uint num_layers);

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TEXTURE_CUBE_ARRAY) ? this : GLTexture::DynamicCast(type_id); }
	void TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels);
	void TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset);
	void CompressedTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, gls::ImageFormat format, size_t size, void* pixels);
	void CopyTexSubImage(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height);
	void InvalidateTexImage(int level);
	void InvalidateTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth);
	void GetTexImage(int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels) const;
	void GetTexImage(int level, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset) const;

	int GetWidth() const
		{ return _width; }
	int GetDepth() const
		{ return _depth; }

private:
	bool Create(GLState* gl_state);

	int _width;
	int _depth;
};

class GLTextureBuffer : public gls::ITextureBuffer, public GLTexture
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ITEXTURE

	static const int typeID = TYPE_ID_TEXTURE_BUFFER;

	bool Create(GLState* gl_state);

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TEXTURE_BUFFER) ? this : GLTexture::DynamicCast(type_id); }
	void TexBuffer(gls::PixelFormat internal_format, gls::IBuffer* buffer);
	void TexBufferRange(gls::PixelFormat internal_format, gls::IBuffer* buffer, size_t offset, size_t size);
	void InvalidateTexImage();
	void InvalidateTexSubImage(int xoffset, int yoffset, int width, int height);

	size_t GetSize() const
		{ return _size; }

private:
	// these are not applicable to buffer textures
	using GLTexture::GenerateMipmap;
	using GLTexture::IsCompressed;

	size_t _size;
};

class GLTextureRectangle : public gls::ITextureRectangle, public GLTexture
{
public:
	IMPLEMENT_IRESOURCE
	IMPLEMENT_ITEXTURE

	static const int typeID = TYPE_ID_TEXTURE_RECTANGLE;

	bool CreateImmutable(GLState* gl_state, size_t levels, gls::PixelFormat internal_format, int width, int height);
	bool CreateView(GLState* gl_state, GLuint orig_tex, gls::PixelFormat internal_format, gls::uint min_level, gls::uint num_levels);

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TEXTURE_RECTANGLE) ? this : GLTexture::DynamicCast(type_id); }
	void TexSubImage(int xoffset, int yoffset, int width, int height, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels);
	void TexSubImage(int xoffset, int yoffset, int width, int height, gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset);
	void CopyTexImage(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, gls::PixelFormat internal_format, int x, int y, int width, int height);
	void CopyTexSubImage(gls::IFramebuffer* source_fbuf, gls::ColorBuffer source_color_buf, int xoffset, int yoffset, int x, int y, int width, int height);
	void InvalidateTexImage();
	void InvalidateTexSubImage(int xoffset, int yoffset, int width, int height);
	void GetTexImage(gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, void* pixels) const;
	void GetTexImage(gls::ImageFormat format, gls::DataType type, const gls::PixelStore* pixel_store, gls::IBuffer* buffer, size_t buffer_offset) const;

	int GetWidth() const
		{ return _width; }
	int GetHeight() const
		{ return _height; }

private:
	// these are not applicable to rectangle textures
	using GLTexture::GenerateMipmap;
	using GLTexture::IsCompressed;

	bool Create(GLState* gl_state);

	int _width;
	int _height;
};


#endif //_GL_TEXTURE_H_
