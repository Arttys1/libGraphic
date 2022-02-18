#include "Shape.h"

namespace libGraphic
{
	Shape::~Shape()
	{
		delete texture;
		delete transformation;
		delete position;
	}
	Vector3D Shape::getposition() const
	{
		return *position;
	}
	void Shape::setPosition(Vector3D* v)
	{
		this->position = v;
	}
	Color Shape::getColor() const
	{
		return color;
	}
	void Shape::setColor(Color c)
	{
		this->color = c;
	}
	void Shape::setTexture(Texture* texture)
	{
		this->texture = texture;
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
		if(texture)
			return texture->getId();
		return -1;
	}
	void Shape::addRotation(Vector3D angle)
	{
		transformation->addRotation(angle);
	}
	void Shape::addRotationTime(float rotationSpeed, Vector3D angle)
	{
		transformation->addRotationTime(rotationSpeed, angle);
	}
	void Shape::addTranslation(Vector3D trans)
	{
		transformation->addTranslation(trans);
	}
	void Shape::addTranslationTime(float translationSpeed, Vector3D trans)
	{
		transformation->addTranslationTime(translationSpeed, trans);
	}
	void Shape::addScale(Vector3D scale)
	{
		transformation->addScale(scale);
	}
	void Shape::addScale(float scalar)
	{
		transformation->addScale(scalar);
	}
	void Shape::addScaleTime(float scaleSpeed, Vector3D scale)
	{
		transformation->addScaleTime(scaleSpeed, scale);
	}
	void Shape::addScaleTime(float scaleSpeed, float scalar)
	{
		transformation->addScaleTime(scaleSpeed, scalar);
	}
	glm::mat4 Shape::getTransformation() const
	{
		return transformation->getTransformation();
	}
}