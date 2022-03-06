#pragma once
#ifndef H_ITRANSFORMABLE
#define H_ITRANSFORMABLE

#include "Vector3D.h"

namespace libGraphic
{
	class ITransformable
	{
		virtual void addRotation(Vector3D angle) = 0;
		virtual void addRotationTime(float rotationSpeed, Vector3D angle) = 0;

		virtual void addTranslation(Vector3D trans) = 0;
		virtual void addTranslationTime(float translationSpeed, Vector3D trans) = 0;

		virtual void addScale(Vector3D scale) = 0;
		virtual void addScale(float scalar) = 0;
		virtual void addScaleTime(float scaleSpeed, Vector3D scale) = 0;
		virtual void addScaleTime(float scaleSpeed, float scalar) = 0;


		virtual glm::mat4 getTransformation() const = 0;
	};
}
#endif // !H_ITRANSFORMABLE