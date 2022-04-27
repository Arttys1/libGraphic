#ifndef H_SPOT_LIGHT
#define H_SPOT_LIGHT
#pragma once
#include "Light.h"

namespace libGraphic
{
	class SpotLight : public Light
	{
	private:
		Vector3D direction;
		float cutOff, outerCutOff;
	public:
		SpotLight(Vector3D direction, Vector3D position = Vector3D(), Color color = Color::WHITE(), float cutOff = 0.91, float outerCutOff = 0.82);
		SpotLight(Vector3D direction, Vector3D position, Color ambient, Color diffuse, Color specular, float cutOff = 0.91f, float outerCutOff = 0.82f);


		// Hérité via Light
		virtual TypeLight getType() const override;
		virtual std::unique_ptr<Light> clone() const override;
		
		Vector3D getDirection() const;
		float getCutOff() const;
		float getOuterCutOff() const;
		
		void setDirection(Vector3D dir);
		void setCutOff(float cutoff);
		void setOuterCutOff(float outercutoff);
	};
}

#endif // !H_SPOT_LIGHT


