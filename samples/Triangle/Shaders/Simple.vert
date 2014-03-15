
#version 330
#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable

layout(binding = 0) uniform VsConstants
{
	mat4 wvpMatrix;
};

in VsInput
{
	layout(location = 0) vec3 inVertPosition;
	layout(location = 1) vec4 inVertColor;
};

out VsOutput
{
	layout(location = 0) vec4 outColor;
};

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
