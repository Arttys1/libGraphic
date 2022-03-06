#include "libGraphic.h"
using namespace libGraphic;

int main()
{
	libGraphic::Window window(900, 600, "test");
	window.setBackgroundColor(Color(0.f, 0.f, 0.35f));
	window.setFramerateLimit(60);

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			Cube* cube = new Cube(new Vector3D(j * 1.0f, -1.5f, i * 1.f), 1.f, 1.f, 1.f);
			cube->setTexture(new Texture("universe.png"));
			window.addShape(cube);
		}
	}


	window.loop();


	return 0;
}