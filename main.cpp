#include "libGraphic.h"
using namespace libGraphic;
#include <iostream>

Window window(900, 600, "test");

void render() {	
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
	PointLight point(Vector3D(1.f, -0.25f, -0.5f), Color::WHITE()/2.0f);
	PointLight point2(Vector3D(1.0f, 1.2f, 2.f), Color::WHITE() / 2.0f);
	DirectionalLight dirLight(Vector3D(-0.2f, -1.0f, -0.3f), Color(0.05f, 0.05f, 0.05f), Color(0.4f, 0.4f, 0.4f), Color(0.5f, 0.5f, 0.5f));
	SpotLight spot(Vector3D(0.f, -1.f, 0.f), Vector3D(0.f, 1.f, 2.f), Color(0.05f, 0.05f, 0.05f), Color::WHITE(), Color::WHITE());
	window.addLight(point);
	//window.addLight(point2);
	window.addLight(dirLight);
	//window.addLight(spot);

	Cube sol(Vector3D(-20, -1, 0), 40, 0.1f, 40);
	sol.setTexture(Texture::LoadTexture("ciel.jpg"));
	window.addShape(sol);


	Vector3D vec = Vector3D(-0.5f, -0.5f, -0.5f);
	Cube cube(vec, 1.f, 1.f, 1.f, Color::RED());
	//cube.setTexture(Texture::LoadTexture("universe.png"));
	Cube cube2(Vector3D(1.5f, -0.5f, -0.5f), 1.f, 1.f, 1.f, Color::CYAN());
	//cube2.setTexture(Texture::LoadTexture("universe.png"));
	window.addShape(cube2);
	window.addShape(cube);
	
	
	window.loop();

	return 0;
}