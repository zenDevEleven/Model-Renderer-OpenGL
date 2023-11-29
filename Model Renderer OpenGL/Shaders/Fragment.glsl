#version 330 core
in vec3 Color;
in vec2 TexCoord;

out vec4 outColor;

uniform sampler2D texture_diffuse1;

void main()
{
	outColor = texture(texture_diffuse1, TexCoord);
}