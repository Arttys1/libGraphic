#pragma once
#ifndef H_SHAPE
#define H_SHAPE
#include <vector>
#include "Color.h"
#include "Transformation.h"
#include "ITransformable.h"
#include "Texture.h"
#include "Vector3D.h"

namespace libGraphic
{
	class Shape : public ITransformable
	{
	private:
		Vector3D *position;
		Transformation* transformation;
		Color color;
		Texture* texture;

	public:
		Shape(Vector3D* pos) : Shape(pos, Color::WHITE()){ }
		Shape(Vector3D* pos, Color color) : position(pos), color(color), transformation(new Transformation()), texture(nullptr) { }
		virtual ~Shape();

		virtual std::vector<float> getVertices() = 0;
		virtual unsigned int getCountTriangle() = 0;

		Vector3D getposition() const;
		void setPosition(Vector3D* v);
		Color getColor() const;
		void setColor(Color c);
		
		void setTexture(Texture* texture);
		bool useTexture() const;
		int getIdTexture() const;

		// Hérité via ITransformable
		virtual void addRotation(Vector3D angle) override;
		virtual void addRotationTime(float rotationSpeed, Vector3D angle) override;

		virtual void addTranslation(Vector3D trans) override;
		virtual void addTranslationTime(float translationSpeed, Vector3D trans) override;

		virtual void addScale(Vector3D scale) override;
		virtual void addScale(float scalar) override;
		virtual void addScaleTime(float scaleSpeed, Vector3D scale) override;
		virtual void addScaleTime(float scaleSpeed, float scalar) override;

		virtual glm::mat4 getTransformation() const override;

	};
}
#endif // !H_SHAPE
