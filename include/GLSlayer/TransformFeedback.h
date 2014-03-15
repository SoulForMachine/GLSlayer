
#ifndef _GLSLAYER_TRANSFORM_FEEDBACK_H_
#define _GLSLAYER_TRANSFORM_FEEDBACK_H_

#include "Resource.h"


namespace gls
{

	class IBuffer;


	class ITransformFeedback : public IResource
	{
	public:
		virtual ~ITransformFeedback() {}

		virtual void BindBuffer(uint index, IBuffer* buffer) = 0;
		virtual void BindBuffer(uint index, IBuffer* buffer, size_t offset, size_t size) = 0;
	};

}

#endif // _GLSLAYER_TRANSFORM_FEEDBACK_H_
