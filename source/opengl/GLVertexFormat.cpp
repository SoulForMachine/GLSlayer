
#include "GLVertexFormat.h"

namespace gls::internals
{

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

} // namespace gls::internals
