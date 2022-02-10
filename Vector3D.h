#pragma once
#ifndef H_VECTOR3D
#define H_VECTOR3D
#include <glm/glm.hpp>

namespace libGraphic
{
	class Vector3D
	{
	private:
		float x, y, z;

	public:
		Vector3D(float x = 0, float y = 0, float z = 0);

		float getX() const;
		float getY() const;
		float getZ() const;

		void setX(float x);
		void setY(float y);
		void setZ(float z);

		glm::vec3 toGlmVec() const;
	};
}

#endif // !H_VECTOR3D

