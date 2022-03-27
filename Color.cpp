#include "Color.h"

namespace libGraphic
{
	Color::Color(float red, float green, float blue) : rgb(red, green, blue)
	{
	}
	Color::Color(Vector3D rgb)
	{
		this->rgb = rgb;
	}
	float Color::getRed() const
	{
		return rgb.getX();
	}
	float Color::getGreen() const
	{
		return rgb.getY();
	}
	float Color::getBlue() const
	{
		return rgb.getZ();
	}
	void Color::setRed(float r)
	{
		rgb.setX(r);
	}
	void Color::setGreen(float g)
	{
		rgb.setX(g);
	}
	void Color::setBlue(float b)
	{
		rgb.setX(b);
	}
	glm::vec3 Color::toGlmVec() const
	{
		return rgb.toGlmVec();
	}
	
	Color Color::operator*(const Color& c) const
	{
		return Color(rgb * c.rgb);
	}

	Color Color::operator+(const Color& c) const
	{
		return Color(rgb + c.rgb);
	}

	Color Color::operator-(const Color& c) const
	{
		return Color(rgb - c.rgb);
	}

	Color Color::operator/(const Color& c) const
	{
		return Color(rgb / c.rgb);
	}

	void Color::operator*=(const Color& c)
	{
		rgb *= c.rgb;
	}

	void Color::operator+=(const Color& c)
	{
		rgb += c.rgb;
	}

	void Color::operator-=(const Color& c)
	{
		rgb -= c.rgb;
	}

	void Color::operator/=(const Color& c)
	{
		rgb /= c.rgb;
	}

	Color Color::operator*(float f) const
	{
		return Color(rgb * f);
	}

	Color Color::operator+(float f) const
	{
		return Color(rgb + f);
	}

	Color Color::operator-(float f) const
	{
		return Color(rgb - f);
	}

	Color Color::operator/(float f) const
	{
		return Color(rgb / f);
	}

	void Color::operator*=(float f)
	{
		rgb *= f;
	}

	void Color::operator+=(float f)
	{
		rgb += f;
	}

	void Color::operator-=(float f)
	{
		rgb -= f;
	}

	void Color::operator/=(float f)
	{
		rgb /= f;
	}

}
