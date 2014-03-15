
#ifndef _GL_TRANSFORM_FEEDBACK_H_
#define _GL_TRANSFORM_FEEDBACK_H_

#include "GLSlayer/TransformFeedback.h"
#include "GLResource.h"


namespace gls
{
	class IBuffer;
}


class GLTransformFeedback : public gls::ITransformFeedback, public GLResource
{
public:
	IMPLEMENT_IRESOURCE

	static const int typeID = TYPE_ID_TRANSFORM_FEEDBACK;

	GLTransformFeedback() {}

	bool Create(GLState* gl_state);
	void Destroy();

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_TRANSFORM_FEEDBACK) ? this : GLResource::DynamicCast(type_id); }
	void BindBuffer(gls::uint index, gls::IBuffer* buffer);
	void BindBuffer(gls::uint index, gls::IBuffer* buffer, size_t offset, size_t size);

private:
	GLTransformFeedback(const GLTransformFeedback&);
	GLTransformFeedback& operator = (const GLTransformFeedback&);

	GLState* _glState;
};


#endif // _GL_TRANSFORM_FEEDBACK_H_
