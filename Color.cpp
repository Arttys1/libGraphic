#include "Color.h"

namespace libGraphic
{
	Color::Color(unsigned char red, unsigned char green, unsigned char blue) : Color(red / 255.f, green / 255.f, blue / 255.f)
	{
	}
	Color::Color(float red, float green, float blue) : r(red), g(green), b(blue)
	{
	}
	float Color::getRed() const
	{
		return r;
	}
	float Color::getGreen() const
	{
		return g;
	}
	float Color::getBlue() const
	{
		return b;
	}
	void Color::setRed(float r)
	{
		this->r = r;
	}
	void Color::setGreen(float g)
	{
		this->g = g;
	}
	void Color::setBlue(float b)
	{
		this->b = b;
	}
	glm::vec3 Color::toGlmVec() const
	{
		return glm::vec3(r, g, b);
	}
	
}
