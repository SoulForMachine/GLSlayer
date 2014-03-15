
#ifndef _GL_VERTEX_FORMAT_H_
#define _GL_VERTEX_FORMAT_H_

#include "GLSlayer/VertexFormat.h"
#include "GLCommon.h"



class GLVertexFormat : public gls::IVertexFormat
{
public:
	GLVertexFormat();
	~GLVertexFormat();

	gls::VertexAttribDesc* _descriptors;
	int _count;
};


#endif // _GL_VERTEX_FORMAT_H_
