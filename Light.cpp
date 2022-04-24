#include "Light.h"

namespace libGraphic 
{
	Light::Light()
		: Light(Vector3D(), Color::WHITE(), Color::WHITE(), Color::WHITE())
	{
	}
	Light::Light(Vector3D position)
		: Light(position, Color::WHITE(), Color::WHITE(), Color::WHITE())
	{
	}
	Light::Light(Color color)
		: Light(Vector3D(), color, color, color)
	{
	}
	Light::Light(Vector3D position, Color color)
		: Light(position, color, color, color)
	{
	}
	Light::Light(Color ambient, Color diffuse, Color specular)
		: Light(Vector3D(), ambient, diffuse, specular)
	{
	}
	Light::Light(Vector3D position, Color ambient, Color diffuse, Color specular)
		: position(position), ambient(ambient), diffuse(diffuse), specular(specular)
	{
	}
	/*Light::Light(Light* other)
		: Light(other->position, other->ambient, other->diffuse, other->specular)
	{
	}
	Light::Light(Light& other)
		: Light(other.position, other.ambient, other.diffuse, other.specular)
	{
	}*/
	Color Light::getAmbient() const
	{
		return ambient;
	}
	Color Light::getDiffuse() const
	{
		return diffuse;
	}
	Color Light::getSpecular() const
	{
		return specular;
	}
	Vector3D Light::getPosition() const
	{
		return position;
	}
	void Light::setAmbient(Color color)
	{
		this->ambient = color;
	}
	void Light::setDiffuse(Color color)
	{
		this->diffuse = color;
	}
	void Light::setSpecular(Color color)
	{
		this->specular = color;
	}
	void Light::setPosition(Vector3D pos)
	{
		position = pos;
	}
}