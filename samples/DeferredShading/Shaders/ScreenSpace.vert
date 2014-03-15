
#version 330
#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable

in VsInput
{
	layout(location = 0) vec2 inVertPosition; // screen-space position
	layout(location = 1) vec2 inVertUV;
};

out VsOutput
{
	layout(location = 0) vec2 outUV;
};

layout(binding = 0) uniform VsConstants
{
	vec4 viewport;
};

out gl_PerVertex
{
	vec4 gl_Position;
	float gl_PointSize;
	float gl_ClipDistance[];
};


void main()
{
	vec2 pos = (inVertPosition - viewport.xy) / viewport.zw;
	gl_Position = vec4(pos * 2.0 - 1.0, 0.0, 1.0);
	outUV = inVertUV;
}
