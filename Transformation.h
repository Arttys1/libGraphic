#pragma once
#ifndef H_TRANSFORMATION
#define H_TRANSFORMATION

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Vector3D.h"
#include "GLFW/glfw3.h"
#include "ITransformable.h"
#include <vector>

namespace libGraphic
{
	class Transformation : ITransformable
	{
	private:
		glm::mat4 transform;

	public:
		Transformation();		

		// Hérité via ITransformable
		virtual void addRotationX(float axis) override;
		virtual void addRotationY(float axis) override;
		virtual void addRotationZ(float axis) override;

		virtual void addTranslationX(float trans) override;
		virtual void addTranslationY(float trans) override;
		virtual void addTranslationZ(float trans) override;

		virtual void addScaleX(float scale) override;
		virtual void addScaleY(float scale) override;
		virtual void addScaleZ(float scale) override;
		
		glm::mat4 getTransformation() const;
	};
}

#endif // !H_TRANSFORMATION