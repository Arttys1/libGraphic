#pragma once
#ifndef h_SHAPE_COL
#define h_SHAPE_COL
#include <vector>
#include <memory>
#include "Shape.h"

namespace libGraphic
{
	class ShapeCollection
	{
	private:
		std::vector<std::unique_ptr<Shape>> shapes;

	public:
		ShapeCollection() : shapes() { };
		~ShapeCollection();
		void add(const Shape& s);
		std::vector<float> getVertices() const;
		unsigned int getCountTriangle() const;
		std::vector<std::unique_ptr<Shape>>& getShapes();

	};
}

#endif // !h_SHAPE_COL