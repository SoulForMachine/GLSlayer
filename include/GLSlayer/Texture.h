
#ifndef _GLSLAYER_TEXTURE_H_
#define _GLSLAYER_TEXTURE_H_

#include "Resource.h"


namespace gls
{

	class IBuffer;
	class ISamplerState;
	class IFramebuffer;


	class ITexture: public IResource
	{
	public:
		virtual ~ITexture() {}

		virtual TextureType GetTextureType() = 0;
		virtual void GenerateMipmap() = 0;
		virtual PixelFormat GetFormat() const = 0;
		virtual void SetBaseLevel(int base_level) = 0;
		virtual int GetBaseLevel() const = 0;
		virtual void SetMaxLevel(int max_level) = 0;
		virtual int GetMaxLevel() const = 0;
		virtual bool IsCompressed() const = 0;
		virtual int GetCompressedSize(int level) const = 0;
		virtual void ComponentSwizzle(TexSwizzleDest dest, TexSwizzleSource source) = 0;
		virtual void ComponentSwizzle(TexSwizzleSource source_red, TexSwizzleSource source_green, TexSwizzleSource source_blue, TexSwizzleSource source_alpha) = 0;
		virtual void DepthStencilMode(DepthStencilTexMode mode) = 0;
	};

	class ITexture1D: public ITexture
	{
	public:
		virtual void TexImage(int level, PixelFormat internal_format, int width, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexImage(int level, PixelFormat internal_format, int width, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexImage(int level, PixelFormat internal_format, int width, size_t size, void* pixels) = 0;
		virtual void TexSubImage(int level, int xoffset, int width, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexSubImage(int level, int xoffset, int width, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexSubImage(int level, int xoffset, int width, ImageFormat format, size_t size, void* pixels) = 0;
		virtual void CopyTexImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, PixelFormat internal_format, int x, int y, int width) = 0;
		virtual void CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, int xoffset, int x, int y, int width) = 0;
		virtual void InvalidateTexImage(int level) = 0;
		virtual void InvalidateTexSubImage(int level, int xoffset, int width) = 0;
		virtual void GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const = 0;
		virtual void GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const = 0;
		virtual void GetCompressedTexImage(int level, void* pixels) const = 0;
		virtual void GetCompressedTexImage(int level, IBuffer* buffer, size_t buffer_offset) const = 0;

		virtual int GetWidth() const = 0;
	};

	class ITexture2D: public ITexture
	{
	public:
		virtual void TexImage(int level, PixelFormat internal_format, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexImage(int level, PixelFormat internal_format, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexImage(int level, PixelFormat internal_format, int width, int height, size_t size, void* pixels) = 0;
		virtual void TexSubImage(int level, int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexSubImage(int level, int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexSubImage(int level, int xoffset, int yoffset, int width, int height, ImageFormat format, size_t size, void* pixels) = 0;
		virtual void CopyTexImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, PixelFormat internal_format, int x, int y, int width, int height) = 0;
		virtual void CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int x, int y, int width, int height) = 0;
		virtual void InvalidateTexImage(int level) = 0;
		virtual void InvalidateTexSubImage(int level, int xoffset, int yoffset, int width, int height) = 0;
		virtual void GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const = 0;
		virtual void GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const = 0;
		virtual void GetCompressedTexImage(int level, void* pixels) const = 0;
		virtual void GetCompressedTexImage(int level, IBuffer* buffer, size_t buffer_offset) const = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
	};

	class ITexture2DMultisample : public ITexture
	{
	public:
		virtual void TexImage(int samples, PixelFormat internal_format, int width, int height, bool fixed_sample_locations) = 0;
		virtual void InvalidateTexImage() = 0;
		virtual void InvalidateTexSubImage(int xoffset, int yoffset, int width, int height) = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
	};

	class ITexture3D: public ITexture
	{
	public:
		virtual void TexImage(int level, PixelFormat internal_format, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexImage(int level, PixelFormat internal_format, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexImage(int level, PixelFormat internal_format, int width, int height, int depth, size_t size, void* pixels) = 0;
		virtual void TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, size_t size, void* pixels) = 0;
		virtual void CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height) = 0;
		virtual void InvalidateTexImage(int level) = 0;
		virtual void InvalidateTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth) = 0;
		virtual void GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const = 0;
		virtual void GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const = 0;
		virtual void GetCompressedTexImage(int level, void* pixels) const = 0;
		virtual void GetCompressedTexImage(int level, IBuffer* buffer, size_t buffer_offset) const = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual int GetDepth() const = 0;
	};

	class ITextureCube: public ITexture
	{
	public:
		virtual void TexImage(int level, PixelFormat internal_format, int width, ImageFormat format, DataType type, const PixelStore* const* pixel_store, void** pixels) = 0;
		virtual void TexImage(CubeFace face, int level, PixelFormat internal_format, int width, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexImage(CubeFace face, int level, PixelFormat internal_format, int width, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexImage(int level, PixelFormat internal_format, int width, size_t size, void** pixels) = 0;
		virtual void CompressedTexImage(CubeFace face, int level, PixelFormat internal_format, int width, size_t size, void* pixels) = 0;
		virtual void TexSubImage(CubeFace face, int level, int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexSubImage(CubeFace face, int level, int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexSubImage(CubeFace face, int level, int xoffset, int yoffset, int width, int height, ImageFormat format, size_t size, void* pixels) = 0;
		virtual void CopyTexImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, CubeFace face, int level, PixelFormat internal_format, int x, int y, int width) = 0;
		virtual void CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, CubeFace face, int level, int xoffset, int yoffset, int x, int y, int width, int height) = 0;
		virtual void InvalidateTexImage(int level) = 0;
		virtual void InvalidateTexSubImage(CubeFace face, int level, int xoffset, int yoffset, int width, int height) = 0;
		virtual void GetTexImage(CubeFace face, int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const = 0;
		virtual void GetTexImage(CubeFace face, int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const = 0;
		virtual void GetCompressedTexImage(CubeFace face, int level, void* pixels) const = 0;
		virtual void GetCompressedTexImage(CubeFace face, int level, IBuffer* buffer, size_t buffer_offset) const = 0;

		virtual int GetWidth() const = 0;
	};

	class ITexture1DArray: public ITexture
	{
	public:
		virtual void TexImage(int level, PixelFormat internal_format, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexImage(int level, PixelFormat internal_format, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexImage(int level, PixelFormat internal_format, int width, int height, size_t size, void* pixels) = 0;
		virtual void TexSubImage(int level, int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexSubImage(int level, int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexSubImage(int level, int xoffset, int yoffset, int width, int height, ImageFormat format, size_t size, void* pixels) = 0;
		virtual void CopyTexImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, PixelFormat internal_format, int x, int y, int width, int height) = 0;
		virtual void CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int x, int y, int width, int height) = 0;
		virtual void InvalidateTexImage(int level) = 0;
		virtual void InvalidateTexSubImage(int level, int xoffset, int yoffset, int width, int height) = 0;
		virtual void GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const = 0;
		virtual void GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const = 0;
		virtual void GetCompressedTexImage(int level, void* pixels) const = 0;
		virtual void GetCompressedTexImage(int level, IBuffer* buffer, size_t buffer_offset) const = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
	};

	class ITexture2DArray: public ITexture
	{
	public:
		virtual void TexImage(int level, PixelFormat internal_format, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexImage(int level, PixelFormat internal_format, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexImage(int level, PixelFormat internal_format, int width, int height, int depth, size_t size, void* pixels) = 0;
		virtual void TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, size_t size, void* pixels) = 0;
		virtual void CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height) = 0;
		virtual void InvalidateTexImage(int level) = 0;
		virtual void InvalidateTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth) = 0;
		virtual void GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const = 0;
		virtual void GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const = 0;
		virtual void GetCompressedTexImage(int level, void* pixels) const = 0;
		virtual void GetCompressedTexImage(int level, IBuffer* buffer, size_t buffer_offset) const = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual int GetDepth() const = 0;
	};

	class ITexture2DMultisampleArray : public ITexture
	{
	public:
		virtual void TexImage(int samples, PixelFormat internal_format, int width, int height, int depth, bool fixed_sample_locations) = 0;
		virtual void InvalidateTexImage() = 0;
		virtual void InvalidateTexSubImage(int xoffset, int yoffset, int zoffset, int width, int height, int depth) = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
	};

	class ITextureCubeArray : public ITexture
	{
	public:
		virtual void TexImage(int level, PixelFormat internal_format, int width, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexImage(int level, PixelFormat internal_format, int width, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexImage(int level, PixelFormat internal_format, int width, int depth, size_t size, void* pixels) = 0;
		virtual void TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CompressedTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, ImageFormat format, size_t size, void* pixels) = 0;
		virtual void CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height) = 0;
		virtual void InvalidateTexImage(int level) = 0;
		virtual void InvalidateTexSubImage(int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth) = 0;
		virtual void GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const = 0;
		virtual void GetTexImage(int level, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const = 0;

		virtual int GetWidth() const = 0;
		virtual int GetDepth() const = 0;
	};

	class ITextureBuffer: public ITexture
	{
	public:
		virtual void TexBuffer(PixelFormat internal_format, IBuffer* buffer) = 0;
		virtual void TexBufferRange(PixelFormat internal_format, IBuffer* buffer, size_t offset, size_t size) = 0;
		virtual void InvalidateTexImage() = 0;
		virtual void InvalidateTexSubImage(int xoffset, int yoffset, int width, int height) = 0;

		virtual size_t GetSize() const = 0;

	private:
		// these are not applicable to buffer textures
		using ITexture::GenerateMipmap;
		using ITexture::IsCompressed;
	};

	class ITextureRectangle: public ITexture
	{
	public:
		virtual void TexImage(PixelFormat internal_format, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexImage(PixelFormat internal_format, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void TexSubImage(int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) = 0;
		virtual void TexSubImage(int xoffset, int yoffset, int width, int height, ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) = 0;
		virtual void CopyTexImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, PixelFormat internal_format, int x, int y, int width, int height) = 0;
		virtual void CopyTexSubImage(IFramebuffer* source_fbuf, ColorBuffer source_color_buf, int xoffset, int yoffset, int x, int y, int width, int height) = 0;
		virtual void InvalidateTexImage() = 0;
		virtual void InvalidateTexSubImage(int xoffset, int yoffset, int width, int height) = 0;
		virtual void GetTexImage(ImageFormat format, DataType type, const PixelStore* pixel_store, void* pixels) const = 0;
		virtual void GetTexImage(ImageFormat format, DataType type, const PixelStore* pixel_store, IBuffer* buffer, size_t buffer_offset) const = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;

	private:
		// these are not applicable to buffer textures
		using ITexture::GenerateMipmap;
		using ITexture::IsCompressed;
	};

}

#endif //_GLSLAYER_TEXTURE_H_
