
#ifndef _GL_VERTEX_FORMAT_H_
#define _GL_VERTEX_FORMAT_H_

#include "GLSlayer/VertexFormat.h"
#include "GLCommon.h"


namespace gls::internals
{

class GLVertexFormat : public IVertexFormat
{
public:
	GLVertexFormat();
	~GLVertexFormat();

	GLVertexFormat(const GLVertexFormat&) = delete;
	GLVertexFormat& operator = (const GLVertexFormat&) = delete;

	VertexAttribDesc* _descriptors;
	int _count;
};

} // namespace gls::internals

#endif // _GL_VERTEX_FORMAT_H_
