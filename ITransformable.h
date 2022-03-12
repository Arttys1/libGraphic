#pragma once
#ifndef H_ITRANSFORMABLE
#define H_ITRANSFORMABLE

#include "Vector3D.h"

namespace libGraphic
{
	class ITransformable
	{
		virtual void addRotationX(float axis) = 0;
		virtual void addRotationY(float axis) = 0;
		virtual void addRotationZ(float axis) = 0;


		virtual void addTranslationX(float trans) = 0;
		virtual void addTranslationY(float trans) = 0;
		virtual void addTranslationZ(float trans) = 0;

		virtual void addScaleX(float scale) = 0;
		virtual void addScaleY(float scale) = 0;
		virtual void addScaleZ(float scale) = 0;

		virtual glm::mat4 getTransformation() const = 0;
	};
}
#endif // !H_ITRANSFORMABLE