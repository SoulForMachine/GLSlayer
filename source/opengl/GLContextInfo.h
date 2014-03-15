
#ifndef _GL_CONTEXT_INFO_H_
#define _GL_CONTEXT_INFO_H_


struct GLContextInfo : gls::ContextInfo
{
	// extension availability flags

	bool extVersion_1_2 : 1;
	bool extVersion_1_3 : 1;
	bool extVersion_1_4 : 1;
	bool extVersion_1_5 : 1;
	bool extVersion_2_0 : 1;
	
	bool extVersion_2_1 : 1;
	bool extPixelBufferObject : 1;
	bool extTextureSRGB : 1;

	bool extVersion_3_0 : 1;
	bool extFramebufferObject : 1;
	bool extMapBufferRange : 1;
	bool extVertexArrayObject : 1;
	bool extDepthBufferFloat : 1;
	bool extFramebufferSRGB : 1;
	bool extHalfFloatVertex : 1;
	bool extTexCompressionRGTC : 1;
	bool extTextureRG : 1;
	bool extTextureFilterAnisotropic : 1;

	bool extVersion_3_1 : 1;
	bool extCopyBuffer : 1;
	bool extUniformBufferObject : 1;
	bool extTextureRectangle : 1;
	bool extTextureSNorm : 1;

	bool extVersion_3_2 : 1;
	bool extDepthClamp : 1;
	bool extDrawElementsBaseVertex : 1;
	bool extProvokingVertex : 1;
	bool extSync : 1;
	bool extTextureMultisample : 1;
	bool extGeometryShader4 : 1;
	bool extFragmentCoordConventions : 1;
	bool extSeamlessCubeMap : 1;

	bool extVersion_3_3 : 1;
	bool extBlendFuncExtended : 1;
	bool extSamplerObjects : 1;
	bool extExplicitAttribLocation : 1;
	bool extOcclusionQuery2 : 1;
	bool extShaderBitEncoding : 1;
	bool extTextureRGB10A2ui : 1;
	bool extTextureSwizzle : 1;
	bool extTimerQuery : 1;
	bool extVertexType_2_10_10_10_rev : 1;

	bool extVersion_4_0 : 1;
	bool extTextureQueryLod : 1;
	bool extDrawIndirect : 1;
	bool extGPUShader5 : 1;
	bool extGPUShaderFP64 : 1;
	bool extShaderSubroutine : 1;
	bool extTessellationShader : 1;
	bool extTextureBufferObjectRGB32 : 1;
	bool extTextureCubeMapArray : 1;
	bool extTextureGather : 1;
	bool extTransformFeedback2 : 1;
	bool extTransformFeedback3 : 1;

	bool extVersion_4_1 : 1;
	bool extES2Compatibility : 1;
	bool extGetProgramBinary : 1;
	bool extSeparateShaderObjects : 1;
	bool extShaderPrecision : 1;
	bool extVertexAttrib64bit : 1;
	bool extViewportArray : 1;

	bool extVersion_4_2 : 1;
	bool extBaseInstance : 1;
	bool extShaderLanguage420Pack : 1;
	bool extTransformFeedbackInstanced : 1;
	bool extCompressedTexturePixelStorage : 1;
	bool extConservativeDepth : 1;
	bool extInternalformatQuery : 1;
	bool extMapBufferAlignment : 1;
	bool extShaderAtomicCounters : 1;
	bool extShaderImageLoadStore : 1;
	bool extShadingLanguagePacking : 1;
	bool extTextureStorage : 1;
	bool extTextureCompressionBPTC : 1;

	bool extVersion_4_3 : 1;
	bool extArraysOfArrays : 1;
	bool extClearBufferObject : 1;
	bool extComputeShader : 1;
	bool extCopyImage : 1;
	bool extES3Compatibility : 1;
	bool extExplicitUniformLocation : 1;
	bool extFragmentLayerViewport : 1;
	bool extFramebufferNoAttachments : 1;
	bool extInternalformatQuery2 : 1;
	bool extInvalidateSubdata : 1;
	bool extMultiDrawIndirect : 1;
	bool extShaderImageSize : 1;
	bool extShaderStorageBufferObject : 1;
	bool extStencilTexturing : 1;
	bool extTextureBufferRange : 1;
	bool extTextureQueryLevel : 1;
	bool extTextureStorageMultisample : 1;
	bool extTextureView : 1;
	bool extVertexAttribBinding : 1;
	bool extDebug : 1;

	// platform specific extensions
	bool pextExtensionsString : 1;
	bool pextPixelFormat : 1;
	bool pextPixelFormatFloat : 1; //extColorBufferFloat
	bool pextMultisample : 1;
	bool pextSwapControl : 1;
	bool pextFramebufferSRGB : 1;
	bool pextCreateContext : 1;
	bool pextSwapMethod : 1;
};



#endif // _GL_CONTEXT_INFO_H_
