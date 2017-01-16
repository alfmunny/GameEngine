#version 330 core
layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Color;

smooth out vec3 theColor;

void main()
{
    gl_Position = vec4(Position, 1.0);
    theColor = Color;
}