#include "libGraphic.h"
using namespace libGraphic;
#include <iostream>

Cube* cube;

libGraphic::Window window(900, 600, "test");

void render() {	
	//cube->addRotationX(0.01f);
	//cube->addRotationY(0.01f);
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
	PointLight point(Vector3D(1.f, -0.25f, -0.5f), Color::WHITE()/3.0f);
	PointLight point2(Vector3D(1.0f, 1.2f, 2.f), Color::WHITE() / 3.0f);
	DirectionalLight dirLight(Vector3D(-0.2f, -1.0f, -0.3f), Color(0.05f, 0.05f, 0.05f), Color(0.4f, 0.4f, 0.4f), Color(0.5f, 0.5f, 0.5f));
	window.addLight(&point);
	//window.addLight(&point2);
	window.addLight(&dirLight);

	/*Cube* sol = new Cube(Vector3D(-20, -1, 0), 40, 0.1f, 40);
	sol->setTexture(new Texture("ciel.jpg"));
	window.addShape(sol);*/

	glm::vec3(-0.2f, -1.0f, -0.3f);
	glm::vec3(0.05f, 0.05f, 0.05f);
	glm::vec3(0.4f, 0.4f, 0.4f);
	glm::vec3(0.5f, 0.5f, 0.5f);


	Vector3D vec = Vector3D(-0.5f, -0.5f, -0.5f);
	cube = new Cube(vec, 1.f, 1.f, 1.f, Color::RED());
	/*cube->addScaleX(10);
	cube->addScaleY(10);
	cube->addScaleZ(10);*/
	//cube->setTexture(new Texture("universe.png"));

	window.addShape(new Cube(Vector3D(1.5f, -0.5f, -0.5f), 1.f, 1.f, 1.f, Color::CYAN()));
	window.addShape(cube);
	
	
	window.loop();

	return 0;
}