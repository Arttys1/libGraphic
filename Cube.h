#pragma once
#include "Shape.h"

namespace libGraphic
{
	class Cube : public Shape
	{
	private:
		float width, height, depth;

	public:
		Cube(Vector3D pos, float width, float height, float depth);
		Cube(Vector3D pos, float width, float height, float depth, Color color);

		// Hérité via Shape
		virtual std::vector<float> getVertices() override;
		virtual unsigned int getCountTriangle() override;
		virtual std::unique_ptr<Shape> clone() const override;
	};
}
