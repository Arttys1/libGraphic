#include "ShapeCollection.h"
#include <algorithm>

namespace libGraphic
{
	ShapeCollection::~ShapeCollection()
	{
	}
	void ShapeCollection::add(const Shape& s)
	{
		shapes.push_back(s.clone());
	}
	std::vector<float> ShapeCollection::getVertices() const
	{
		std::vector<float> tab;
		for (auto it = shapes.begin(); it != shapes.end(); it++)
		{
			std::vector<float> vertices = (*it)->getVertices();
			tab.insert(tab.end(), vertices.begin(), vertices.end());
		}

		return tab;
	}
	unsigned int ShapeCollection::getCountTriangle() const
	{
		unsigned int count = 0;

		for (auto it = shapes.begin(); it != shapes.end(); it++)
		{
			count += (*it)->getCountTriangle();
		}

		return count;
	}
	std::vector<std::unique_ptr<Shape>>& ShapeCollection::getShapes()
	{
		return shapes;
	}
}
