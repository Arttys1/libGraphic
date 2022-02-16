#include "Vector3D.h"

namespace libGraphic
{
    Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z)
    {

    }

    float Vector3D::getX() const
    {
        return x;
    }
    float Vector3D::getY() const
    {
        return y;
    }
    float Vector3D::getZ() const
    {
        return z;
    }
    void Vector3D::setX(float x)
    {
        this->x = x;
    }
    void Vector3D::setY(float y)
    {
        this->y = y;
    }
    void Vector3D::setZ(float z)
    {
        this->z = z;
    }
    glm::vec3 Vector3D::toGlmVec() const
    {
        return glm::vec3(x, y, z);
    }
}