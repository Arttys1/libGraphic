#include "libGraphic.h"
using namespace libGraphic;

int main()
{
	libGraphic::Window window(900, 600, "test");
	window.setBackgroundColor(Color(0.f, 0.f, 0.35f));
	
	Triangle* tri = new Triangle(new Vector3D(), -1.f, 1.f, Color::RED());
	tri->setTexture(new Texture("ciel.jpg"));
	window.addShape(tri);
	/*window.addShape(new Triangle(new Vector3D(), 1.f, -1.f, Color::BLACK()));
	window.addShape(new Triangle(new Vector3D(), -1.f, -1.f, Color::RED()));*/
	//window.addShape(new Triangle(new Vector3D(), 1.f, 1.f, Color::GREEN()));
	//window.addShape(new Rectangle(new Vector3D(), -0.9f, -0.9f, Color::YELLOW()));
	//window.addShape(new Rectangle(new Vector3D(-0.5f, 0.5f), 1.f, -1.f, Color::CYAN()));

	Cube *cube = new Cube(new Vector3D(-0.5f, -0.5f, -1.f), 1.f, 1.f, 1.f);
	cube->setTexture(new Texture("universe.png"));
	window.addShape(cube);
	/*Rectangle *rect = new Rectangle(new Vector3D(-0.5, -0.5), 1, 1);
	rect->setTexture(new Texture("ciel.jpg"));
	window.addShape(rect);*/
	window.addShape(new Cube(new Vector3D(0.0f, 0.0f, 0.0f), 1.f, 1.f, 1.f, Color::CYAN()));
	window.addShape(new Cube(new Vector3D(2.0f, 5.0f, -15.0f), 1.f, 1.f, 1.f));
	window.addShape(new Cube(new Vector3D(-1.5f, -2.2f, -2.5f), 1.f, 1.f, 1.f));
	window.addShape(new Cube(new Vector3D(-3.8f, -2.0f, -12.3f), 1.f, 1.f, 1.f));
	window.addShape(new Cube(new Vector3D(2.4f, -0.4f, -3.5f), 1.f, 1.f, 1.f));

	for (Shape* s : window.getShapes()) {
		//s->addRotationTime(glm::radians(50.f), Vector3D(0.5f, 1.0f, 0));
	}

	window.loop();


	return 0;
}