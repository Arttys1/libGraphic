#include "libGraphic.h"
using namespace libGraphic;
#include <iostream>

Cube* cube;
Vector3D vec;

libGraphic::Window window(900, 600, "test");

void render() {	
	//cube->addRotationX(0.1f);
	//cube->addScaleX(1.1f);
	//cube->addRotationY(0.05f);

	//cube->addTranslationZ(-0.1f);
	//vec->setX(vec->getX() + 0.1f);
	//window.updateObjectPosition();
}

int main()
{
	window.setBackgroundColor(Color(0.f, 0.f, 0.35f));
	window.setFramerateLimit(60);
	window.setCallBackFunction(render);
	//window.setLight(Light(Vector3D(0, 0, 2), Color::WHITE(), 0.5f));

	/*Cube* sol = new Cube(Vector3D(-20, -1, 0), 40, 0.1f, 40);
	sol->setTexture(new Texture("ciel.jpg"));
	window.addShape(sol);*/


	vec = Vector3D(-0.5f, -0.5f, -0.5f);
	cube = new Cube(vec, 1.f, 1.f, 1.f, Color::CYAN());
	/*cube->addScaleX(10);
	cube->addScaleY(10);
	cube->addScaleZ(10);*/
	//cube->setTexture(new Texture("universe.png"));
	window.addShape(cube);
	
	
	window.loop();

	return 0;
}