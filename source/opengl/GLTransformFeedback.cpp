
#include <cassert>
#include "GLTransformFeedback.h"
#include "GLBuffer.h"

using namespace gls;


#define STATE_MACHINE_HACK \
	if(_id != _glState->transformFeedback) \
	{ \
		glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, _id); \
		OPENGL_ERROR_CHECK \
		_glState->transformFeedback = _id; \
	}



bool GLTransformFeedback::Create(GLState* gl_state)
{
	_glState = gl_state;

	glGenTransformFeedbacks(1, &_id);
	OPENGL_ERROR_CHECK

	if(!_id)
		return false;

	glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, _id);
	OPENGL_ERROR_CHECK

	if(glGetError() != GL_NO_ERROR)
		return false;

	_target = GL_TRANSFORM_FEEDBACK;
	_resType = RES_TRANSFORM_FEEDBACK;

	return true;
}

void GLTransformFeedback::Destroy()
{
	if(_id)
	{
		if(_id == _glState->transformFeedback)
		{
			glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0);
			_glState->transformFeedback = 0;
		}
		glDeleteTransformFeedbacks(1, &_id);
		OPENGL_ERROR_CHECK
		_id = 0;
	}
}

void GLTransformFeedback::BindBuffer(uint index, gls::IBuffer* buffer)
{
	STATE_MACHINE_HACK
	GLuint buf_id = dyn_cast_ptr<GLBuffer*>(buffer)->GetID();
	_glState->transfFeedbackBuf = buf_id;
	glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, index, buf_id);
	OPENGL_ERROR_CHECK
}

void GLTransformFeedback::BindBuffer(uint index, gls::IBuffer* buffer, size_t offset, size_t size)
{
	STATE_MACHINE_HACK
	GLuint buf_id = dyn_cast_ptr<GLBuffer*>(buffer)->GetID();
	_glState->transfFeedbackBuf = buf_id;
	glBindBufferRange(GL_TRANSFORM_FEEDBACK_BUFFER, index, buf_id, offset, size);
	OPENGL_ERROR_CHECK
}
