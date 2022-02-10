#include "Triangle.h"


namespace libGraphic {
    Triangle::~Triangle()
    {
    }

    std::vector<float> Triangle::getVertices()
    {
        Vector3D pos = getposition();
        Color c = getColor();
        std::vector<float> vertices{
            pos.getX(), pos.getY(), pos.getZ(),             1.0f, 1.0f,
            pos.getX() + width, pos.getY(), pos.getZ(),     0.0f, 1.0f,
            pos.getX(), pos.getY() + height, pos.getZ(),    1.0f, 0.0f,
        };

        return vertices;
    }

    unsigned int Triangle::getCountTriangle()
    {
        return 1;
    }
}