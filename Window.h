#pragma once
#ifndef H_WINDOW
#define H_WINDOW

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>

#include "ShapeCollection.h"
#include "Shader.h"
#include "Camera.h"

namespace libGraphic
{
	class Window
	{
	private:
		unsigned int width;
		unsigned int height;
		GLFWwindow* window;
		ShapeCollection* collection;
		Shader* shader;
		Camera* camera;
		Color backgroundColor;

		void processInput(GLFWwindow *window);
		void mouseInput(GLFWwindow *window);

	public:
		Window(unsigned int width = 900, unsigned int height = 600, const char* title = "");
		~Window();
		void loop();
		void addShape(Shape*);
		void setBackgroundColor(Color);
		std::vector<Shape*> getShapes() const;

	};
}

#endif // !H_WINDOW