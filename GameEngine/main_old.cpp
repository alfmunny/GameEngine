#include <iostream>
#include <time.h>
#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/maths/maths.h"

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"
#include "src/graphics/renderable2d.h"
#include "src/graphics/renderer2d.h"
#include "src/graphics/simple2drenderer.h"

#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"
#include "src/graphics/batchrenderer2d.h"

int main_old() 
{
	using namespace sparky;
	using namespace graphics;
	using namespace maths;
	Window window("Sparky!", 960, 540);
	//glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);


	Shader shader("src/shaders/basics.vert", "src/shaders/basics.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);

	std::vector<Renderable2D*> sprites;

	Sprite sprite(5, 5, 4, 4, maths::vec4(1, 0, 1, 1));
	Sprite sprite2(7, 1, 2, 3, maths::vec4(0.2f, 0, 1, 1));

	BatchRenderer2D renderer;

	for (float y = 0; y < 9.0f; y+= 0.1f)
	{
		for (float x = 0; x < 16.0f; x+=0.1f)
		{
			sprites.push_back(new Sprite(x, y, 0.08f, 0.08f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x* 16.0f / 960.0f), (float)(9.0f - y*9.0f / 540.0f)));

		renderer.begin();
		for (int i = 0; i < sprites.size(); i++)
		{
			renderer.submit(sprites[i]);
		}
		renderer.end();
		renderer.flush();

		window.update();
	}
	return 0;
}