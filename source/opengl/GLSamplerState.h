
#ifndef _GL_SAMPLER_STATE_H_
#define _GL_SAMPLER_STATE_H_

#include "GLSlayer/SamplerState.h"
#include "GLResource.h"


class GLSamplerState : public gls::ISamplerState, public GLResource
{
public:
	IMPLEMENT_IRESOURCE

	static const int typeID = TYPE_ID_SAMPLER_STATE;

	GLSamplerState();

	void* DynamicCast(int type_id)	{ return (type_id == TYPE_ID_SAMPLER_STATE) ? this : GLResource::DynamicCast(type_id); }
	bool Create(const gls::SamplerStateDesc& desc);
	void Destroy();
};



#endif // _GL_SAMPLER_STATE_H_
