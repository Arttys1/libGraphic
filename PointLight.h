#ifndef H_POINT_LIGHT
#define H_POINT_LIGHT
#pragma once
#include "Light.h"

namespace libGraphic
{
	class PointLight : public Light
	{
	public:
		PointLight();
		PointLight(Vector3D position);
		PointLight(Color color);
		PointLight(Vector3D position, Color color);
		PointLight(Color ambient, Color diffuse, Color specular);
		PointLight(Vector3D position, Color ambient, Color diffuse, Color specular);

		// Hérité via Light
		virtual TypeLight getType() const override;
		virtual std::unique_ptr<Light> clone() const override;

	};
}

#endif // !H_POINT_LIGHT