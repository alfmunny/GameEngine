#version 330

smooth in vec3 theColor;
out vec3 outputColor;

void main()
{
    outputColor = vec3(theColor);
}