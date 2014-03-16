
#version 330
#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable

layout(binding = 1) uniform FsConstants
{
	vec4 color;
};

layout(location = 0) in vec3 inWorldPosition;
layout(location = 1) in vec3 inWorldNormal;

layout(location = 0, index = 0) out vec4 fragPosition;
layout(location = 1, index = 0) out vec4 fragNormal;
layout(location = 2, index = 0) out vec4 fragColor;

void main()
{
	fragPosition = vec4(inWorldPosition, 0.0);
	fragNormal = vec4(normalize(inWorldNormal), 0.0);
	fragColor = color;
}
