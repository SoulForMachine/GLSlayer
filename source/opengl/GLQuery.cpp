
#include <cassert>
#include "GLQuery.h"

using namespace gls;


void GLQuery::Create()
{
	glGenQueries(1, &_id);
	OPENGL_ERROR_CHECK
	_type = QUERY_UNDEFINED;
	_target = 0;
}

void GLQuery::Destroy()
{
	if(_id)
	{
		glDeleteQueries(1, &_id);
		OPENGL_ERROR_CHECK
		_id = 0;
	}
}

void GLQuery::BeginQuery(QueryType type)
{
	_type = type;
	_target = GetGLEnum(type);
	glBeginQuery(_target, _id);
	OPENGL_ERROR_CHECK
}

void GLQuery::BeginQueryIndexed(QueryType type, int index)
{
	_type = type;
	_target = GetGLEnum(type);
	glBeginQueryIndexed(_target, index, _id);
	OPENGL_ERROR_CHECK
}

void GLQuery::EndQuery()
{
	glEndQuery(_target);
	OPENGL_ERROR_CHECK
}

void GLQuery::QueryCounter(QueryType type)
{
	_type = type;
	_target = GetGLEnum(type);
	glQueryCounter(_id, _target);
	OPENGL_ERROR_CHECK
}

bool GLQuery::ResultAvailable()
{
	GLint available;
	glGetQueryObjectiv(_id, GL_QUERY_RESULT_AVAILABLE, &available);
	OPENGL_ERROR_CHECK
	return (available != 0);
}

uint GLQuery::GetResultUI()
{
	GLuint result;
	glGetQueryObjectuiv(_id, GL_QUERY_RESULT, &result);
	OPENGL_ERROR_CHECK
	return (uint)result;
}

uint64 GLQuery::GetResultUI64()
{
	GLuint64 result;
	glGetQueryObjectui64v(_id, GL_QUERY_RESULT, &result);
	OPENGL_ERROR_CHECK
	return (uint64)result;
}

QueryType GLQuery::GetQueryType()
{
	return _type;
}
