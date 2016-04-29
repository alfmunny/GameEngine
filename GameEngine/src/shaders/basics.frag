#version 330 core

layout (location = 0) out vec4 color;
uniform vec4 colour;
uniform vec2 light_pos;

in vec4 pos;

void main()
{
	float indensity = 1.0 / length(pos.xy - light_pos);
	color = colour * indensity;
}