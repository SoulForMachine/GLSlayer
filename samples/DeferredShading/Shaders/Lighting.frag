
#version 330
#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable

layout(location = 0) flat in int inLightIndex;

layout(location = 0) out vec4 fragColor;

layout(binding = 0) uniform FsConstants
{
	vec4 viewport;
};

layout(binding = 1) uniform samplerBuffer lightPalette;
layout(binding = 2) uniform sampler2D diffuseTex;
layout(binding = 3) uniform sampler2D positionTex;
layout(binding = 4) uniform sampler2D normalTex;

const float lightFalloffExp = 2.0;


void main()
{
	vec2 uv = (gl_FragCoord.xy - viewport.xy) / viewport.zw;
	vec4 diffuseColor = texture(diffuseTex, uv);
	vec3 position = texture(positionTex, uv).xyz;
	vec3 normal = normalize(texture(normalTex, uv).xyz);

	int index = inLightIndex * 2;
	vec4 lightPosRadius = texelFetch(lightPalette, index + 0);
	vec4 lightColor = texelFetch(lightPalette, index + 1);

	vec3 lightVec = lightPosRadius.xyz - position;
	float distance = length(lightVec);
	float intensity = pow(max(1.0 - distance / lightPosRadius.w, 0.0), lightFalloffExp);
	intensity *= dot(normal, normalize(lightVec));

	fragColor = lightColor * diffuseColor * intensity;
	//fragColor = vec4(0.01, 0.01, 0.01, 1.0);
}
