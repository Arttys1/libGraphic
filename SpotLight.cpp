#include "SpotLight.h"

namespace libGraphic
{
	SpotLight::SpotLight(Vector3D direction, Vector3D position, Color color, float cutOff, float outerCutOff)
		: SpotLight(direction, position, color, color, color, cutOff, outerCutOff)
	{
	}
	SpotLight::SpotLight(Vector3D direction, Vector3D position, Color ambient, Color diffuse, Color specular, float cutOff, float outerCutOff)
		: Light(position, ambient, diffuse, specular), direction(direction), cutOff(cutOff), outerCutOff(outerCutOff)
	{
	}
	TypeLight SpotLight::getType() const
	{
		return TypeLight::SPOT;
	}
	std::unique_ptr<Light> SpotLight::clone() const
	{
		return std::make_unique<SpotLight>(*this);
	}
	void SpotLight::setDirection(Vector3D dir)
	{
		direction = dir;
	}
	void SpotLight::setCutOff(float cutoff)
	{
		this->cutOff = cutoff;
	}
	void SpotLight::setOuterCutOff(float outercutoff)
	{
		this->outerCutOff = outercutoff;
	}
	Vector3D SpotLight::getDirection() const
	{
		return direction;
	}
	float SpotLight::getCutOff() const
	{
		return cutOff;
	}
	float SpotLight::getOuterCutOff() const
	{
		return outerCutOff;
	}
}