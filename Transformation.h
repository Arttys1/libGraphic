#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Vector3D.h"
#include "GLFW/glfw3.h"
#include "ITransformable.h"
#include <vector>
#include <functional>

namespace libGraphic
{
	enum class TransformationType {
		ROTATION, TRANSLATION, SCALE
	};

	class Transformation : ITransformable
	{
	private:
		glm::mat4 transform;
		std::vector<TransformationType> types;
		std::vector<float> speeds;
		std::vector<Vector3D> angles;
		
		static float getUniformTime();
		void addOperationInQueue(TransformationType, float, Vector3D);

		glm::mat4 RotationTime(float, Vector3D);

	public:
		Transformation();

		void addRotation(Vector3D angle);
		void addRotationTime(float rotationSpeed, Vector3D angle);

		void addTranslation(Vector3D trans);
		void addTranslationTime(float translationSpeed, Vector3D trans);

		void addScale(Vector3D scale);
		void addScale(float scalar);
		void addScaleTime(float scaleSpeed, Vector3D scale);
		void addScaleTime(float scaleSpeed, float scalar);
		

		glm::mat4 getTransformation() const;
	};
}
