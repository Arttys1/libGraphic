#ifndef H_DIRECTIONAL_LIGHT
#define H_DIRECTIONAL_LIGHT
#pragma once
#include "Light.h"
namespace libGraphic
{
	class DirectionalLight : public Light
	{
	private:
		Vector3D direction;
	public:
		DirectionalLight(Vector3D direction);
		DirectionalLight(Vector3D direction, Color color);
		DirectionalLight(Vector3D direction, Color ambient, Color diffuse, Color specular);

		Vector3D getDirection() const;
		void setDirection(Vector3D direction);

		// Hérité via Light
		virtual TypeLight getType() const override;
		virtual std::unique_ptr<Light> clone() const override;
	};
}
#endif // !H_DIRECTIONAL_LIGHT
