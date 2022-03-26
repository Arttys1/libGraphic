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

#include <functional>

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
		Light light;
		Color backgroundColor;
		unsigned char framerateLimit;
		std::function<void()> callBack;		

		void processInput(GLFWwindow *window);
		void mouseInput(GLFWwindow *window);

	public:
		Window(unsigned int width = 900, unsigned int height = 600, const char* title = "");
		~Window();
		void loop();
		void addShape(Shape*);
		void setLight(Light);
		void setBackgroundColor(Color);
		std::vector<Shape*> getShapes() const;
		void setFramerateLimit(unsigned char limit);
		void setCallBackFunction(void());
		void updateObjectPosition();

	};
}

#endif // !H_WINDOW
