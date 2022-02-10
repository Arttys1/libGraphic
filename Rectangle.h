#pragma once
#ifndef H_RECTANGLE
#define H_RECTANGLE
#include "Shape.h"

namespace libGraphic
{
	class Rectangle : public Shape
	{
	private:
		float height;
		float width;

	public:
		Rectangle(Vector3D* v, float width, float height, Color color) : Shape(v, color), height(height), width(width) { }
		Rectangle(Vector3D *v, float width, float height) : Shape(v), height(height), width(width) { }
		~Rectangle();

		// Hérité via Shape
		virtual std::vector<float> getVertices() override;
		virtual unsigned int getCountTriangle() override;
	};
}

#endif // !H_RECTANGLE