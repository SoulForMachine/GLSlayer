
#ifndef _GLSLAYER_SAMPLER_STATE_H_
#define _GLSLAYER_SAMPLER_STATE_H_

#include "Common.h"
#include "Resource.h"


namespace gls
{


	struct SamplerStateDesc
	{
		SamplerStateDesc()
		{
			addressU = TEX_ADDRESS_REPEAT;
			addressV = TEX_ADDRESS_REPEAT;
			addressW = TEX_ADDRESS_REPEAT;
			minFilter = TEX_FILTER_NEAREST_MIPMAP_LINEAR;
			magFilter = TEX_FILTER_LINEAR;
			borderColor[0] = 0.0f;
			borderColor[1] = 0.0f;
			borderColor[2] = 0.0f;
			borderColor[3] = 0.0f;
			minLOD = -1000.0f;
			maxLOD = 1000.0f;
			lodBias = 0.0f;
			texCmpMode = DEPTH_CMP_NONE;
			texCmpFunc = FUNC_LEQUAL;
			maxAnisotropy = 1.0f;
		}

		TexAddressMode addressU;
		TexAddressMode addressV;
		TexAddressMode addressW;
		TexFilter minFilter;
		TexFilter magFilter;
		float borderColor[4];
		float minLOD;
		float maxLOD;
		float lodBias;
		TexCompareMode texCmpMode;
		CompareFunc texCmpFunc;
		float maxAnisotropy;
	};


	class ISamplerState : public IResource
	{
	public:
		virtual ~ISamplerState() = 0;
	};


	inline
	ISamplerState::~ISamplerState()
	{
	}

}


#endif // _GLSLAYER_SAMPLER_STATE_H_
