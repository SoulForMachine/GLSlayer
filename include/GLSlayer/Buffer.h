
#ifndef _GLSLAYER_BUFFER_H_
#define _GLSLAYER_BUFFER_H_

#include "Resource.h"


namespace gls
{

	class IBuffer: public IResource
	{
	public:
		virtual ~IBuffer() {}

		virtual void BufferSubData(size_t offset, size_t size, const void* data) = 0;
		virtual void GetBufferSubData(size_t offset, size_t size, void* data) = 0;
		virtual void* Map(uint map_flags) = 0;
		virtual void* MapRange(size_t offset, size_t length, uint map_flags) = 0;
		virtual void FlushMappedRange(size_t offset, size_t length) = 0;
		virtual bool Unmap() = 0;
		virtual void ClearData(PixelFormat internal_format, ImageFormat format, DataType type, const void* data) = 0;
		virtual void ClearSubData(PixelFormat internal_format, ImageFormat format, DataType type, size_t offset, size_t size, const void* data) = 0;
		virtual void InvalidateData() = 0;
		virtual void InvalidateSubData(size_t offset, size_t size) = 0;
	};

}

#endif // _GLSLAYER_BUFFER_H_
