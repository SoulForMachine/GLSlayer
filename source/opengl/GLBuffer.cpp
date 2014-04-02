
#include <cassert>
#include "GLBuffer.h"

using namespace gls;


#define STATE_MACHINE_HACK \
	if(_id != *_currentId) \
	{ \
		glBindBuffer(_target, _id); \
		*_currentId = _id; \
	}



GLBuffer::GLBuffer()
{
	_size = 0;
	_mapped = false;
}

bool GLBuffer::Create(GLState* gl_state, BufferType type, size_t size, const void* data, BufferUsage usage)
{
	if(_id)
		return false;

	_glState = gl_state;

	switch(type)
	{
	case VERTEX_BUFFER:
		_currentId = &_glState->vertexBuf;
		break;
	case INDEX_BUFFER:
		_currentId = &_glState->indexBuf;
		break;
	case PIXEL_PACK_BUFFER:
		_currentId = &_glState->pixelPackBuf;
		break;
	case PIXEL_UNPACK_BUFFER:
		_currentId = &_glState->pixelUnpackBuf;
		break;
	case TEXTURE_BUFFER:
		_currentId = &_glState->textureBuf;
		break;
	case UNIFORM_BUFFER:
		_currentId = &_glState->uniformBuf;
		break;
	case TRANSFORM_FEEDBACK_BUFFER:
		_currentId = &_glState->transfFeedbackBuf;
		break;
	case DRAW_INDIRECT_BUFFER:
		_currentId = &_glState->drawIndirectBuf;
		break;
	case DISPATCH_INDIRECT_BUFFER:
		_currentId = &_glState->dispatchIndirectBuf;
		break;
	case ATOMIC_COUNTER_BUFFER:
		_currentId = &_glState->atomicCounterBuf;
		break;
	case SHADER_STORAGE_BUFFER:
		_currentId = &_glState->shaderStorageBuf;
		break;
	default:
		assert(false);
	}

	_resType = RES_BUFFER;
	_target = GetGLEnum(type);
	_bufferType = type;
	_size = size;
	_usage = usage;

	glGenBuffers(1, &_id);

	if(!_id)
		return false;

	glBindBuffer(_target, _id);
	*_currentId = _id;

	if(size > 0)
	{
		glBufferData(_target, size, data, GetGLEnum(usage));

		if(glGetError() != GL_NO_ERROR)
		{
			Destroy();
			return false;
		}
	}

	return true;
}

void GLBuffer::Destroy()
{
	if(_id)
	{
		if(_id == *_currentId)
		{
			glBindBuffer(_target, 0);
			*_currentId = 0;
		}
		glDeleteBuffers(1, &_id);
		_id = 0;
		_size = 0;
		_mapped = false;
	}
}

BufferType GLBuffer::GetBufferType()
{
	return _bufferType;
}

void GLBuffer::BufferSubData(size_t offset, size_t size, const void* data)
{
	assert(_id);
	assert(!_mapped);
	STATE_MACHINE_HACK
	glBufferSubData(_target, offset, size, data);
}

void GLBuffer::GetBufferSubData(size_t offset, size_t size, void* data)
{
	assert(_id);
	assert(!_mapped);
	STATE_MACHINE_HACK
	glGetBufferSubData(_target, offset, size, data);
}

/*
	If discard is true, invalidates buffer data and allows driver to perform optimization.
	If you want to respecify the size and usage, call BufferData() with 0 for data before
	calling Map().
*/
void* GLBuffer::Map(BufferAccess access, bool discard)
{
	assert(_id);
	assert(!_mapped);
	STATE_MACHINE_HACK
	if(discard)
	{
		glBufferData(_target, _size, 0, GetGLEnum(_usage));	// or glInvalidateBufferData
	}
	void* ptr = glMapBuffer(_target, GetGLEnum(access));
	_mapped = true;
	return ptr;
}

/*
	map_flags is a combination of BufferMapFlags
*/
void* GLBuffer::MapRange(size_t offset, size_t length, uint map_flags)
{
	assert(_id);
	assert(!_mapped);
	STATE_MACHINE_HACK

	GLbitfield bits = 0;
	if(map_flags & MAP_READ_BIT)
		bits |= GL_MAP_READ_BIT;
	if(map_flags & MAP_WRITE_BIT)
		bits |= GL_MAP_WRITE_BIT;
	if(map_flags & MAP_INVALIDATE_RANGE_BIT)
		bits |= GL_MAP_INVALIDATE_RANGE_BIT;
	if(map_flags & MAP_INVALIDATE_BUFFER_BIT)
		bits |= GL_MAP_INVALIDATE_BUFFER_BIT;
	if(map_flags & MAP_FLUSH_EXPLICIT_BIT)
		bits |= GL_MAP_FLUSH_EXPLICIT_BIT;
	if(map_flags & MAP_UNSYNCHRONIZED_BIT)
		bits |= GL_MAP_UNSYNCHRONIZED_BIT;

	void* ptr = glMapBufferRange(_target, offset, length, bits);
	_mapped = true;
	return ptr;
}

void GLBuffer::FlushMappedRange(size_t offset, size_t length)
{
	assert(_id);
	assert(_mapped);
	STATE_MACHINE_HACK
	glFlushMappedBufferRange(_target, offset, length);
}

bool GLBuffer::Unmap()
{
	assert(_id);
	assert(_mapped);
	STATE_MACHINE_HACK
	bool result = (glUnmapBuffer(_target) == GL_TRUE);
	_mapped = false;
	return result;
}

void GLBuffer::ClearData(PixelFormat internal_format, ImageFormat format, DataType type, const void* data)
{
	assert(_id);
	assert(!_mapped);
	STATE_MACHINE_HACK
	glClearBufferData(_target, GetGLEnum(internal_format), GetGLEnum(format), GetGLEnum(type), data);
}

void GLBuffer::ClearSubData(PixelFormat internal_format, ImageFormat format, DataType type, size_t offset, size_t size, const void* data)
{
	assert(_id);
	assert(!_mapped);
	STATE_MACHINE_HACK
	glClearBufferSubData(_target, GetGLEnum(internal_format), offset, size, GetGLEnum(format), GetGLEnum(type), data);
}

void GLBuffer::InvalidateData()
{
	assert(_id);
	glInvalidateBufferData(_id);
}

void GLBuffer::InvalidateSubData(size_t offset, size_t size)
{
	assert(_id);
	glInvalidateBufferSubData(_id, offset, size);
}
