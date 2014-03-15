
#include "GLVertexFormat.h"


GLVertexFormat::GLVertexFormat()
{
	_descriptors = 0;
	_count = 0;
}

GLVertexFormat::~GLVertexFormat()
{
	delete[] _descriptors;
	_count = 0;
}
