#pragma once
#ifndef H_TRIANGLE
#define H_TRIANGLE
#include "Shape.h"

namespace libGraphic
{
	class Triangle : public Shape
	{
	private:
		float width, height;

	public:
		Triangle(Vector3D pos, float width, float height, Color color) : Shape(pos, color), width(width), height(height) { }
		Triangle(Vector3D pos, float width, float height) : Shape(pos), width(width), height(height) { }
		~Triangle();


		// Hérité via Shape
		virtual std::vector<float> getVertices() override;
		virtual unsigned int getCountTriangle() override;
		virtual std::unique_ptr<Shape> clone() const override;

	};
}

#endif // !H_TRIANGLE