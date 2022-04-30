#include "Triangle.h"

namespace libGraphic {
    Triangle::~Triangle()
    {
    }

    std::vector<float> Triangle::getVertices()
    {
        Vector3D pos = getposition();
        std::vector<float> vertices{    
            //vertex position                       //texture position      //normal vector
            pos.getX(), pos.getY(), pos.getZ(),             1.0f, 1.0f,     0.f, 0.f, -1.f,
            pos.getX() + width, pos.getY(), pos.getZ(),     0.0f, 1.0f,     0.f, 0.f, -1.f,
            pos.getX(), pos.getY() + height, pos.getZ(),    1.0f, 0.0f,     0.f, 0.f, -1.f,
        };

        return vertices;
    }

    unsigned int Triangle::getCountTriangle()
    {
        return 1;
    }
    std::unique_ptr<Shape> Triangle::clone() const
    {
        return std::make_unique<Triangle>(*this);
    }
}