#include "Cube.h"

namespace libGraphic 
{
	Cube::Cube(Vector3D pos, float width, float height, float depth) 
		: Shape(pos), width(width), height(height), depth(depth)
	{
	}
	Cube::Cube(Vector3D pos, float width, float height, float depth, Color color)
		: Shape(pos, color), width(width), height(height), depth(depth)
	{
	}
	std::vector<float> Cube::getVertices()
	{
		Vector3D pos = getposition();

		return std::vector<float> {
			//position of vertices								//position of texture	//normal vector
			pos.getX(), pos.getY(), pos.getZ(),					 1.0f, 1.0f,		0.0f, 0.0f, -1.0f, //first rectangle (face)
			pos.getX() + width, pos.getY(), pos.getZ(),			 0.0f, 1.0f,		0.0f, 0.0f, -1.0f,
			pos.getX(), pos.getY() + height, pos.getZ(),		 1.0f, 0.0f,		0.0f, 0.0f, -1.0f,

			pos.getX() + width, pos.getY() + height, pos.getZ(), 0.0f, 0.0f,		0.0f, 0.0f, -1.0f,
			pos.getX() + width, pos.getY(), pos.getZ(),			 0.0f, 1.0f,		0.0f, 0.0f, -1.0f, 
			pos.getX(), pos.getY() + height, pos.getZ(),		 1.0f, 0.0f,		0.0f, 0.0f, -1.0f,

			pos.getX(), pos.getY(), pos.getZ(),					 1.0f, 1.0f,		-1.0f, 0.0f, 0.0f,	//second rectangle (left side)
			pos.getX(), pos.getY() + height, pos.getZ(),		 1.0f, 0.0f,		-1.0f, 0.0f, 0.0f,
			pos.getX(), pos.getY(), pos.getZ() + depth,			 0.0f, 1.0f,		-1.0f, 0.0f, 0.0f,

			pos.getX(), pos.getY() + height, pos.getZ(),		 1.0f, 0.0f,		-1.0f, 0.0f, 0.0f,
			pos.getX(), pos.getY(), pos.getZ() + depth,			 0.0f, 1.0f,		-1.0f, 0.0f, 0.0f,
			pos.getX(), pos.getY() + height, pos.getZ() + depth, 0.0f, 0.0f,		-1.0f, 0.0f, 0.0f,

			pos.getX() + width, pos.getY(), pos.getZ(),			 1.0f, 1.0f,		1.0f, 0.0f, 0.0f, //third rectangle (right side)
			pos.getX() + width, pos.getY() + height, pos.getZ(), 1.0f, 0.0f,		1.0f, 0.0f, 0.0f,
			pos.getX() + width, pos.getY(), pos.getZ() + depth,  0.0f, 1.0f,		1.0f, 0.0f, 0.0f,

			pos.getX() + width, pos.getY() + height, pos.getZ(),		 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
			pos.getX() + width, pos.getY(), pos.getZ() + depth,			 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			pos.getX() + width, pos.getY() + height, pos.getZ() + depth, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

			pos.getX(), pos.getY(), pos.getZ(),					 1.0f, 1.0f,		0.0f, -1.0f, 0.0f,	//fourth rectangle (under side)
			pos.getX(), pos.getY(), pos.getZ() + depth,			 0.0f, 1.0f,		0.0f, -1.0f, 0.0f,
			pos.getX() + width, pos.getY(), pos.getZ(),			 1.0f, 0.0f,		0.0f, -1.0f, 0.0f,

			pos.getX() + width, pos.getY(), pos.getZ() + depth,  0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
			pos.getX(), pos.getY(), pos.getZ() + depth,			 0.0f, 1.0f,		0.0f, -1.0f, 0.0f,
			pos.getX() + width, pos.getY(), pos.getZ(),			 1.0f, 0.0f,		0.0f, -1.0f, 0.0f,

			pos.getX(), pos.getY() + height, pos.getZ(),			1.0f, 1.0f,			0.0f, 1.0f, 0.0f, //fifth rectangle (upper side)
			pos.getX(), pos.getY() + height, pos.getZ() + depth,	0.0f, 1.0f,			0.0f, 1.0f, 0.0f,
			pos.getX() + width, pos.getY() + height, pos.getZ(),	1.0f, 0.0f,			0.0f, 1.0f, 0.0f,

			pos.getX() + width, pos.getY() + height, pos.getZ() + depth, 0.0f, 0.0f,	0.0f, 1.0f, 0.0f,
			pos.getX(), pos.getY() + height, pos.getZ() + depth,		 0.0f, 1.0f,	0.0f, 1.0f, 0.0f,
			pos.getX() + width, pos.getY() + height, pos.getZ(),		 1.0f, 0.0f,	0.0f, 1.0f, 0.0f,

			pos.getX(), pos.getY(), pos.getZ() + depth,				1.0f, 1.0f,			0.0f, 0.0f, 1.0f, //sixth rectangle (back)
			pos.getX() + width, pos.getY(), pos.getZ() + depth,		0.0f, 1.0f,			0.0f, 0.0f, 1.0f,
			pos.getX(), pos.getY() + height, pos.getZ() + depth,	1.0f, 0.0f,			0.0f, 0.0f, 1.0f,

			pos.getX() + width, pos.getY() + height, pos.getZ() + depth, 0.0f, 0.0f,	0.0f, 0.0f, 1.0f,
			pos.getX() + width, pos.getY(), pos.getZ() + depth,			 0.0f, 1.0f,	0.0f, 0.0f, 1.0f,
			pos.getX(), pos.getY() + height, pos.getZ() + depth,		1.0f, 0.0f,		0.0f, 0.0f, 1.0f,
		};

	}
	unsigned int Cube::getCountTriangle()
	{
		return 12;
	}
	std::unique_ptr<Shape> Cube::clone() const
	{
		return std::make_unique<Cube>(*this);
	}
}