#pragma once
#ifndef h_SHAPE_COL
#define h_SHAPE_COL
#include <vector>
#include "Shape.h"

namespace libGraphic
{
	class ShapeCollection
	{
	private:
		std::vector<Shape*> shapes;	

	public:
		ShapeCollection() : shapes() { };
		~ShapeCollection();
		void add(Shape*);
		std::vector<float> getVertices() const;
		unsigned int getCountTriangle() const;
		std::vector<Shape*> getShapes() const;

	};
}

#endif // !h_SHAPE_COL