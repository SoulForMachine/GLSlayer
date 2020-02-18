
#version 330
#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable

layout(location = 0) in vec2 inUV;

layout(location = 0, index = 0) out vec4 fragColor;

layout(binding = 0) uniform sampler2D DiffuseSampler;

layout(binding = 1) uniform FsConstants
{
	vec4 rangeMin;
	vec4 rangeMax;
	int texComponents;
};


void main()
{
	vec3 tex = texture(DiffuseSampler, inUV).rgb;
	tex = (tex - rangeMin.xyz) / (rangeMax.xyz - rangeMin.xyz);
	if (texComponents > 1)
		fragColor = vec4(tex, 1.0);
	else
		fragColor = vec4(tex.r, tex.r, tex.r, 1.0);
}
