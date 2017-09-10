
#ifndef _GL_BUFFER_H_
#define _GL_BUFFER_H_

#include "GLSlayer/Buffer.h"
#include "GLResource.h"



class GLTextureBuffer;


class GLBuffer: public gls::IBuffer, public GLResource
{
public:
	IMPLEMENT_IRESOURCE

	static const int typeID = TYPE_ID_BUFFER;

	GLBuffer();

	bool Create(GLState* state, size_t size, const void* data, gls::uint flags);
	void Destroy();

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_BUFFER) ? this : GLResource::DynamicCast(type_id); }
	void BufferSubData(size_t offset, size_t size, const void* data);
	void GetBufferSubData(size_t offset, size_t size, void* data);
	void* Map(uint map_flags);
	void* MapRange(size_t offset, size_t length, gls::uint map_flags);
	void FlushMappedRange(size_t offset, size_t length);
	bool Unmap();
	void ClearData(gls::PixelFormat internal_format, gls::ImageFormat format, gls::DataType type, const void* data);
	void ClearSubData(gls::PixelFormat internal_format, gls::ImageFormat format, gls::DataType type, size_t offset, size_t size, const void* data);
	void InvalidateData();
	void InvalidateSubData(size_t offset, size_t size);
	size_t GetSize() const { return _size; }

private:
	GLBuffer(const GLBuffer&);
	GLBuffer& operator = (const GLBuffer&);

	size_t _size; // size of buffer in bytes
	GLState* _glState;

	friend class GLTextureBuffer;
};


#endif // _GL_BUFFER_H_
