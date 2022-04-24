#include "DirectionalLight.h"

namespace libGraphic
{
    DirectionalLight::DirectionalLight(Vector3D direction)
        : Light(), direction(direction)
    {
    }
    DirectionalLight::DirectionalLight(Vector3D direction, Color color)
        : Light(color), direction(direction)
    {
    }
    DirectionalLight::DirectionalLight(Vector3D direction, Color ambient, Color diffuse, Color specular)
        : Light(ambient, diffuse, specular), direction(direction)
    {
    }
    Vector3D DirectionalLight::getDirection() const
    {
        return direction;
    }
    void DirectionalLight::setDirection(Vector3D direction)
    {
        this->direction = direction;
    }
	TypeLight DirectionalLight::getType() const
	{
		return TypeLight::DIRECTIONAL;
	}
    std::unique_ptr<Light> DirectionalLight::clone() const
    {
        return std::make_unique<DirectionalLight>(*this);
    }
}