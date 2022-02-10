#include "Transformation.h"

namespace libGraphic
{
	float Transformation::getUniformTime()
	{
		return (float)glfwGetTime();
	}
	void Transformation::addOperationInQueue(TransformationType type, float speed, Vector3D angle)
	{
		types.push_back(type);
		speeds.push_back(speed);
		angles.push_back(angle);
	}
	glm::mat4 Transformation::RotationTime(float rotationSpeed, Vector3D angle)
	{
		return glm::rotate(transform, getUniformTime() * rotationSpeed, angle.toGlmVec());
	}
	Transformation::Transformation()
		: transform(glm::mat4(1.0f)),	//set the matrix to identity matrix
		types(), speeds(), angles()
	{
	}
	void Transformation::addRotation(Vector3D angle)
	{
		transform = glm::rotate(transform, 1.f, angle.toGlmVec());
	}
	void Transformation::addRotationTime(float rotationSpeed, Vector3D angle)
	{
		addOperationInQueue(TransformationType::ROTATION, rotationSpeed, angle);
	}
	void Transformation::addTranslation(Vector3D trans)
	{
		transform = glm::translate(transform, trans.toGlmVec());
	}
	void Transformation::addTranslationTime(float translationSpeed, Vector3D trans)
	{
		addOperationInQueue(TransformationType::TRANSLATION, translationSpeed, trans);
	}
	void Transformation::addScale(Vector3D scale)
	{
		transform = glm::scale(transform, scale.toGlmVec());
	}
	void Transformation::addScale(float scalar)
	{
		transform = glm::scale(transform, glm::vec3(1.0f, 1.0f, 1.0f) * scalar);
	}
	void Transformation::addScaleTime(float scaleSpeed, Vector3D scale)
	{
		addOperationInQueue(TransformationType::SCALE, scaleSpeed, scale);
	}
	void Transformation::addScaleTime(float scaleSpeed, float scalar)
	{
		addOperationInQueue(TransformationType::SCALE, scaleSpeed, Vector3D(scalar, scalar, scalar));
	}
	glm::mat4 Transformation::getTransformation() const
	{
		auto result = transform;
		for (size_t i = 0; i < types.size(); i++)
		{
			switch (types[i])
			{
			case TransformationType::ROTATION: result = glm::rotate(result, Transformation::getUniformTime() * speeds[i], angles[i].toGlmVec()); break;
			case TransformationType::TRANSLATION: result = glm::translate(result, angles[i].toGlmVec() * getUniformTime() * speeds[i]); break;
			case TransformationType::SCALE: result = glm::scale(result, angles[i].toGlmVec() * getUniformTime() * speeds[i]); break;
			}
		}


		return result;
	}
}