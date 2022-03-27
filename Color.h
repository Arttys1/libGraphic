#pragma once
#ifndef H_COLOR
#define H_COLOR
#include "glm/vec3.hpp"

#include "Vector3D.h"

namespace libGraphic
{
	class Color
	{
	private:
		Vector3D rgb;

	public:
		Color(float red, float green, float blue);
		Color(Vector3D rgb);

		float getRed() const;
		float getGreen() const;
		float getBlue() const;
		void setRed(float r);
		void setGreen(float g);
		void setBlue(float b);

		glm::vec3 toGlmVec() const;

		static Color WHITE() { return Color(1.0f, 1.0f, 1.0f); }
		static Color BLACK() { return Color(0.f, 0.f, 0.f); }
		static Color RED() { return Color(1.f, 0.f, 0.f); }
		static Color GREEN() { return Color(0.f, 1.f, 0.f); }
		static Color BLUE() { return Color(0.f, 0.f, 1.f); }
		static Color YELLOW() { return Color(1.f, 1.f, 0.f); }
		static Color CYAN() { return Color(0.f, 1.f, 1.f); }
		static Color MAGENTA() { return Color(1.f, 0.f, 1.f); }

		Color operator*(const Color&) const;
		Color operator+(const Color&) const;
		Color operator-(const Color&) const;
		Color operator/(const Color&) const;
		void operator*=(const Color&);
		void operator+=(const Color&);
		void operator-=(const Color&);
		void operator/=(const Color&);
		Color operator*(float) const;
		Color operator+(float) const;
		Color operator-(float) const;
		Color operator/(float) const;
		void operator*=(float);
		void operator+=(float);
		void operator-=(float);
		void operator/=(float);
	};
}

#endif // !H_COLOR