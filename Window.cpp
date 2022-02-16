#include "Window.h"
#include <exception>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

#ifdef __linux__
#include <unistd.h>
#endif //__linux__

namespace libGraphic
{
	void Window::processInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			camera->advance();
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			camera->stepBack();
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			camera->left();
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			camera->right();

	}
	void Window::mouseInput(GLFWwindow* window)
	{
		double posX, posY;
		glfwGetCursorPos(window, &posX, &posY);
		camera->moveCamera(posX, posY);
		
	}
	Window::Window(unsigned int width, unsigned int height, const char* title) :
		width(width), height(height), window(nullptr), collection(new ShapeCollection()), backgroundColor(Color::BLACK()), shader(nullptr), camera(new Camera(width, height))
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

		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		//define defaults shaders
		const char* vertexShaderSource = "shader/vertexShader.glsl";
		const char* fragmentShaderSource = "shader/fragmentShader.glsl";

		this->shader = new Shader(vertexShaderSource, fragmentShaderSource);
	}

	Window::~Window()
	{
		delete shader;
		delete collection;
		delete camera;
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

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::rotate(model, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

		//use our shaders
		shader->use();

		shader->setMat4("model", model);
		shader->setMat4("projection", projection);

		while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			glfwWindowShouldClose(window) == 0) {

			double startframe = glfwGetTime();

			//input 
			processInput(window);
			mouseInput(window);

			//clear screen and z-buffer
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			

			//set camera matrix
			glm::mat4 view = camera->getView();
			shader->setMat4("view", view);

			//draw, color, texture and transform shape
			int count = 0;
			for (Shape *s : collection->getShapes())
			{
				Color color = s->getColor();
	
				//set shader's uniform values
				shader->setVec3("color", glm::vec3(color.getRed(), color.getGreen(), color.getBlue()));
				shader->setMat4("transform", s->getTransformation());
				shader->setBool("readTexture", s->useTexture());

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
