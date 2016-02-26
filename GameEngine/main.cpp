#include <iostream>
#include "src/graphics/window.h"
#include "src/maths/maths.h"

int main() 
{
	using namespace sparky;
	using namespace graphics;
	using namespace maths;
	Window window("Sparky!", 640, 480);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec2 v1(1.0f, 2.0f);
	vec2 v2(1.0f, 2.0f);
	vec4 v4(1.0f, 2.0f, 3.0f, 4.0f);

	mat4 position = mat4::translation(vec3(2, 3, 4));
	
	position *= mat4::identity();

	while (!window.closed())
	{
		//std::cout << window.getWidth() << "," << window.getHeight() << std::endl;

		window.clear();

		//std::cout << c << std::endl;

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}
	return 0;
}
