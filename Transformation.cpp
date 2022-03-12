#include "Transformation.h"

namespace libGraphic
{
	Transformation::Transformation()
		: transform(glm::mat4(1.0f))	//set the matrix to identity matrix
	{
	}

	glm::mat4 Transformation::getTransformation() const
	{
		return transform;
	}
	void Transformation::addRotationX(float axis)
	{
		transform = glm::rotate(transform, axis, glm::vec3(1, 0.f, 0.f));
	}
	void Transformation::addRotationY(float axis)
	{
		transform = glm::rotate(transform, axis, glm::vec3(0.f, 1.f, 0.f));
	}
	void Transformation::addRotationZ(float axis)
	{
		transform = glm::rotate(transform, axis, glm::vec3(0.f, 0.f, 1.f));
	}
	void Transformation::addTranslationX(float trans)
	{
		transform = glm::translate(transform, glm::vec3(trans, 0.f, 0.f));
	}
	void Transformation::addTranslationY(float trans)
	{
		transform = glm::translate(transform, glm::vec3(0.f, trans, 0.f));

	}
	void Transformation::addTranslationZ(float trans)
	{
		transform = glm::translate(transform, glm::vec3(0.f, 0.f, trans));
	}
	void Transformation::addScaleX(float scale)
	{
		transform = glm::scale(transform, glm::vec3(scale, 0.0f, 0.0f));
	}
	void Transformation::addScaleY(float scale)
	{
		transform = glm::scale(transform, glm::vec3(0.0f, scale, 0.0f));
	}
	void Transformation::addScaleZ(float scale)
	{
		transform = glm::scale(transform, glm::vec3(0.0f, 0.0f, scale));
	}
}