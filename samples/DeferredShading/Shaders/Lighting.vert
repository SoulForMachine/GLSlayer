
#version 330
#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable

layout(location = 0) in vec3 inVertPosition;

layout(location = 0) flat out int outLightIndex;

layout(binding = 0) uniform samplerBuffer wvpMatrixPalette;

out gl_PerVertex
{
	vec4 gl_Position;
	float gl_PointSize;
	float gl_ClipDistance[];
};

void main()
{
	mat4 vwpMatrix;
	int index = gl_InstanceID * 4;
	vwpMatrix[0] = texelFetch(wvpMatrixPalette, index + 0);
	vwpMatrix[1] = texelFetch(wvpMatrixPalette, index + 1);
	vwpMatrix[2] = texelFetch(wvpMatrixPalette, index + 2);
	vwpMatrix[3] = texelFetch(wvpMatrixPalette, index + 3);

	gl_Position = vwpMatrix * vec4(inVertPosition, 1.0f);
	outLightIndex = gl_InstanceID;
}
