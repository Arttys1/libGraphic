#include "Rectangle.h"

namespace libGraphic
{
    Rectangle::~Rectangle()
    {
    }
    std::vector<float> Rectangle::getVertices()
    {
        Vector3D pos = getposition();

        std::vector<float> vertices {
            //first triangle
            pos.getX(), pos.getY(), pos.getZ(),	                    1.0f, 1.0f,
            pos.getX() + width, pos.getY(), pos.getZ(),             0.0f, 1.0f,
            pos.getX(), pos.getY() + height, pos.getZ(),            1.0f, 0.0f,

            //second triangle
            pos.getX() + width, pos.getY() + height, pos.getZ(),	0.0f, 0.0f,
            pos.getX() + width, pos.getY(), pos.getZ(),             0.0f, 1.0f,
            pos.getX(), pos.getY() + height, pos.getZ(),            1.0f, 0.0f,
        };

        return vertices;
    }
    unsigned int Rectangle::getCountTriangle()
    {
        return 2;
    }
}