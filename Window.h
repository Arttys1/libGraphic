#pragma once
#ifndef H_WINDOW
#define H_WINDOW

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>

#include "ShapeCollection.h"
#include "Shader.h"
#include "Camera.h"
#include "Light.h"

#include <memory>
#include <functional>

namespace libGraphic
{
	class Window
	{
	private:
		//Attributes who manage the windows
		unsigned int width;
		unsigned int height;
		unsigned char framerateLimit;
		GLFWwindow* window;
		Color backgroundColor;

		//Attributes who manage shapes and drawing of the scene
		ShapeCollection collection;
		Shader* shader;
		Camera camera;
		std::vector<std::unique_ptr<Light>> lights;
		
		
		std::function<void()> callBack;		

		void processInput(GLFWwindow *window);
		void mouseInput(GLFWwindow *window);
		void processLighting();

	public:
		Window(unsigned int width = 900, unsigned int height = 600, const char* title = "");
		~Window();
		void loop();
		void addShape(const Shape& s);
		void addLight(const Light& light);
		void setBackgroundColor(Color);
		std::vector<std::unique_ptr<Shape>>& getShapes();
		void setFramerateLimit(unsigned char limit);
		void setCallBackFunction(void());
		void updateObjectPosition();

	};
}

#endif // !H_WINDOW
