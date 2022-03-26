#include "Light.h"

namespace libGraphic 
{
	//init static attributes
	Color Light::ambientColor = Color::WHITE();
	float Light::ambientStrenght = 0.5f;

	Light::Light(Vector3D pos) :
		Light(pos, Color::WHITE(), 1.0f)
	{
	}

	Light::Light(Vector3D pos, Color color) :
		Light(pos, color, 1.0f)
	{
	}

	Light::Light(Vector3D pos, float strength) :
		Light(pos, Color::WHITE(), strength)
	{
	}

	Light::Light(Vector3D pos, Color color, float strength) :
		position(pos), lightColor(color), strength(strength)
	{
	}
	Vector3D Light::getPosition() const
	{
		return position;
	}
	Color Light::getLightColor() const
	{
		return lightColor;
	}
	float Light::getStrength() const
	{
		return strength;
	}
	void Light::setPosition(Vector3D pos)
	{
		position = pos;
	}
	void Light::setLightColor(Color color)
	{
		lightColor = color;
	}
	void Light::setStrenght(float strength)
	{
		this->strength = strength;
	}
	Color Light::getAmbientColor()
	{
		return Light::ambientColor;
	}
	float Light::getAmbientStrenght()
	{
		return Light::ambientStrenght;
	}
	void Light::setAmbientColor(Color color)
	{
		Light::ambientColor = color;
	}
	void Light::setAmbientstrength(float strength)
	{
		Light::ambientStrenght = strength;
	}
}