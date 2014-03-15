
#ifndef _GL_RESOURCE_H_
#define _GL_RESOURCE_H_

#include "GLSlayer/Resource.h"
#include "GLCommon.h"


#define IMPLEMENT_IRESOURCE \
	gls::ResourceType GetType() const {return GLResource::GetType(); }



class GLResource
{
public:
	static const int typeID = TYPE_ID_RESOURCE;

	GLResource()
		{ _id = 0; }
	virtual ~GLResource() = 0;

	void* DynamicCast(int type_id)			{ return (type_id == TYPE_ID_RESOURCE) ? this : 0; }
	gls::ResourceType GetType() const	{ return _resType; }
	GLuint GetID() const					{ return _id; }
	GLenum GetTarget() const				{ return _target; }

protected:
	GLuint _id;
	GLenum _target;
	gls::ResourceType _resType;

	GLResource(const GLResource&);
	GLResource& operator = (const GLResource&);
};


inline
GLResource::~GLResource()
{
}

#endif // _GL_RESOURCE_H_
