#include "ShapeCollection.h"
#include <algorithm>

namespace libGraphic
{
	ShapeCollection::~ShapeCollection()
	{
		for (Shape* shape : shapes)
		{
			delete shape;			
		}
	}
	void ShapeCollection::add(Shape*s)
	{
		shapes.push_back(s);
	}
	std::vector<float> ShapeCollection::getVertices() const
	{
		std::vector<float> tab;
		for (Shape* shape : shapes)
		{
			std::vector<float> vertices = shape->getVertices();
			tab.insert(tab.end(), vertices.begin(), vertices.end());
		}

		return tab;
	}
	unsigned int ShapeCollection::getCountTriangle() const
	{
		unsigned int count = 0;

		for (Shape* s : shapes)
		{
			count += s->getCountTriangle();
		}

		return count;
	}
	std::vector<Shape*> ShapeCollection::getShapes() const
	{
		return shapes;
	}
}
