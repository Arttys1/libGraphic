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

		Vector3D operator*(const Vector3D&) const;
		Vector3D operator+(const Vector3D&) const;
		Vector3D operator-(const Vector3D&) const;
		Vector3D operator/(const Vector3D&) const;
		void operator*=(const Vector3D&);
		void operator+=(const Vector3D&);
		void operator-=(const Vector3D&);
		void operator/=(const Vector3D&);
		Vector3D operator*(float) const;
		Vector3D operator+(float) const;
		Vector3D operator-(float) const;
		Vector3D operator/(float) const;
		void operator*=(float);
		void operator+=(float);
		void operator-=(float);
		void operator/=(float);
	};
}

#endif // !H_VECTOR3D

