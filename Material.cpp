#include "Material.h"

namespace libGraphic
{
    Material::Material()
        : Material(Color::WHITE(), Color::WHITE(), Color::WHITE()/2.f)
    {
    }
    Material::Material(Color color, float shininess)
        : Material(color, color, color, shininess)
    {
    }
    Material::Material(Color ambiant, Color diffuse, Color specular, float shininess)
        : ambiant(ambiant), diffuse(diffuse), specular(specular), shininess(shininess)
    {
    }
    Color Material::getAmbiant() const
    {
        return ambiant;
    }
    Color Material::getDiffuse() const
    {
        return diffuse;
    }
    Color Material::getSpecular() const
    {
        return specular;
    }
    float Material::getShininess() const
    {
        return shininess;
    }
    void Material::setAmbiant(Color color)
    {
        ambiant = color;
    }
    void Material::setDiffuse(Color color)
    {
        diffuse = color;
    }
    void Material::setSpecular(Color color)
    {
        specular = color;
    }
    void Material::setShininess(float shininess)
    {
        this->shininess = shininess;
    }
}