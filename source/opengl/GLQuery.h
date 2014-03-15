
#ifndef _GL_QUERY_H_
#define _GL_QUERY_H_

#include "GLSlayer/Query.h"
#include "GLCommon.h"


class GLQuery: public gls::IQuery
{
public:
	GLQuery() {}
	~GLQuery() {}

	void Create();
	void Destroy();

	void BeginQuery(gls::QueryType type);
	void BeginQueryIndexed(gls::QueryType type, int index);
	void EndQuery();
	void QueryCounter(gls::QueryType type);
	bool ResultAvailable();
	gls::uint GetResultUI();
	gls::uint64 GetResultUI64();
	gls::QueryType GetQueryType();

	GLenum GetTarget() const	{ return _target; }
	GLuint GetID() const		{ return _id; }

private:
	GLQuery(const GLQuery&);
	GLQuery& operator = (const GLQuery&);

	gls::QueryType _type;
	GLenum _target;
	GLuint _id;
};


#endif // _GL_QUERY_H_
