#include "PointLight.h"

namespace libGraphic
{
    PointLight::PointLight()
        : Light()
    {
    }
    PointLight::PointLight(Vector3D position)
        : Light(position)
    {
    }
    PointLight::PointLight(Color color)
        : Light(color)
    {
    }
    PointLight::PointLight(Vector3D position, Color color)
        : Light(position, color)
    {
    }
    PointLight::PointLight(Color ambient, Color diffuse, Color specular)
        : Light(ambient, diffuse, specular)
    {
    }
    PointLight::PointLight(Vector3D position, Color ambient, Color diffuse, Color specular)
        : Light(position, ambient, diffuse, specular)
    {
    }
    TypeLight PointLight::getType() const
    {
        return TypeLight::POINT;
    }
    std::unique_ptr<Light> PointLight::clone() const
    {
        return std::make_unique<PointLight>(*this);
    }
}