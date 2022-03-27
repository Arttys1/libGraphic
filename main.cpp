#include "libGraphic.h"
using namespace libGraphic;
#include <iostream>

Cube* cube;

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
	window.setLight(Light(Vector3D(-2, 2, 2), Color::WHITE(), 1.f));
	Light::setAmbientstrength(0.1f);

	Color c(0, 0, 0);
	c * 3;
	/*Cube* sol = new Cube(Vector3D(-20, -1, 0), 40, 0.1f, 40);
	sol->setTexture(new Texture("ciel.jpg"));
	window.addShape(sol);*/


	Vector3D vec = Vector3D(-0.5f, -0.5f, -0.5f);
	cube = new Cube(vec, 1.f, 1.f, 1.f, Color(1.0f, 0.5f, 0.31f));
	/*cube->addScaleX(10);
	cube->addScaleY(10);
	cube->addScaleZ(10);*/
	//cube->setTexture(new Texture("universe.png"));
	window.addShape(cube);
	
	
	window.loop();

	return 0;
}