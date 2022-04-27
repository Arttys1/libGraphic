#include "Shape.h"

namespace libGraphic
{
	Shape::~Shape()
	{
	}
	Vector3D Shape::getposition() const
	{
		return position;
	}
	void Shape::setPosition(Vector3D v)
	{
		this->position = v;
	}
	Color Shape::getColor() const
	{
		return color;
	}
	bool Shape::isAffectByLight() const
	{
		return affectByLight;
	}
	void Shape::setColor(Color c)
	{
		this->color = c;
	}
	void Shape::setTexture(std::shared_ptr<Texture> texture)
	{
		this->texture = texture;
	}
	void Shape::setAffectByLight(bool affect)
	{
		affectByLight = affect;
	}
	bool Shape::useTexture() const
	{
		if (texture)
		{
			texture->use();
			return true;
		}
		return false;
	}
	int Shape::getIdTexture() const
	{
		if (texture)
		{
			return texture->getId();
		}
		return -1;
	}
	void Shape::addRotationX(float axis)
	{
		transformation.addRotationX(axis);
	}
	void Shape::addRotationY(float axis)
	{
		transformation.addRotationY(axis);
	}
	void Shape::addRotationZ(float axis)
	{
		transformation.addRotationZ(axis);
	}
	void Shape::addTranslationX(float trans)
	{
		transformation.addTranslationX(trans);
	}
	void Shape::addTranslationY(float trans)
	{
		transformation.addTranslationY(trans);
	}
	void Shape::addTranslationZ(float trans)
	{
		transformation.addTranslationZ(trans);
	}
	void Shape::addScaleX(float scale)
	{
		transformation.addScaleX(scale);
	}
	void Shape::addScaleY(float scale)
	{
		transformation.addScaleY(scale);
	}
	void Shape::addScaleZ(float scale)
	{
		transformation.addScaleZ(scale);
	}
	glm::mat4 Shape::getTransformation() const
	{
		return transformation.getTransformation();
	}
}