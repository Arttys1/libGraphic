#pragma once
#ifndef H_LIGHT
#define H_LIGHT
#include "Vector3D.h"
#include "Color.h"
#include <memory>

namespace libGraphic
{
	enum class TypeLight
	{
		DIRECTIONAL, POINT, SPOT
	};

	class Light
	{
	private:
		Color ambient, diffuse, specular;
		Vector3D position;
	public:
		Light();
		Light(Vector3D position);
		Light(Color color);
		Light(Vector3D position, Color color);
		Light(Color ambient, Color diffuse, Color specular);
		Light(Vector3D position, Color ambient, Color diffuse, Color specular);

		Color getAmbient() const;
		Color getDiffuse() const;
		Color getSpecular() const;
		Vector3D getPosition() const;

		void setAmbient(Color color);
		void setDiffuse(Color color);
		void setSpecular(Color color);
		void setPosition(Vector3D pos);

		virtual TypeLight getType() const = 0;
		virtual std::unique_ptr<Light> clone() const = 0;
	};
}

#endif // !H_LIGHT