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
		Vector3D position;
		Transformation* transformation;
		Color color;
		Texture* texture;

	public:
		Shape(Vector3D pos) : Shape(pos, Color::WHITE()){ }
		Shape(Vector3D pos, Color color) : position(pos), color(color), transformation(new Transformation()), texture(nullptr) { }
		virtual ~Shape();

		virtual std::vector<float> getVertices() = 0;
		virtual unsigned int getCountTriangle() = 0;

		Vector3D getposition() const;
		void setPosition(Vector3D v);
		Color getColor() const;
		void setColor(Color c);
		
		void setTexture(Texture* texture);
		bool useTexture() const;
		int getIdTexture() const;

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

		virtual glm::mat4 getTransformation() const override;
	};
}
#endif // !H_SHAPE
