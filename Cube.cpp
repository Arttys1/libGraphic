#include "Cube.h"

namespace libGraphic 
{
	Cube::Cube(Vector3D *pos, float width, float height, float depth) 
		: Shape(pos), width(width), height(height), depth(depth)
	{
	}
	Cube::Cube(Vector3D *pos, float width, float height, float depth, Color color)
		: Shape(pos, color), width(width), height(height), depth(depth)
	{
	}
	std::vector<float> Cube::getVertices()
	{
		Vector3D pos = getposition();

		return std::vector<float> {
			//position of vertices								//position of texture
			pos.getX(), pos.getY(), pos.getZ(),					 1.0f, 1.0f,	//first rectangle
			pos.getX() + width, pos.getY(), pos.getZ(),			 0.0f, 1.0f,
			pos.getX(), pos.getY() + height, pos.getZ(),		 1.0f, 0.0f, 

			pos.getX() + width, pos.getY() + height, pos.getZ(), 0.0f, 0.0f,
			pos.getX() + width, pos.getY(), pos.getZ(),			 0.0f, 1.0f,
			pos.getX(), pos.getY() + height, pos.getZ(),		 1.0f, 0.0f,

			pos.getX(), pos.getY(), pos.getZ(),					 1.0f, 1.0f,	//second rectangle
			pos.getX(), pos.getY() + height, pos.getZ(),		 1.0f, 0.0f,
			pos.getX(), pos.getY(), pos.getZ() + depth,			 0.0f, 1.0f,

			pos.getX(), pos.getY() + height, pos.getZ(),		 1.0f, 0.0f,
			pos.getX(), pos.getY(), pos.getZ() + depth,			 0.0f, 1.0f,
			pos.getX(), pos.getY() + height, pos.getZ() + depth, 0.0f, 0.0f,

			pos.getX() + width, pos.getY(), pos.getZ(),			 1.0f, 1.0f,	//third rectangle
			pos.getX() + width, pos.getY() + height, pos.getZ(), 1.0f, 0.0f,
			pos.getX() + width, pos.getY(), pos.getZ() + depth,  0.0f, 1.0f,

			pos.getX() + width, pos.getY() + height, pos.getZ(),		 1.0f, 0.0f,
			pos.getX() + width, pos.getY(), pos.getZ() + depth,			 0.0f, 1.0f,
			pos.getX() + width, pos.getY() + height, pos.getZ() + depth, 0.0f, 0.0f,

			pos.getX(), pos.getY(), pos.getZ(),					 1.0f, 1.0f,	//fourth rectangle
			pos.getX(), pos.getY(), pos.getZ() + depth,			 0.0f, 1.0f,
			pos.getX() + width, pos.getY(), pos.getZ(),			 1.0f, 0.0f,

			pos.getX() + width, pos.getY(), pos.getZ() + depth,  0.0f, 0.0f,
			pos.getX(), pos.getY(), pos.getZ() + depth,			 0.0f, 1.0f,
			pos.getX() + width, pos.getY(), pos.getZ(),			 1.0f, 0.0f,

			pos.getX(), pos.getY() + height, pos.getZ(), 1.0f, 1.0f,		//fifth rectangle
			pos.getX(), pos.getY() + height, pos.getZ() + depth, 0.0f, 1.0f,
			pos.getX() + width, pos.getY() + height, pos.getZ(), 1.0f, 0.0f,

			pos.getX() + width, pos.getY() + height, pos.getZ() + depth, 0.0f, 0.0f,
			pos.getX(), pos.getY() + height, pos.getZ() + depth, 0.0f, 1.0f,
			pos.getX() + width, pos.getY() + height, pos.getZ(), 1.0f, 0.0f,

			pos.getX(), pos.getY(), pos.getZ() + depth, 1.0f, 1.0f,	//sixth rectangle
			pos.getX() + width, pos.getY(), pos.getZ() + depth, 0.0f, 1.0f,
			pos.getX(), pos.getY() + height, pos.getZ() + depth, 1.0f, 0.0f,

			pos.getX() + width, pos.getY() + height, pos.getZ() + depth, 0.0f, 0.0f,
			pos.getX() + width, pos.getY(), pos.getZ() + depth, 0.0f, 1.0f,
			pos.getX(), pos.getY() + height, pos.getZ() + depth, 1.0f, 0.0f,
		};

	}
	unsigned int Cube::getCountTriangle()
	{
		return 12;
	}
}