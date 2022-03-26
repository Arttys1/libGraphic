#include "Camera.h"

namespace libGraphic
{
	Camera::Camera(unsigned int widthScreen, unsigned int heightScreen)
		: cameraPosition(0.0f, 0.0f, 3.0f), spead(0.25f), cameraFront(0.0f, 0.0f, -1.0f), cameraUp(0.0f , 1.0f, 0.0f)
		, lastX(widthScreen/2.0f), lastY(heightScreen/2.0f), yaw(-90.0f), pitch(0.0f)
	{
	}
	Camera::~Camera()
	{
	}
	void Camera::advance()
	{
		cameraPosition += spead * cameraFront;
	}
	void Camera::stepBack()
	{
		cameraPosition -= spead * cameraFront;
	}
	void Camera::right()
	{
		cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)) * spead;
	}
	void Camera::left()
	{
		cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)) * spead;
	}
	glm::mat4 Camera::getView() const
	{
		return glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
	}
	glm::vec3 Camera::getPosition() const
	{
		return cameraPosition;
	}
	void Camera::setCameraSpead(float spead)
	{
		this->spead = spead;
	}
	void Camera::moveCamera(float cursorPosX, float cursorPosY)
	{
		if (cursorPosX != lastX && cursorPosY != lastY)
		{
			float xoffset = cursorPosX - lastX;
			float yoffset = lastY - cursorPosY;
			lastX = cursorPosX;
			lastY = cursorPosY;

			float sensitivity = 0.1f;
			xoffset *= sensitivity;
			yoffset *= sensitivity;

			yaw += xoffset;
			pitch += yoffset;

			pitch = pitch > 89.0f ? 89.0f : pitch;
			pitch = pitch < -89.0f ? -89.0f : pitch;

			//change the direction of the camera
			glm::vec3 direction{};
			direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
			direction.y = sin(glm::radians(pitch));
			direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
			cameraFront = glm::normalize(direction);
		}
	}
}