#include "Window.h"
#include <exception>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

#ifdef __linux__
#include <unistd.h>
#endif

namespace libGraphic
{
	Window::Window(unsigned int width, unsigned int height, const char* title) : 
		width(width), height(height), window(nullptr), collection(new ShapeCollection()), backgroundColor(Color::BLACK()), shader(nullptr)
	{
		// Initialise GLFW
		if (!glfwInit())
		{
			throw new std::exception("Failed to initialize GLFW");
		}

		//glfw's parameters
		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Open a window and create its OpenGL context
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (!window) {
			glfwTerminate();
			throw new std::exception("Failed to open GLFW window");
		}
		glfwMakeContextCurrent(window);

		// Initialize GLEW
		if (glewInit() != GLEW_OK) {
			glfwTerminate();
			throw new std::exception("Failed to initialize GLEW");
		}	

		//set input on
		glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

		//define defaults shaders
		const char* vertexShaderSource = "#version 330 core\n"
			"layout (location = 0) in vec3 position;\n"
			"layout (location = 1) in vec2 texPosition;\n"
			"uniform mat4 transform;\n"
			"out vec2 texturePosition;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = transform * vec4(position, 1.0);\n"
				"texturePosition = texPosition;"
			"}\0";

		const char* fragmentShaderSource = "#version 330 core\n"
			"in vec2 texturePosition;\n"
			"out vec4 FragColor;\n"
			"uniform vec3 color;\n"
			"uniform sampler2D ourTexture;"
			"void main()\n"
			"{\n"
			"	FragColor =  texture(ourTexture, texturePosition) * vec4(color, 1.0);\n"
			"}\n\0";

		this->shader = new Shader(vertexShaderSource, fragmentShaderSource);

	}

	Window::~Window()
	{
		delete shader;
		delete collection;
		glfwTerminate();
	}

	void Window::loop()
	{
		// set background color
		glClearColor(backgroundColor.getRed(), backgroundColor.getGreen(), backgroundColor.getBlue(), 0.0f);
		glEnable(GL_DEPTH_TEST); //use z-buffer

		//init buffers
		unsigned int bufferId;
		glGenBuffers(1, &bufferId);
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);

		unsigned int VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		//vertice coord 
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// texture coord attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		//get vertices array from our shape
		std::vector<float> vertices = collection->getVertices();
		if (vertices.size() != 0)
		{
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
		}

		


		//use our shaders
		shader->use();

		while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			glfwWindowShouldClose(window) == 0) {

			double startframe = glfwGetTime();

			//clear screen and z-buffer
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			

			//draw and color shape
			int count = 0;
			for (Shape *s : collection->getShapes())
			{
				Color color = s->getColor();
				int vertexColorLocation = glGetUniformLocation(shader->getId(), "color");
				glUniform3f(vertexColorLocation, color.getRed(), color.getGreen(), color.getBlue());		

				int transformLoc = glGetUniformLocation(shader->getId(), "transform");
				glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(s->getTransformation()));

				s->useTexture();

				glDrawArrays(GL_TRIANGLES, count , 3 * s->getCountTriangle());
				count += 3 * s->getCountTriangle();
			}


			// Swap buffers
			glfwSwapBuffers(window);

			//check events
			glfwPollEvents();

			//wait aprox 16 millisecond to have 60fps
			double endframe = glfwGetTime();

#ifdef _WIN32
			Sleep(16.0 - (endframe - startframe));
#endif // _WIN32

#ifdef __linux__
			sleep((16.0 - (endframe - startframe))/1000.0);
#endif // __linux__

		}

		//clean memory
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &bufferId);

	}
	void Window::addShape(Shape* s)
	{
		collection->add(s);
	}
	void Window::setBackgroundColor(Color color)
	{
		this->backgroundColor = color;
	}
	std::vector<Shape*> Window::getShapes() const
	{
		return collection->getShapes();
	}
}
