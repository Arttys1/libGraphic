#include "Window.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Cube.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>

using namespace libGraphic;

int main()
{

	libGraphic::Window window(900, 600, "test");
	window.setBackgroundColor(Color(0.f, 0.f, 0.35f));
	
	//Triangle *tri = new Triangle(new Vector3D(), -1.f, 1.f, Color::MAGENTA());
	//tri->setTexture(new Texture("ciel.jpg"));
	//window.addShape(tri);
	/*window.addShape(new Triangle(new Vector3D(), 1.f, -1.f, Color::BLACK()));
	window.addShape(new Triangle(new Vector3D(), -1.f, -1.f, Color::RED()));*/
	//window.addShape(new Triangle(new Vector3D(), 1.f, 1.f, Color::GREEN()));
	//window.addShape(new Rectangle(new Vector3D(), -0.9f, -0.9f, Color::YELLOW()));
	//window.addShape(new Rectangle(new Vector3D(-0.5f, 0.5f), 1.f, -1.f, Color::CYAN()));

	Cube *cube = new Cube(new Vector3D(-0.5f, -0.5f, -1), 0.75f, 0.75f, 0.75f);
	cube->setTexture(new Texture("universe.png"));
	window.addShape(cube);
	/*Rectangle *rect = new Rectangle(new Vector3D(-0.5, -0.5), 1, 1);
	rect->setTexture(new Texture("ciel.jpg"));
	window.addShape(rect);*/
	

	for (Shape* s : window.getShapes()) {
		s->addRotationTime(glm::radians(50.f), Vector3D(1.f, 1.0f, 0));
	}

	

	window.loop();


	return 0;
}