#include "Window.h"
#include <exception>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

#ifdef __linux__
#include <unistd.h>
#endif //__linux__
#include "DirectionalLight.h"

namespace libGraphic
{
	void Window::processInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_UP))
			camera.advance();
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_DOWN))
			camera.stepBack();
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_LEFT))
			camera.left();
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT))
			camera.right();

	}
	void Window::mouseInput(GLFWwindow* window)
	{
		double posX, posY;
		glfwGetCursorPos(window, &posX, &posY);
		camera.moveCamera((float)posX, (float)posY);
		
	}
	void Window::processLighting()
	{
		char numPoint = 0;
		for (auto it = lights.begin(); it != lights.end(); it++)
		{
			if ((*it))
			{
				switch ((*it)->getType())
				{
				case TypeLight::DIRECTIONAL:
				{
					DirectionalLight* dirLight = dynamic_cast<DirectionalLight*>(it->get());

					shader->setVec3("dirLight.direction", dirLight->getDirection().toGlmVec());
					shader->setVec3("dirLight.ambient", dirLight->getAmbient().toGlmVec());
					shader->setVec3("dirLight.diffuse", dirLight->getDiffuse().toGlmVec());
					shader->setVec3("dirLight.specular", dirLight->getSpecular().toGlmVec());
					break;
				}
				case TypeLight::POINT:
				{
					std::string s = "pointLights[";
					s += (numPoint + 48);
					shader->setVec3(s + "].position", (*it)->getPosition().toGlmVec());
					shader->setVec3(s + "].ambient", (*it)->getAmbient().toGlmVec());
					shader->setVec3(s + "].diffuse", (*it)->getDiffuse().toGlmVec());
					shader->setVec3(s + "].specular", (*it)->getSpecular().toGlmVec());
					numPoint++;
					break;
				}
				case TypeLight::SPOT:
				{
					break;
				}
				default:
					break;
				}
			}
		}

		////set unuse point light value to 0.0
		//for (char i = 0; i < 4; i++)
		//{
		//	std::string s = "pointLights[";
		//	s += (i + 48);
		//	shader->setFloat(s + "].ambient", 0.0f);
		//	shader->setFloat(s + "].diffuse", 0.0f);
		//	shader->setFloat(s + "].specular", 0.0f);
		//}

		//set shader's uniform light value
			/*shader->setVec3("pointLights[0].position", light.getPosition().toGlmVec());
			shader->setVec3("pointLights[0].ambient", Light::getAmbientColor().toGlmVec());
			shader->setVec3("pointLights[0].diffuse", light.getDiffuseColor().toGlmVec());
			shader->setVec3("pointLights[0].specular", light.getSpecularColor().toGlmVec());	*/
	}
	Window::Window(unsigned int width, unsigned int height, const char* title) :
		width(width), height(height), window(nullptr), collection(),
		backgroundColor(Color::BLACK()), shader(nullptr), camera(width, height),
		framerateLimit(60), callBack(), lights()
	{
		// Initialise GLFW
		if (!glfwInit())
		{
			throw std::exception("Failed to initialize GLFW");
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
			throw std::exception("Failed to open GLFW window");
		}
		glfwMakeContextCurrent(window);

		// Initialize GLEW
		if (glewInit() != GLEW_OK) {
			glfwTerminate();
			throw std::exception("Failed to initialize GLEW");
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
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// texture coord attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		//normal vector
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
		glEnableVertexAttribArray(2);

		//get vertices array from our shapes
		updateObjectPosition();

		glm::mat4 model = glm::mat4(1.0f);
		//model = glm::rotate(model, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);
		//projection = glm::ortho(0.0f, (float)width, 0.0f, (float)height, 0.1f, 100.f);

		//use our shaders
		shader->use();

		shader->setMat4("model", model);
		shader->setMat4("projection", projection);

		double timeToWaitAtEachFrame = (1.0 / framerateLimit) * 1000;

		while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			glfwWindowShouldClose(window) == 0) {

			double startframe = glfwGetTime();

			//input 
			processInput(window);
			mouseInput(window);

			//clear screen and z-buffer
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		

			if (callBack)
			{
				callBack();
			}

			//set camera matrix
			glm::mat4 view = camera.getView();
			shader->setMat4("view", view);

			processLighting();	

			shader->setVec3("cameraPosition", camera.getPosition());

			//draw, color, texture and transform shape
			int count = 0;
			auto &shapes = collection.getShapes();
			for (auto s = shapes.begin(); s != shapes.end(); s++)
			{
				Color color = (*s)->getColor();
	
				//set shader's uniform values
				shader->setVec3("material.ambient", (*s)->getColor().toGlmVec());
				shader->setVec3("material.diffuse", (*s)->getColor().toGlmVec());
				shader->setVec3("material.specular", glm::vec3(0.5f));
				shader->setFloat("material.shininess", 32.0f);

				shader->setMat4("transform", (*s)->getTransformation());
				shader->setBool("readTexture", (*s)->useTexture());
				shader->setInt("texture1", (*s)->getIdTexture());

				glDrawArrays(GL_TRIANGLES, count , 3 * (*s)->getCountTriangle());
				count += 3 * (*s)->getCountTriangle();
			}

			// Swap buffers
			glfwSwapBuffers(window);

			//check events
			glfwPollEvents();

			//wait aprox 16 millisecond to have 60fps
			double endframe = glfwGetTime();			
			double waitTime = timeToWaitAtEachFrame - ((endframe - startframe) * 1000);
			waitTime = waitTime > 0.0 ? waitTime : 0.0;
			std::cout << waitTime << std::endl;
#ifdef _WIN32
			Sleep((DWORD)waitTime);
#endif // _WIN32

#ifdef __linux__
			usleep((unsigned int)(waitTime/1000.0));
#endif // __linux__

		}

		//clean memory
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &bufferId);

	}
	void Window::addShape(const Shape& s)
	{
		collection.add(s);
	}
	void Window::addLight(const Light& light)
	{
		lights.push_back(light.clone());		
	}
	void Window::setBackgroundColor(Color color)
	{
		this->backgroundColor = color;
	}
	std::vector<std::unique_ptr<Shape>>& Window::getShapes()
	{
		return collection.getShapes();
	}
	void Window::setFramerateLimit(unsigned char limit)
	{
		framerateLimit = limit;
	}
	void Window::setCallBackFunction(void func())
	{
		callBack = [func]() {func();};
	}
	void Window::updateObjectPosition()
	{
		//(re)bind the buffer with the data of our shapes vertices
		std::vector<float> vertices = collection.getVertices();
		if (vertices.size() != 0)
		{
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
		}
	}
}
