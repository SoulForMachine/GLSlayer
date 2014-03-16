
#version 330
#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable

layout(binding = 0) uniform VsConstants
{
	mat4 wvpMatrix;
};

layout(location = 0) in vec3 inVertPosition;
layout(location = 1) in vec4 inVertColor;

layout(location = 0) out vec4 outColor;

out gl_PerVertex
{
	vec4 gl_Position;
	float gl_PointSize;
	float gl_ClipDistance[];
};


void main()
{
	gl_Position = wvpMatrix * vec4(inVertPosition, 1.0);
	outColor = inVertColor;
}
