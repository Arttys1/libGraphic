#pragma once
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace libGraphic
{
	class Camera
	{
	private:
		glm::vec3 cameraPosition;
		float spead;
		glm::vec3 cameraUp;
		glm::vec3 cameraFront;

		float lastX, lastY;	//mouse position

		float yaw, pitch; //Euler angle to move camera

	public:
		Camera(unsigned int widthScreen, unsigned int heightScreen);
		~Camera();
		void advance();
		void stepBack();
		void right();
		void left();

		glm::mat4 getView() const;
		void setCameraSpead(float spead);
		void moveCamera(float cursorPosX, float cursorPosY);
		
	};
}
