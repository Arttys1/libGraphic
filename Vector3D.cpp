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
    Vector3D Vector3D::operator*(const Vector3D& v) const
    {
        return Vector3D(x * v.x, y * v.y, z * v.z);
    }
    Vector3D Vector3D::operator+(const Vector3D& v) const
    {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }
    Vector3D Vector3D::operator-(const Vector3D& v) const
    {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    }
    Vector3D Vector3D::operator/(const Vector3D& v) const
    {
        return Vector3D(x / v.x, y / v.y, z / v.z);
    }
    void Vector3D::operator*=(const Vector3D& v)
    {
        *this = (*this) * v;
    }
    void Vector3D::operator+=(const Vector3D& v)
    {
        *this = *this + v;
    }
    void Vector3D::operator-=(const Vector3D& v)
    {
        *this = *this - v;
    }
    void Vector3D::operator/=(const Vector3D& v)
    {
        *this = *this / v;
    }
    Vector3D Vector3D::operator*(float f) const
    {
        return Vector3D(x * f, y * f, z * f);
    }
    Vector3D Vector3D::operator+(float f) const
    {
        return Vector3D(x + f, y + f, z + f);
    }
    Vector3D Vector3D::operator-(float f) const
    {
        return Vector3D(x - f, y - f, z - f);
    }
    Vector3D Vector3D::operator/(float f) const
    {
        return Vector3D(x / f, y / f, z / f);
    }
    void Vector3D::operator*=(float f)
    {
        *this = *this * f;
    }
    void Vector3D::operator+=(float f)
    {
        *this = *this + f;
    }
    void Vector3D::operator-=(float f)
    {
        *this = *this - f;
    }
    void Vector3D::operator/=(float f)
    {
        *this = *this / f;
    }
}